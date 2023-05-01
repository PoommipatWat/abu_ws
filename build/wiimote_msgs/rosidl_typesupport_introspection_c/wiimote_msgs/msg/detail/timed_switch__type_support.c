// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wiimote_msgs:msg/TimedSwitch.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wiimote_msgs/msg/detail/timed_switch__rosidl_typesupport_introspection_c.h"
#include "wiimote_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wiimote_msgs/msg/detail/timed_switch__functions.h"
#include "wiimote_msgs/msg/detail/timed_switch__struct.h"


// Include directives for member types
// Member `pulse_pattern`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wiimote_msgs__msg__TimedSwitch__init(message_memory);
}

void TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_fini_function(void * message_memory)
{
  wiimote_msgs__msg__TimedSwitch__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_member_array[3] = {
  {
    "switch_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wiimote_msgs__msg__TimedSwitch, switch_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_cycles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wiimote_msgs__msg__TimedSwitch, num_cycles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pulse_pattern",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wiimote_msgs__msg__TimedSwitch, pulse_pattern),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_members = {
  "wiimote_msgs__msg",  // message namespace
  "TimedSwitch",  // message name
  3,  // number of fields
  sizeof(wiimote_msgs__msg__TimedSwitch),
  TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_member_array,  // message members
  TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_init_function,  // function to initialize message memory (memory has to be allocated)
  TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_type_support_handle = {
  0,
  &TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wiimote_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wiimote_msgs, msg, TimedSwitch)() {
  if (!TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_type_support_handle.typesupport_identifier) {
    TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &TimedSwitch__rosidl_typesupport_introspection_c__TimedSwitch_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
