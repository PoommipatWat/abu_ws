// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wiimote_msgs:msg/State.idl
// generated code does not contain a copyright notice

#ifndef WIIMOTE_MSGS__MSG__DETAIL__STATE__STRUCT_H_
#define WIIMOTE_MSGS__MSG__DETAIL__STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'INVALID'.
enum
{
  wiimote_msgs__msg__State__INVALID = -1
};

/// Constant 'INVALID_FLOAT'.
static const float wiimote_msgs__msg__State__INVALID_FLOAT = -1.0f;

/// Constant 'MSG_BTN_1'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_1 = 0
};

/// Constant 'MSG_BTN_2'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_2 = 1
};

/// Constant 'MSG_BTN_A'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_A = 2
};

/// Constant 'MSG_BTN_B'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_B = 3
};

/// Constant 'MSG_BTN_PLUS'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_PLUS = 4
};

/// Constant 'MSG_BTN_MINUS'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_MINUS = 5
};

/// Constant 'MSG_BTN_LEFT'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_LEFT = 6
};

/// Constant 'MSG_BTN_RIGHT'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_RIGHT = 7
};

/// Constant 'MSG_BTN_UP'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_UP = 8
};

/// Constant 'MSG_BTN_DOWN'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_DOWN = 9
};

/// Constant 'MSG_BTN_HOME'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_HOME = 10
};

/// Constant 'MSG_BTN_Z'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_Z = 0
};

/// Constant 'MSG_BTN_C'.
enum
{
  wiimote_msgs__msg__State__MSG_BTN_C = 1
};

/// Constant 'MSG_CLASSIC_BTN_X'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_X = 0
};

/// Constant 'MSG_CLASSIC_BTN_Y'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_Y = 1
};

/// Constant 'MSG_CLASSIC_BTN_A'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_A = 2
};

/// Constant 'MSG_CLASSIC_BTN_B'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_B = 3
};

/// Constant 'MSG_CLASSIC_BTN_PLUS'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_PLUS = 4
};

/// Constant 'MSG_CLASSIC_BTN_MINUS'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_MINUS = 5
};

/// Constant 'MSG_CLASSIC_BTN_LEFT'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_LEFT = 6
};

/// Constant 'MSG_CLASSIC_BTN_RIGHT'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_RIGHT = 7
};

/// Constant 'MSG_CLASSIC_BTN_UP'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_UP = 8
};

/// Constant 'MSG_CLASSIC_BTN_DOWN'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_DOWN = 9
};

/// Constant 'MSG_CLASSIC_BTN_HOME'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_HOME = 10
};

/// Constant 'MSG_CLASSIC_BTN_L'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_L = 11
};

/// Constant 'MSG_CLASSIC_BTN_R'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_R = 12
};

/// Constant 'MSG_CLASSIC_BTN_ZL'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_ZL = 13
};

/// Constant 'MSG_CLASSIC_BTN_ZR'.
enum
{
  wiimote_msgs__msg__State__MSG_CLASSIC_BTN_ZR = 14
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'angular_velocity_zeroed'
// Member 'angular_velocity_raw'
// Member 'linear_acceleration_zeroed'
// Member 'linear_acceleration_raw'
// Member 'nunchuk_acceleration_zeroed'
// Member 'nunchuk_acceleration_raw'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'ir_tracking'
#include "wiimote_msgs/msg/detail/ir_source_info__struct.h"
// Member 'zeroing_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in msg/State in the package wiimote_msgs.
typedef struct wiimote_msgs__msg__State
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Vector3 angular_velocity_zeroed;
  geometry_msgs__msg__Vector3 angular_velocity_raw;
  double angular_velocity_covariance[9];
  geometry_msgs__msg__Vector3 linear_acceleration_zeroed;
  geometry_msgs__msg__Vector3 linear_acceleration_raw;
  double linear_acceleration_covariance[9];
  geometry_msgs__msg__Vector3 nunchuk_acceleration_zeroed;
  geometry_msgs__msg__Vector3 nunchuk_acceleration_raw;
  float nunchuk_joystick_zeroed[2];
  float nunchuk_joystick_raw[2];
  bool buttons[11];
  bool nunchuk_buttons[2];
  bool leds[4];
  bool rumble;
  wiimote_msgs__msg__IrSourceInfo__Sequence ir_tracking;
  float raw_battery;
  float percent_battery;
  builtin_interfaces__msg__Time zeroing_time;
  uint64_t errors;
} wiimote_msgs__msg__State;

// Struct for a sequence of wiimote_msgs__msg__State.
typedef struct wiimote_msgs__msg__State__Sequence
{
  wiimote_msgs__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wiimote_msgs__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WIIMOTE_MSGS__MSG__DETAIL__STATE__STRUCT_H_
