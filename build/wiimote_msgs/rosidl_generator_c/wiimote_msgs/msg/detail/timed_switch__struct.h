// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wiimote_msgs:msg/TimedSwitch.idl
// generated code does not contain a copyright notice

#ifndef WIIMOTE_MSGS__MSG__DETAIL__TIMED_SWITCH__STRUCT_H_
#define WIIMOTE_MSGS__MSG__DETAIL__TIMED_SWITCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ON'.
enum
{
  wiimote_msgs__msg__TimedSwitch__ON = 1
};

/// Constant 'OFF'.
enum
{
  wiimote_msgs__msg__TimedSwitch__OFF = 0
};

/// Constant 'NO_CHANGE'.
enum
{
  wiimote_msgs__msg__TimedSwitch__NO_CHANGE = -2
};

/// Constant 'REPEAT'.
enum
{
  wiimote_msgs__msg__TimedSwitch__REPEAT = -1
};

/// Constant 'FOREVER'.
enum
{
  wiimote_msgs__msg__TimedSwitch__FOREVER = -1
};

// Include directives for member types
// Member 'pulse_pattern'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/TimedSwitch in the package wiimote_msgs.
typedef struct wiimote_msgs__msg__TimedSwitch
{
  int8_t switch_mode;
  int32_t num_cycles;
  rosidl_runtime_c__float__Sequence pulse_pattern;
} wiimote_msgs__msg__TimedSwitch;

// Struct for a sequence of wiimote_msgs__msg__TimedSwitch.
typedef struct wiimote_msgs__msg__TimedSwitch__Sequence
{
  wiimote_msgs__msg__TimedSwitch * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wiimote_msgs__msg__TimedSwitch__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WIIMOTE_MSGS__MSG__DETAIL__TIMED_SWITCH__STRUCT_H_
