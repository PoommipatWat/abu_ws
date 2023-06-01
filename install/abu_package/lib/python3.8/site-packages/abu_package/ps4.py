import rclpy

from rclpy.node import Node

from sensor_msgs.msg import Joy

from std_msgs.msg import String

from std_msgs.msg import Float64

from geometry_msgs.msg import Twist

from sensor_msgs.msg import Imu

from sensor_msgs.msg import Image

from rclpy import qos

import math
import cv2
import numpy as np
from cv_bridge import CvBridge
import datetime
import time

from simple_pid import PID

class Ps4(Node):
	def __init__(self):
		super().__init__("xbox_control_node")
		self.subscription = self.create_subscription(
			Image,
			'/color/image_raw',  # Adjust the topic name as per your setup
			self.image_callback,
			10
		)

		time.sleep(2)
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
		self.all = ["X","O","LLLL","S","T","LLL","L1","R1","L2","R2","L","R","PS","LS","RS"]
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


		self.param_pwm_motor1 = 110.0	# ค่าสำหรับห่วงไกล
		self.param_pwm_motor2 = 90.0	# ค่าสำหรับห่วงใกล้
		self.param_pwm_motor3 = 140.0
		self.param_pwm_motor4 = 170.0
		self.param_pwm_motor5 = 200.0
		self.param_pwm_motor6 = 230.0								
		self.param_distance = 10

		for a in self.all:
			self.button[a] = 0
		for a in self.all2:
			self.axes[a] = 0
		self.axes["AX"] = 0
		self.axes["AY"] = 0
		
		self.deg = 0.0
		self.keep_deg = 0
		self.kp = 0.1
		self.ki = 0.0
		self.kd = 0.0
		self.setpoint = 0.0
		self.pid = 0.0
		self.once_pwm = True
		self.width_frame, self.height_frame = (1024, 600)
		self.debugState = False
		self.cheatState = 1
		self.window_state = 'fullscreen'
		self.img = None

		self.start_time = datetime.datetime.now()
		self.target_delta = datetime.timedelta(minutes=3, seconds=10)

	def image_callback(self, msg):
		bridge = CvBridge()
		cv_image = bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
		self.img = cv_image
	
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
		self.button["LS"] = msg_in.buttons[-1]
		self.button["RS"] = msg_in.buttons[-2]
		if(self.button["LS"] == 1) and (self.button["RS"] == 1):
			self.start_time = datetime.datetime.now()
			self.target_delta = datetime.timedelta(minutes=3, seconds=10)
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
		self.deg = round(msg_in.orientation.y,2)*100.0
		if(self.once_pwm):
			self.pid = PID(self.kp, self.ki, self.kd, setpoint=self.deg)
			self.once_pwm = False
			self.setpoint = self.deg

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

		#if turn != 0:
		#	self.pid = PID(self.kp, self.ki, self.kd, setpoint=self.deg)
		# if x != 0 or y != 0:
		# 	if self.deg-self.setpoint >= 1:
		# 		turn = 0.5
		# if turn == 0:
		# 	if(self.deg-self.setpoint >= 1):
		# 		turn = 0.5
		# 	elif(self.deg-self.setpoint <= -1):
		# 		turn = -0.5
		# 	else:
		# 		turn = 0.0
		#control = self.pid(self.deg)
		#if(turn == 0) and (abs(control) > 0.2):
		#	turn = control*-1
		#self.get_logger().info(str(control))
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
		if(self.state > 5):
			self.state = 0
		if(self.state < 0):
			self.state = 1
		if(self.state == 0):
			self.pwm = self.param_pwm_motor2 - self.assis_shoot
		elif(self.state == 1):
			self.pwm = self.param_pwm_motor1 - self.assis_shoot
		elif(self.state == 2):
			self.pwm = self.param_pwm_motor3 - self.assis_shoot
		elif(self.state == 3):
			self.pwm = self.param_pwm_motor4 - self.assis_shoot
		elif(self.state == 4):
			self.pwm = self.param_pwm_motor5 - self.assis_shoot	
		elif(self.state == 5):
			self.pwm = self.param_pwm_motor6 - self.assis_shoot

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

		tempMsg = [
					msg.linear.x,
					msg.linear.y,
					msg.linear.z,
					msg.angular.x,
					msg.angular.y,
					msg.angular.z,
				]
		for key_press_axes in self.axes:
			if self.axes[key_press_axes] != 0:
				if self.cheatState == 0 and self.axes["AY"] == 1:
					self.cheatState = 1
				elif self.cheatState == 1 and self.axes["AY"] == -1:
					self.cheatState = 2
				elif self.cheatState == 2 and self.axes["AX"] == 1:
					self.cheatState = 3
				elif self.cheatState == 3 and self.axes["AX"] == -1:
					self.cheatState = 4
				elif self.axes["LT"] != 0:
					self.cheatState = self.cheatState
				elif self.axes["RT"] != 0:
					self.cheatState = self.cheatState
				else:
					self.cheatState = 0
		for key_press_button in self.button:
			if self.button[key_press_button] != 0:
				if self.cheatState == 4 and self.button["X"] == 1:
					self.cheatState = 5
				elif self.cheatState == 5:
					if self.debugState:
						self.debugState = False
					else:
						self.debugState = True
					self.cheatState = 0
				else:
					self.cheatState = 0

		self.gui(tempMsg)

		# //------------------------------------------------------------------------------------------------//
		self.sent_drive.publish(msg)

	def gui(self, msg_temp):
		block = [
			[0, int(self.height_frame - 25), 50, 25],
			[0, int(self.height_frame - 50), 50, 25],
			[0, int(self.height_frame - 75), 50, 25],
			[0, int(self.height_frame - 100), 50, 25],
			[0, int(self.height_frame - 125), 50, 25],
			[0, int(self.height_frame - 150), 50, 25],
		]

		text_msg_temp = [
			"msg.linear.x",
			"msg.linear.y",
			"msg.linear.z",
			"msg.angular.x",
			"msg.angular.y",
			"msg.angular.z",
		]

		circle_c = (91, 77, 55)
		if self.img is None:
			frame = np.full((1024, 600, 3), 255, dtype=np.uint8)
		else:
			frame = self.img

		frame = cv2.resize(frame, (self.width_frame, self.height_frame))
		frame = cv2.flip(frame, 1)

		cv2.line(
			frame,
			(int(self.width_frame / 2), 0),
			(int(self.width_frame / 2), self.height_frame),
			(0, 0, 0),
			3,
		)
		cv2.line(
			frame,
			(0, int(self.height_frame / 2)),
			(self.width_frame, int(self.height_frame / 2)),
			(0, 0, 0),
			3,
		)
		self.draw_gauge(
			frame=frame,
			x_cord=self.width_frame * 0.8,
			y_cord=self.height_frame * 0.8,
			thickness=40,
			radius=120,
			circle_colour=circle_c,
			value_pwm=self.pwm,
		)
		self.draw_mode(frame=frame, block=block, mode=self.state)

		if self.debugState:
			cv2.rectangle(
				frame, (0, 0), (self.width_frame, self.height_frame), (0, 0, 0), -1
			)
			for i, value in enumerate(msg_temp):
				text_msg_size, _ = cv2.getTextSize(
					f"{text_msg_temp[i]}: {value}", cv2.FONT_HERSHEY_SIMPLEX, 1.5, 3
				)
				cv2.putText(
					frame,
					f"{text_msg_temp[i]}: {value}",
					(
						int((self.width_frame / 2) - (text_msg_size[0] / 2)),
						int(i * 80 + 50),
					),
					cv2.FONT_HERSHEY_SIMPLEX,
					1.5,
					(0, 255, 0),
					3,
				)		

		self.toggle_fullscreen()

		cv2.imshow("Webcam", frame)
		if cv2.waitKey(1) & 0xFF == ord("q"):
			# closing all open windows
			cv2.destroyAllWindows()
			exit()

	def toggle_fullscreen(self):
		cv2.namedWindow("Webcam", cv2.WND_PROP_FULLSCREEN)
		if self.window_state == 'normal':
			cv2.setWindowProperty("Webcam", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_NORMAL)
		elif self.window_state == 'fullscreen':
			cv2.setWindowProperty("Webcam", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
		cv2.setMouseCallback("Webcam", self.mouse_callback)

	def mouse_callback(self, event, x, y, flags, param):
		if event == cv2.EVENT_LBUTTONUP:
			if(self.window_state) == 'normal':
				self.window_state = 'fullscreen'
			else:
				self.window_state = 'normal'


	def draw_gauge( self, frame, x_cord, y_cord, thickness, radius, circle_colour, value_pwm=0 ):
		value_pwm = min(value_pwm, 255)

		fill_angle = int(value_pwm * 280 / 255)
		per = value_pwm
		if per > 255:
			per = 255
		ac = (int(0), int(255 - per * 100 / 255), int(per * 255 / 255))

		pertext = str(value_pwm)
		text_size, _ = cv2.getTextSize(pertext, cv2.FONT_HERSHEY_SIMPLEX, 1.5, 3)
		text_width = text_size[0]
		text_height = text_size[1]
		text_x = int(x_cord) - text_width // 2
		text_y = int(y_cord) + text_height // 2
		cv2.rectangle(
			frame,
			(int(text_x), int(text_y * 1.02)),
			(text_x + text_width, int((text_y - text_height) * 0.98)),
			(255, 255, 255),
			-1,
		)
		cv2.rectangle(
			frame,
			(text_x, int(text_y * 1.02)),
			(text_x + text_width, int((text_y - text_height) * 0.98)),
			(0, 0, 0),
			2,
		)
		cv2.putText(
			frame,
			pertext,
			(text_x, text_y),
			cv2.FONT_HERSHEY_SIMPLEX,
			1.5,
			ac,
			3,
			cv2.LINE_AA,
		)

		for i in range(0, thickness):
			start_angle = -225
			end_angle = start_angle + 270
			cv2.ellipse(
				frame,
				(int(x_cord), int(y_cord)),
				(radius - i, radius - i),
				0,
				start_angle,
				end_angle,
				circle_colour,
				thickness=1,
			)
			if value_pwm > 0:
				cv2.ellipse(
					frame,
					(int(x_cord), int(y_cord)),
					(radius - i, radius - i),
					0,
					start_angle,
					start_angle + fill_angle - 8,
					ac,
					thickness=1,
				)

	def draw_mode(self, frame, block, mode):
		hours = 0
		minutes = 0
		seconds = 0
		text_block = ["S1", "S2", "S3","S4","S5","S6"]
		# current_time = datetime.datetime.now().strftime("%H:%M:%S")
		current_time = datetime.datetime.now()
		elapsed_time = current_time - self.start_time
		modee = 'normal'
		if elapsed_time >= self.target_delta:
			current_time = "TimeUp!!!"
			modee = 'timeup'
		else:
			elapsed_time = elapsed_time.seconds  - 10
			if(elapsed_time <= 0):
				elapsed_time *= -1
				hours = elapsed_time // 3600
				minutes = (elapsed_time // 60) % 60
				seconds = elapsed_time % 60
				modee = 'start'
				seconds = elapsed_time % 60
				current_time = f"Start in {seconds}"
			else:
				hours = elapsed_time // 3600
				minutes = (elapsed_time // 60) % 60
				seconds = elapsed_time % 60
				current_time = f"{hours} : {minutes} : {seconds}"

		text_size_time, _ = cv2.getTextSize(
			current_time, cv2.FONT_HERSHEY_SIMPLEX, 1.5, 3
		)
		for index, arr in enumerate(block):
			text = f"{text_block[index]}"
			x, y, width, height = arr
			if index == mode:
				cv2.rectangle(
					frame, (x, y), (x + width, y + height), (190, 245, 208), -1
				)
			else:
				cv2.rectangle(
					frame, (x, y), (x + width, y + height), (253, 206, 223), -1
				)
			cv2.rectangle(frame, (x, y), (x + width, y + height), (0, 0, 0), 2)

			text_size, _ = cv2.getTextSize(text, cv2.FONT_HERSHEY_SIMPLEX, 1.5, 3)
			text_x = x + int((width - text_size[0]) / 2)
			text_y = y + int((height + text_size[1]) / 2)
			cv2.putText(
				frame,
				text,
				(text_x, text_y),
				cv2.FONT_HERSHEY_SIMPLEX,
				1.5,
				(109, 55, 25),
				3,
			)
		cv2.putText(
			frame,
			current_time,
			(int((self.width_frame - text_size_time[0]) / 2), 50),
			cv2.FONT_HERSHEY_SIMPLEX,
			1.5,
			self.text_color(hours, minutes, seconds, modee),
			3,
			cv2.LINE_AA,
		)

	def text_color(self, hours, minutes, seconds, mode):
		if mode == 'timeup' or mode == 'start':
			return (0,0,0)
		elif hours == 0 and minutes >= 2 and seconds >= 30:
			return (99,102,255)
		elif hours == 0 and minutes >= 1 and seconds >= 30:
			return (80, 135, 250)
		elif hours == 0 and minutes >= 2 and seconds >= 0:
			return (80, 135, 250)
		else:
			return (0,250,0)


def main():
	rclpy.init()

	sub = Ps4()
	rclpy.spin(sub)

	rclpy.shutdown()

if __name__=="__main__":
	main()
