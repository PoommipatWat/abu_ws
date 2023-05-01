// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from wiimote_msgs:msg/State.idl
// generated code does not contain a copyright notice
#include "wiimote_msgs/msg/detail/state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "wiimote_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "wiimote_msgs/msg/detail/state__struct.h"
#include "wiimote_msgs/msg/detail/state__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "builtin_interfaces/msg/detail/time__functions.h"  // zeroing_time
#include "geometry_msgs/msg/detail/vector3__functions.h"  // angular_velocity_raw, angular_velocity_zeroed, linear_acceleration_raw, linear_acceleration_zeroed, nunchuk_acceleration_raw, nunchuk_acceleration_zeroed
#include "std_msgs/msg/detail/header__functions.h"  // header
#include "wiimote_msgs/msg/detail/ir_source_info__functions.h"  // ir_tracking

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
size_t get_serialized_size_geometry_msgs__msg__Vector3(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
size_t max_serialized_size_geometry_msgs__msg__Vector3(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_wiimote_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();
size_t get_serialized_size_wiimote_msgs__msg__IrSourceInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_wiimote_msgs__msg__IrSourceInfo(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wiimote_msgs, msg, IrSourceInfo)();


using _State__ros_msg_type = wiimote_msgs__msg__State;

static bool _State__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _State__ros_msg_type * ros_message = static_cast<const _State__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: angular_velocity_zeroed
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->angular_velocity_zeroed, cdr))
    {
      return false;
    }
  }

  // Field name: angular_velocity_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->angular_velocity_raw, cdr))
    {
      return false;
    }
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: linear_acceleration_zeroed
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->linear_acceleration_zeroed, cdr))
    {
      return false;
    }
  }

  // Field name: linear_acceleration_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->linear_acceleration_raw, cdr))
    {
      return false;
    }
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: nunchuk_acceleration_zeroed
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->nunchuk_acceleration_zeroed, cdr))
    {
      return false;
    }
  }

  // Field name: nunchuk_acceleration_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->nunchuk_acceleration_raw, cdr))
    {
      return false;
    }
  }

  // Field name: nunchuk_joystick_zeroed
  {
    size_t size = 2;
    auto array_ptr = ros_message->nunchuk_joystick_zeroed;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: nunchuk_joystick_raw
  {
    size_t size = 2;
    auto array_ptr = ros_message->nunchuk_joystick_raw;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: buttons
  {
    size_t size = 11;
    auto array_ptr = ros_message->buttons;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: nunchuk_buttons
  {
    size_t size = 2;
    auto array_ptr = ros_message->nunchuk_buttons;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: leds
  {
    size_t size = 4;
    auto array_ptr = ros_message->leds;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: rumble
  {
    cdr << (ros_message->rumble ? true : false);
  }

  // Field name: ir_tracking
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, wiimote_msgs, msg, IrSourceInfo
      )()->data);
    size_t size = ros_message->ir_tracking.size;
    auto array_ptr = ros_message->ir_tracking.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: raw_battery
  {
    cdr << ros_message->raw_battery;
  }

  // Field name: percent_battery
  {
    cdr << ros_message->percent_battery;
  }

  // Field name: zeroing_time
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->zeroing_time, cdr))
    {
      return false;
    }
  }

  // Field name: errors
  {
    cdr << ros_message->errors;
  }

  return true;
}

static bool _State__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _State__ros_msg_type * ros_message = static_cast<_State__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: angular_velocity_zeroed
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->angular_velocity_zeroed))
    {
      return false;
    }
  }

  // Field name: angular_velocity_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->angular_velocity_raw))
    {
      return false;
    }
  }

  // Field name: angular_velocity_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: linear_acceleration_zeroed
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->linear_acceleration_zeroed))
    {
      return false;
    }
  }

  // Field name: linear_acceleration_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->linear_acceleration_raw))
    {
      return false;
    }
  }

  // Field name: linear_acceleration_covariance
  {
    size_t size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: nunchuk_acceleration_zeroed
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->nunchuk_acceleration_zeroed))
    {
      return false;
    }
  }

  // Field name: nunchuk_acceleration_raw
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->nunchuk_acceleration_raw))
    {
      return false;
    }
  }

  // Field name: nunchuk_joystick_zeroed
  {
    size_t size = 2;
    auto array_ptr = ros_message->nunchuk_joystick_zeroed;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: nunchuk_joystick_raw
  {
    size_t size = 2;
    auto array_ptr = ros_message->nunchuk_joystick_raw;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: buttons
  {
    size_t size = 11;
    auto array_ptr = ros_message->buttons;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: nunchuk_buttons
  {
    size_t size = 2;
    auto array_ptr = ros_message->nunchuk_buttons;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: leds
  {
    size_t size = 4;
    auto array_ptr = ros_message->leds;
    for (size_t i = 0; i < size; ++i) {
      uint8_t tmp;
      cdr >> tmp;
      array_ptr[i] = tmp ? true : false;
    }
  }

  // Field name: rumble
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->rumble = tmp ? true : false;
  }

  // Field name: ir_tracking
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, wiimote_msgs, msg, IrSourceInfo
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->ir_tracking.data) {
      wiimote_msgs__msg__IrSourceInfo__Sequence__fini(&ros_message->ir_tracking);
    }
    if (!wiimote_msgs__msg__IrSourceInfo__Sequence__init(&ros_message->ir_tracking, size)) {
      return "failed to create array for field 'ir_tracking'";
    }
    auto array_ptr = ros_message->ir_tracking.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: raw_battery
  {
    cdr >> ros_message->raw_battery;
  }

  // Field name: percent_battery
  {
    cdr >> ros_message->percent_battery;
  }

  // Field name: zeroing_time
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->zeroing_time))
    {
      return false;
    }
  }

  // Field name: errors
  {
    cdr >> ros_message->errors;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wiimote_msgs
size_t get_serialized_size_wiimote_msgs__msg__State(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _State__ros_msg_type * ros_message = static_cast<const _State__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name angular_velocity_zeroed

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->angular_velocity_zeroed), current_alignment);
  // field.name angular_velocity_raw

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->angular_velocity_raw), current_alignment);
  // field.name angular_velocity_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->angular_velocity_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name linear_acceleration_zeroed

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->linear_acceleration_zeroed), current_alignment);
  // field.name linear_acceleration_raw

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->linear_acceleration_raw), current_alignment);
  // field.name linear_acceleration_covariance
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->linear_acceleration_covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nunchuk_acceleration_zeroed

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->nunchuk_acceleration_zeroed), current_alignment);
  // field.name nunchuk_acceleration_raw

  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->nunchuk_acceleration_raw), current_alignment);
  // field.name nunchuk_joystick_zeroed
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->nunchuk_joystick_zeroed;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nunchuk_joystick_raw
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->nunchuk_joystick_raw;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name buttons
  {
    size_t array_size = 11;
    auto array_ptr = ros_message->buttons;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nunchuk_buttons
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->nunchuk_buttons;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leds
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->leds;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rumble
  {
    size_t item_size = sizeof(ros_message->rumble);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ir_tracking
  {
    size_t array_size = ros_message->ir_tracking.size;
    auto array_ptr = ros_message->ir_tracking.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_wiimote_msgs__msg__IrSourceInfo(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name raw_battery
  {
    size_t item_size = sizeof(ros_message->raw_battery);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name percent_battery
  {
    size_t item_size = sizeof(ros_message->percent_battery);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name zeroing_time

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->zeroing_time), current_alignment);
  // field.name errors
  {
    size_t item_size = sizeof(ros_message->errors);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _State__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_wiimote_msgs__msg__State(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wiimote_msgs
size_t max_serialized_size_wiimote_msgs__msg__State(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: angular_velocity_zeroed
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }
  // member: angular_velocity_raw
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }
  // member: angular_velocity_covariance
  {
    size_t array_size = 9;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: linear_acceleration_zeroed
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }
  // member: linear_acceleration_raw
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }
  // member: linear_acceleration_covariance
  {
    size_t array_size = 9;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: nunchuk_acceleration_zeroed
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }
  // member: nunchuk_acceleration_raw
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Vector3(
        full_bounded, current_alignment);
    }
  }
  // member: nunchuk_joystick_zeroed
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nunchuk_joystick_raw
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: buttons
  {
    size_t array_size = 11;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: nunchuk_buttons
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: leds
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rumble
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: ir_tracking
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_wiimote_msgs__msg__IrSourceInfo(
        full_bounded, current_alignment);
    }
  }
  // member: raw_battery
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: percent_battery
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: zeroing_time
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_builtin_interfaces__msg__Time(
        full_bounded, current_alignment);
    }
  }
  // member: errors
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _State__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_wiimote_msgs__msg__State(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_State = {
  "wiimote_msgs::msg",
  "State",
  _State__cdr_serialize,
  _State__cdr_deserialize,
  _State__get_serialized_size,
  _State__max_serialized_size
};

static rosidl_message_type_support_t _State__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_State,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wiimote_msgs, msg, State)() {
  return &_State__type_support;
}

#if defined(__cplusplus)
}
#endif
