// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wiimote_msgs:msg/IrSourceInfo.idl
// generated code does not contain a copyright notice

#ifndef WIIMOTE_MSGS__MSG__DETAIL__IR_SOURCE_INFO__TRAITS_HPP_
#define WIIMOTE_MSGS__MSG__DETAIL__IR_SOURCE_INFO__TRAITS_HPP_

#include "wiimote_msgs/msg/detail/ir_source_info__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wiimote_msgs::msg::IrSourceInfo>()
{
  return "wiimote_msgs::msg::IrSourceInfo";
}

template<>
inline const char * name<wiimote_msgs::msg::IrSourceInfo>()
{
  return "wiimote_msgs/msg/IrSourceInfo";
}

template<>
struct has_fixed_size<wiimote_msgs::msg::IrSourceInfo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<wiimote_msgs::msg::IrSourceInfo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<wiimote_msgs::msg::IrSourceInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WIIMOTE_MSGS__MSG__DETAIL__IR_SOURCE_INFO__TRAITS_HPP_
