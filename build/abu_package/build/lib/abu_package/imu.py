import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from rclpy import qos
import math

class ImuPublisher(Node):
    def __init__(self):
        super().__init__('imu_publisher')
        self.imu = self.create_subscription(Imu, "/accel/sample", self.sub_accel, qos_profile=qos.qos_profile_sensor_data)
        self.imu
        self.imu2 = self.create_subscription(Imu, "/gyro/sample", self.sub_gyro, qos_profile=qos.qos_profile_sensor_data)
        self.imu2
        self.publisher_ = self.create_publisher(Imu, 'imu_data', 10)
        self.timer_ = self.create_timer(0.01, self.publish_imu_data)


        self.ax = 0
        self.ay = 0
        self.az = 0
        self.gx = 0
        self.gy = 0
        self.gz = 0
        self.roll = 10
        self.pitch = 10
        self.yaw = 10

    def sub_accel(self, msg):
        self.ax = msg.linear_acceleration.x
        self.ay = msg.linear_acceleration.y
        self.az = msg.linear_acceleration.z
        
    def sub_gyro(self, msg):
        self.gx = msg.angular_velocity.x
        self.gy = msg.angular_velocity.y
        self.gz = msg.angular_velocity.z

    def publish_imu_data(self):
        imu_msg = Imu()
        # Fill in the Imu message with example data
        imu_msg.header.stamp = self.get_clock().now().to_msg()
        imu_msg.header.frame_id = 'base_link'
        imu_msg.linear_acceleration.x = float(self.gx)
        imu_msg.linear_acceleration.y = float(self.gy)
        imu_msg.linear_acceleration.z = float(self.gz)
        imu_msg.angular_velocity.x = float(self.ax)
        imu_msg.angular_velocity.y = float(self.ay)
        imu_msg.angular_velocity.z = float(self.az)
        self.calculate_orientation(self.ax, self.ay, self.az, self.gx, self.gy, self.gz)
        imu_msg.orientation.x = float(self.roll)
        imu_msg.orientation.y = float(self.pitch)
        imu_msg.orientation.z = float(self.yaw)

        self.publisher_.publish(imu_msg)

    def calculate_orientation(self, accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z):
        dt = 0.01  # Time interval between sensor updates
        alpha = 0.98  # Complementary filter constant
        # Convert accelerometer measurements to roll and pitch angles
        roll_acc = math.atan2(accel_y, accel_z) * (180.0 / math.pi)
        pitch_acc = math.atan2(-accel_x, math.sqrt(accel_y**2 + accel_z**2)) * (180.0 / math.pi)
        sroll = self.roll
        spitch = self.pitch
        syaw = self.yaw
        # Integrate the gyro measurements for change in orientation
        sroll += gyro_x * dt
        spitch += gyro_y * dt
        syaw += gyro_z * dt

        # Apply the complementary filter
        sroll = alpha * self.roll + (1 - alpha) * roll_acc
        spitch = alpha * self.pitch + (1 - alpha) * pitch_acc

        self.roll = sroll
        self.pitch = spitch
        self.yaw = syaw

def main(args=None):
    rclpy.init(args=args)
    imu_publisher = ImuPublisher()
    rclpy.spin(imu_publisher)
    imu_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
