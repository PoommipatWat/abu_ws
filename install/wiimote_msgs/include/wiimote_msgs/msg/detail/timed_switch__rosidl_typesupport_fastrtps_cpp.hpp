// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from wiimote_msgs:msg/TimedSwitch.idl
// generated code does not contain a copyright notice

#ifndef WIIMOTE_MSGS__MSG__DETAIL__TIMED_SWITCH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define WIIMOTE_MSGS__MSG__DETAIL__TIMED_SWITCH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "wiimote_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "wiimote_msgs/msg/detail/timed_switch__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace wiimote_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wiimote_msgs
cdr_serialize(
  const wiimote_msgs::msg::TimedSwitch & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wiimote_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wiimote_msgs::msg::TimedSwitch & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wiimote_msgs
get_serialized_size(
  const wiimote_msgs::msg::TimedSwitch & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wiimote_msgs
max_serialized_size_TimedSwitch(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wiimote_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wiimote_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wiimote_msgs, msg, TimedSwitch)();

#ifdef __cplusplus
}
#endif

#endif  // WIIMOTE_MSGS__MSG__DETAIL__TIMED_SWITCH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
