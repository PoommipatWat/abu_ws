import rclpy

from rclpy.node import Node

from sensor_msgs.msg import Joy

from std_msgs.msg import String

from geometry_msgs.msg import Twist

from rclpy import qos

import math

class Ps4(Node):
	def __init__(self):
		super().__init__("xbox_control_node")
		self.dat = self.create_subscription(Joy, "joy", self.sub_callback, qos_profile=qos.qos_profile_sensor_data)
		self.dat

		self.sent_drive = self.create_publisher(Twist, "control_drive_topic", qos_profile=qos.qos_profile_system_default)
		self.sent_drive_timer = self.create_timer(0.05, self.sent_drive_callback)

		self.button = {}
		self.all = ["X","O","T","S","L1","R1","L2","R2","Share","Option","AL","AR","PS"]
		for index, element in enumerate(self.all):
			self.button[element] = 0

		self.axes = {}
		self.all2 = ["LX", "LY", "RX", "LT", "RT", "RY", "AX", "AY"]
		for index, element in enumerate(self.all2):
			self.axes[element] = 0
		self.pwm = 0
		self.state = 0
		self.counter = 0
		self.state2 = 0
		self.counter2 = 0


	def sub_callback(self, msg_in):	#subscription topic
		self.new_dat = msg_in
		for index, element in enumerate(self.all):
			self.button[element] = msg_in.buttons[index]
#			print(f"{self.all[index]}  :  {self.button[element]}")

		for index, element in enumerate(self.all2):
			if msg_in.axes[index] <= 0.1 and msg_in.axes[index] >= -0.1:
				self.axes[element] = 0
			else:
				self.axes[element] = msg_in.axes[index]
#			print(f"{self.all2[index]} : {self.axes[element]}")

	def sent_drive_callback(self): #publisher drive topic
		limit = 0.4
		in_limit = -0.4
		msg = Twist()
		
		if ((self.axes["AX"] > 0) or (self.axes["AY"] > 0)):
			y = -1*(self.axes["AX"])
			x = -1*self.axes["AY"]
		elif ((self.axes["AX"] < 0) or (self.axes["AY"] < 0)):
			y = -1*(self.axes["AX"])
			x = -1*self.axes["AY"]
		else:
			y = -1*(self.axes["LX"])
			x = -1*self.axes["LY"]
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
		
				
		turn = self.axes["LT"]
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
			self.pwm = 105.0
		elif(self.state == 1):
			self.pwm = 165.0
		
		if(self.button["X"] == 1):
			msg.linear.z = self.pwm
#//------------------------------------------------------------------------------------------------//
		
		if(self.button["T"] == 1):
			msg.angular.z = 1.0
		if(self.button["L1"] == 1):
			msg.angular.z = 10.0
		if(self.button["Share"] == 1):
			msg.angular.z = 20.0
		if(self.button["Option"] == 1):
			msg.angular.z = 30.0
		
		self.sent_drive.publish(msg)


def main():
	rclpy.init()

	sub = Ps4()
	rclpy.spin(sub)

	rclpy.shutdown()

if __name__=="__main__":
	main()
