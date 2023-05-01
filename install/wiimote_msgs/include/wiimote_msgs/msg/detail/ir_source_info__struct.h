// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wiimote_msgs:msg/IrSourceInfo.idl
// generated code does not contain a copyright notice

#ifndef WIIMOTE_MSGS__MSG__DETAIL__IR_SOURCE_INFO__STRUCT_H_
#define WIIMOTE_MSGS__MSG__DETAIL__IR_SOURCE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/IrSourceInfo in the package wiimote_msgs.
typedef struct wiimote_msgs__msg__IrSourceInfo
{
  double x;
  double y;
  int64_t ir_size;
} wiimote_msgs__msg__IrSourceInfo;

// Struct for a sequence of wiimote_msgs__msg__IrSourceInfo.
typedef struct wiimote_msgs__msg__IrSourceInfo__Sequence
{
  wiimote_msgs__msg__IrSourceInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wiimote_msgs__msg__IrSourceInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WIIMOTE_MSGS__MSG__DETAIL__IR_SOURCE_INFO__STRUCT_H_
