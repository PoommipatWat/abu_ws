import rclpy

from rclpy.node import Node

from sensor_msgs.msg import Joy

from std_msgs.msg import String

from std_msgs.msg import Float64

from geometry_msgs.msg import Twist

from sensor_msgs.msg import Imu

from rclpy import qos

import math
import cv2
import numpy as np

from simple_pid import PID

class Ps4(Node):
	def __init__(self):
		super().__init__("xbox_control_node")
		self.dat = self.create_subscription(Joy, "joy", self.sub_callback, qos_profile=qos.qos_profile_sensor_data)
		self.dat

		self.cam = self.create_subscription(Float64, "distance_xy", self.sub_callback_cam, qos_profile=qos.qos_profile_sensor_data)
		self.cam

		self.imu = self.create_subscription(Imu, "/imu/data", self.sub_callback_imu, qos_profile=qos.qos_profile_sensor_data)
		self.imu

		self.sent_drive = self.create_publisher(Twist, "control_drive_topic", qos_profile=qos.qos_profile_system_default)
		self.sent_drive_timer = self.create_timer(0.05, self.sent_drive_callback)

		self.button = {}
		# self.all = ["X","O","LLLL","S","L1","R1","L2","R2","L","R","PS"]
		self.all = ["X","O","LLLL","S","T","LLL","L1","R1","L2","R2","L","R","PS"]
		for index, element in enumerate(self.all):
			self.button[element] = 0

		self.axes = {}
		self.all2 = ["LX", "LY", "LT", "RX", "RY", "RT"]
		# self.all2 = ["LX", "LY", "LT", "RX", "RY", "RT", "AX", "AY"]
		for index, element in enumerate(self.all2):
			self.axes[element] = 0
		self.pwm = 0
		self.state = 0
		self.counter = 0
		self.state2 = 0
		self.counter2 = 0


		self.distance = 0.0
		self.state_auto = 0

		self.assis_shoot = 0
		self.list_debount_r = []
		self.list_debount_l = []


		self.param_pwm_motor1 = 121.5	# ค่าสำหรับห่วงไกล
		self.param_pwm_motor2 = 91.5	# ค่าสำหรับห่วงใกล้
		self.param_distance = 10

		for a in self.all:
			self.button[a] = 0
		for a in self.all2:
			self.axes[a] = 0
		self.axes["AX"] = 0
		self.axes["AY"] = 0
		
		self.deg = 0
		self.keep_deg = 0

	def sub_callback(self, msg_in):	#subscription topic
		self.new_dat = msg_in
		self.button["X"] = msg_in.buttons[0]
		self.button["O"] = msg_in.buttons[1]
		self.button["T"] = msg_in.buttons[2]
		self.button["S"] = msg_in.buttons[3]
		self.button["L1"] = msg_in.buttons[4]
		self.button["R1"] = msg_in.buttons[5]
		self.button["L2"] = msg_in.buttons[6]
		self.button["R2"] = msg_in.buttons[7]
		#if(msg_in.axes[5] < 0):
		#	self.button["L2"] = 1
		#else:
		#	self.button["L2"] = 0
		#if(msg_in.axes[4] > 0):
		#	self.button["R2"] = 0
		#else:
		#	self.button["R2"] = 1
		self.button["L"] = msg_in.buttons[8]
		self.button["R"] = msg_in.buttons[9]
		self.button["PS"] = msg_in.buttons[10]
		for index, element in enumerate(self.all2):
			if msg_in.axes[index] <= 0.1 and msg_in.axes[index] >= -0.1:
				self.axes[element] = 0
			else:
				self.axes[element] = msg_in.axes[index]
		self.axes["AX"] = msg_in.axes[-2]
		self.axes["AY"] = msg_in.axes[-1]

	def sub_callback_cam(self, msg_in):
		self.distance = msg_in.data

	def sub_callback_imu(self, msg_in):
		rad = msg_in.orientation.y
		self.deg = ((346.35*(rad**2)) + (9.2361*rad) - 95.13) + 100

	def sent_drive_callback(self): #publisher drive topic
		limit = 0.1
		in_limit = -1 * limit
		msg = Twist()

		x = 0.0
		y = 0.0

		if(self.state_auto == 0):
			if ((self.axes["AX"] > 0) or (self.axes["AY"] > 0)):
				y = -1*(self.axes["AX"])
				x = -1*self.axes["AY"]
			elif ((self.axes["AX"] < 0) or (self.axes["AY"] < 0)):
				y = -1*(self.axes["AX"])
				x = -1*self.axes["AY"]
			else:
				y = -1*(self.axes["LX"])
				x = -1*self.axes["LY"]
				if(self.button["L1"] == 1):
					if((x > limit) and (y > limit)):
						x = 0.707
						y = 0.707
					elif((x < in_limit) and (y > limit)):
						x = -0.707
						y = 0.707
					elif((x < in_limit) and (y < in_limit)):
						x = -0.707
						y = -0.707
					elif ((x > limit) and (y < in_limit)):
						x = 0.707
						y = -0.707
					else:
						x = 0.0
						y = 0.0

		if((self.button["PS"] == 1) and (self.axes["AX"] == 0) and (self.axes["AY"] == 0) and (self.axes["LY"] == 0) and (self.axes["LX"] == 0)):
			self.state_auto = 1
		else:
			self.state_auto = 0
		
		if(self.state_auto == 1):
			if(self.distance > self.param_distance):
				x = 0.707
				y = 0.707
			elif(self.distance < (self.param_distance * -1)):
				x = -0.707
				y = 0.707
			else:
				self.state_auto = 0
				x = 0.0
				y = 0.0
				
		turn = self.axes["RX"]
		
		xs = x
		x = y
		y = -1*xs

		theta = math.atan2(y, x)
		power = math.hypot(x, y)
		sin = math.sin(theta - math.pi/4)
		cos = math.cos(theta - math.pi/4)
		Max = max(abs(sin), abs(cos))
		leftFront = power * cos/Max + turn
		rightFront = power * sin/Max - turn
		leftBack = power * sin/Max + turn
		rightBack = power * cos/Max - turn

		if ((power + abs(turn)) > 1):
			leftFront /= (power + abs(turn))
			rightFront /= (power + abs(turn))
			leftBack /= (power + abs(turn))
			rightBack /= (power + abs(turn))		

		msg.linear.x = float(round(leftFront*255))
		msg.linear.y = float(round(rightFront*255))
		msg.angular.x = float(round(leftBack*255))
		msg.angular.y = float(round(rightBack*255))


#//------------------------------------------------------------------------------------------------//
		if((self.button["S"] == 1) and (self.button["O"] == 1)):
			self.assis_shoot = 0
		elif(self.button["S"] == 1):
			self.assis_shoot += 0.5
		elif(self.button["O"] == 1):
			self.assis_shoot -= 0.5

#//------------------------------------------------------------------------------------------------//		
		if((self.button["R1"] == 1) and (self.counter == 0)):
			self.state += 1
			self.counter = 4
		if(self.counter > 0):
			self.counter -= 1
		if(self.state > 1):
			self.state = 0
		if(self.state < 0):
			self.state = 1
		if(self.state == 0):
			self.pwm = self.param_pwm_motor2 - self.assis_shoot
		elif(self.state == 1):
			self.pwm = self.param_pwm_motor1 - self.assis_shoot
			
		if(self.pwm > 255):
			self.pwm = 255.0
		elif(self.pwm < 0):
			self.pwm  = 0.0
		
		if(self.button["X"] == 1):
			msg.linear.z = self.pwm
#//------------------------------------------------------------------------------------------------//
		
		if(self.button["T"] == 1):
			msg.angular.z = 1.0
		elif(self.button["L"] == 1):
			msg.angular.z = 10.0
		elif(self.button["R"] == 1):
			msg.angular.z = 20.0
		elif(self.button["R2"] == 1):
			msg.angular.z = 30.0


		
		
		self.sent_drive.publish(msg)
		img = np.ones((1050, 2100, 3), dtype = np.uint8)
		img = 255* img
		# Using cv2.putText() method
		img = cv2.putText(img, str(self.pwm), (300,500), cv2.FONT_HERSHEY_SIMPLEX, 
						13, (255,0,0), 5, cv2.LINE_AA)

		# display the image using opencv
		# cv2.imshow('white image', img)
		# cv2.waitKey(1)
		cv2.namedWindow("image", cv2.WND_PROP_FULLSCREEN)
		cv2.setWindowProperty("image", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_NORMAL)
		key = cv2.waitKey(1)
		cv2.imshow("image", img)


def main():
	rclpy.init()

	sub = Ps4()
	rclpy.spin(sub)

	rclpy.shutdown()

if __name__=="__main__":
	main()
