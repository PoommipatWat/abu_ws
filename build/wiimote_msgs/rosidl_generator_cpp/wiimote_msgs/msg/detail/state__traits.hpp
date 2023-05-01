// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wiimote_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef WIIMOTE_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_
#define WIIMOTE_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_

#include "wiimote_msgs/msg/detail/state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'angular_velocity_zeroed'
// Member 'angular_velocity_raw'
// Member 'linear_acceleration_zeroed'
// Member 'linear_acceleration_raw'
// Member 'nunchuk_acceleration_zeroed'
// Member 'nunchuk_acceleration_raw'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'zeroing_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wiimote_msgs::msg::State>()
{
  return "wiimote_msgs::msg::State";
}

template<>
inline const char * name<wiimote_msgs::msg::State>()
{
  return "wiimote_msgs/msg/State";
}

template<>
struct has_fixed_size<wiimote_msgs::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<wiimote_msgs::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<wiimote_msgs::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WIIMOTE_MSGS__MSG__DETAIL__STATE__TRAITS_HPP_
