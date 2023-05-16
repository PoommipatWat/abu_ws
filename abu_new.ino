#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>
#include <geometry_msgs/msg/twist.h>

#define LED_PIN 13
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){return false;}}
#define EXECUTE_EVERY_N_MS(MS, X)  do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis();} \
  if (uxr_millis() - init > MS) { X; init = uxr_millis();} \
} while (0)\


//-----------------------------------------------------------------------------------//

#define PWM1 1
#define PWM2 5
#define PWM3 22
#define PWM4 4

#define INA1 20
#define INA2 6
#define INA3 23
#define INA4 3
int ina1 = 0, ina2 = 0, ina3 = 0, ina4 = 0;

#define INB1 21
#define INB2 8
#define INB3 0
#define INB4 2
int inb1 = 0, inb2 = 0, inb3 = 0, inb4 = 0;

#define stepPin 26
#define limit_s 27

#define limit_s1 17 //top
#define limit_s2 16 //under

#define pick_ina 40
#define pick_inb 41
float pick = 0;
String pick_state = "up";
bool pick_on = false;

float keep_pwmm = 0;
float keep_pwm = 0;
int statein = 0;

bool once = false;

#define shoot_motor_under 14
#define shoot_motor_top 15

static uint32_t preTime;

// linear.x = ล้อซ้ายหน้า 
// linear.y = ล้อขวาหน้า
// angular.x = ล้อซ้ายหลัง
// angular.y = ล้อขวาหลัง

// linear.z = เครื่องยิง
// angular.z = เครื่องยก 

int lim_switch(){
  int st = digitalRead(limit_s);
  return st;
}  

int lim_switch1(){
  int st = digitalRead(limit_s1);
  return st;
}
int lim_switch2(){
  int st = digitalRead(limit_s2);
  return st;
}

void shoot_fun(float pwmm){
      if(pwmm > 0) keep_pwm = pwmm;
  
      if((pwmm > 0)  && (statein == 1)){
        statein = 2;
        once = true;
        keep_pwmm = pwmm;
        preTime = millis();
      }

      if(statein == 0){
        if(lim_switch() == true){
          digitalWrite(stepPin, HIGH);
        }
        else{
          statein = 1;          
          analogWrite(shoot_motor_under, 0);
          analogWrite(shoot_motor_top, 0);
          digitalWrite(stepPin, LOW);
          once = true;
        }
      }
      if (statein == 1){
        if(lim_switch() == true) digitalWrite(stepPin, HIGH);
        else digitalWrite(stepPin, LOW);
        if(once){
          analogWrite(shoot_motor_under, 0);
          analogWrite(shoot_motor_top, 0);
          once = false;
        }
      }
      if (statein == 2){
        if(millis() - preTime > 1500){
          statein  = 3;
          once = true;
        }
        else{
          if(once){
            analogWrite(shoot_motor_under, keep_pwmm);
            analogWrite(shoot_motor_top, keep_pwmm);
            once = false;       
          }
        }
      }
      if (statein == 3){
        if(lim_switch() == false){
          digitalWrite(stepPin, HIGH);
        }
        else{
          statein = 4;
          digitalWrite(stepPin, LOW);
          once = true;
          preTime = millis();
        }
      }
      if(statein == 4){
        if(millis() - preTime > 750){
          statein  = 0;
          analogWrite(shoot_motor_under, 0);
          analogWrite(shoot_motor_top, 0);
        }
      }
}

void drive_fun(float wheel1, float wheel2, float wheel3, float  wheel4){
    if(wheel1 > 0){
      ina1 = 1; inb1 = 0;
    }
    else if(wheel1 == 0){
      ina1 = 1; inb1 = 1;
    }
    else{
      ina1 = 0; inb1 = 1;      
    }
    if(wheel2 > 0){
      ina2 = 1; inb2 = 0;
    }
    else if(wheel2 == 0){
      ina2 = 1; inb2 = 1;      
    }
    else{
      ina2 = 0; inb2 = 1;      
    }
    if(wheel3 > 0){
      ina3 = 1; inb3 = 0;
    }
    else if(wheel3 == 0){
      ina3 = 1; inb3 = 1;
    }
    else{
      ina3 = 0; inb3 = 1;      
    }
    if(wheel4 > 0){
      ina4 = 1; inb4= 0;
    }
    else if(wheel4 == 0){
      ina4 = 1; inb4 = 1;
    }
    else{
      ina4 = 0; inb4 = 1;      
    }
    analogWrite(PWM1, abs(wheel1));
    analogWrite(PWM2, abs(wheel2));
    analogWrite(PWM3, abs(wheel3));
    analogWrite(PWM4, abs(wheel4));
    digitalWrite(INA1, ina1);
    digitalWrite(INB1, inb1);
    digitalWrite(INA2, ina2);
    digitalWrite(INB2, inb2);
    digitalWrite(INA3, ina3);
    digitalWrite(INB3, inb3);
    digitalWrite(INA4, ina4);
    digitalWrite(INB4, inb4);
}

void pick_fun(float msg){
    pick = msg;
    if((pick == 1) && (pick_on == false)){
      pick_on = true;
      analogWrite(shoot_motor_under, 0);
      analogWrite(shoot_motor_top, 0);
      digitalWrite(stepPin, LOW);
    }

    if((pick == 10) || (pick == 20)) pick_on = false;
        
    if(pick_on){
      if(pick_state == "up"){
        if(lim_switch1() == false){
          pick_state = "down";
          pick_on = false;
          statein = 0;
          once = true;
        }
        else{
          digitalWrite(pick_ina, HIGH);
          digitalWrite(pick_inb, LOW);
        }
      }
      else{
        if(lim_switch2() == false){
          pick_state = "up";
          pick_on = false;
          statein = 0;
          once = true;
        }
        else{
          digitalWrite(pick_ina, LOW);
          digitalWrite(pick_inb, HIGH);
        }
      }
    }
    else{
      if(pick == 10){
        if(lim_switch2() == true){
        digitalWrite(pick_ina, HIGH);
        digitalWrite(pick_inb, LOW);
        }
      }
      else if(pick == 20){
        digitalWrite(pick_ina, LOW);
        digitalWrite(pick_inb, HIGH);        
      }
      else{
        digitalWrite(pick_ina, HIGH);
        digitalWrite(pick_inb, HIGH);
      }    
    }
}


//-----------------------------------------------------------------------------------//


//basic
rclc_support_t support;
rcl_node_t node;
rcl_timer_t timer;
rcl_allocator_t allocator;

//publisher
rclc_executor_t executor_pub;
rcl_publisher_t publisher;
geometry_msgs__msg__Twist msg_pub;


//subscriber
rclc_executor_t executor_sub;
rcl_subscription_t subscriber;
geometry_msgs__msg__Twist msg_sub;

bool micro_ros_init_successful;

enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
  (void) last_call_time;
  if (timer != NULL) {
    rcl_publish(&publisher, &msg_pub, NULL);
    msg_pub.linear.y++;
  }
}

void subscription_callback(const void *msgin) {
  const geometry_msgs__msg__Twist * msg_sub = (const geometry_msgs__msg__Twist *)msgin;
    drive_fun(msg_sub->linear.x, msg_sub->linear.y, msg_sub->angular.x, msg_sub->angular.y);
    
    if(lim_switch2() == true) shoot_fun(msg_sub->linear.z);
    else{
      digitalWrite(shoot_motor_under, LOW);
      digitalWrite(shoot_motor_top, LOW);
      if(msg_sub->angular.z == 999) digitalWrite(stepPin, HIGH);
      else digitalWrite(stepPin, LOW);
    }
    
}

// Functions create_entities and destroy_entities can take several seconds.
// In order to reduce this rebuild the library with
// - RMW_UXRCE_ENTITY_CREATION_DESTROY_TIMEOUT=0
// - UCLIENT_MAX_SESSION_CONNECTION_ATTEMPTS=3

bool create_entities()
{
  allocator = rcl_get_default_allocator();

  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "int32_publisher_rclc", "", &support));

  // create publisher
  RCCHECK(rclc_publisher_init_best_effort(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "twist_topic"));

  // create timer,
  const unsigned int timer_timeout = 100;
  RCCHECK(rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(timer_timeout),
    timer_callback));

  // create subscriber
  RCCHECK(rclc_subscription_init_default(
    &subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "control_drive_topic"));

  // create executor publisher
  executor_pub = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor_pub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor_pub, &timer));

  // create executor subscriber
  executor_sub = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor_sub, &support.context, 1, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor_sub, &subscriber, &msg_sub, &subscription_callback, ON_NEW_DATA));


  return true;
}

void destroy_entities()
{
  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&publisher, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor_pub);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}

void renew(){
  digitalWrite(PWM1, LOW);
  digitalWrite(PWM2, LOW);
  digitalWrite(PWM3, LOW);
  digitalWrite(PWM4, LOW);
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, HIGH);
  digitalWrite(INA2, HIGH);
  digitalWrite(INB2, HIGH);
  digitalWrite(INA3, HIGH);
  digitalWrite(INB3, HIGH);
  digitalWrite(INA4, HIGH);
  digitalWrite(INB4, HIGH);

  digitalWrite(pick_ina, HIGH);
  digitalWrite(pick_inb, HIGH);

  digitalWrite(shoot_motor_under, LOW);
  digitalWrite(shoot_motor_top, LOW);
}

void setup() {
  set_microros_transports();
  pinMode(LED_PIN, OUTPUT);

  state = WAITING_AGENT;
  
  msg_pub.linear.x = 0.0;
  msg_pub.linear.y = 0.0;
  msg_pub.linear.z = 0.0;
  msg_pub.angular.x = 0.0;
  msg_pub.angular.y = 0.0;
  msg_pub.angular.z = 0.0;

  msg_sub.linear.x = 0.0;
  msg_sub.linear.y = 0.0;
  msg_sub.linear.z = 0.0;
  msg_sub.angular.x = 0.0;
  msg_sub.angular.y = 0.0;
  msg_sub.angular.z = 0.0;
}

void loop() {
  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
    case AGENT_AVAILABLE:
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroy_entities();
      };
      break;
    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
      if (state == AGENT_CONNECTED) {
        //rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(100));
        rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(100));
      }
      break;
    case AGENT_DISCONNECTED:
      destroy_entities();
      state = WAITING_AGENT;
      break;
    default:
      break;
  }

  if (state == AGENT_CONNECTED) {
    digitalWrite(LED_PIN, 1);
  } else {
    digitalWrite(LED_PIN, 0);
    renew();
  }
}
