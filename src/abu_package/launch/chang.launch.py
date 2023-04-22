from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
	ld = LaunchDescription()

	node_microros = Node(package="micro_ros_agent", executable="micro_ros_agent", output='screen', arguments=['serial', '--dev', '/dev/ttyUSB0'])
	node_joy = Node(package="joy", executable="joy_node")
	node_drive = Node(package="abu_package", executable="drive_node")
#	node_shoot = Node(package="abu_package", executable="shoot_node")
#	node_feed = Node(package="abu_package", executable="feed_node")


	ld.add_action(node_drive)
	ld.add_action(node_joy)
#	ld.add_action(node_shoot)
#	ld.add_action(node_feed)
	ld.add_action(node_microros)

	return ld

