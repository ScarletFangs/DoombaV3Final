#ifndef ROBOT_CONFIG
#define ROBOT_CONFIG
using namespace vex;

extern brain Brain;

//Controller
extern controller controller1;

//Driving motor
extern motor left1;
extern motor left2;

extern motor right1;
extern motor right2;

//Driving Motor Groups
extern motor_group leftWheels;
extern motor_group rightWheels;

//4 Bar motor
extern motor liftL1;
extern motor liftL2;
extern motor liftR1;
extern motor liftR2;

//Bar Motor Group
extern motor_group lift;

//Pneumatic 
extern digital_out clampPart;
extern digital_out latchDown;

void vexcodeInit(void);

#endif