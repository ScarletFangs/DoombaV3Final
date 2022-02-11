#include "vex.h"
#include "robot-config.h"
using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller controller1(primary);

//Driving motors
motor left1(PORT1, ratio18_1, false);
motor left2(PORT2, ratio18_1, false); //front

motor right1(PORT10, ratio18_1, true);
motor right2(PORT7, ratio18_1, true); //front

//Motor Groups
motor_group leftWheels(left1, left2);
motor_group rightWheels(right1, right2);

//4 Bar motor
motor liftL1(PORT3, ratio36_1, true);
motor liftL2(PORT5, ratio36_1, true);
motor liftR1(PORT8, ratio36_1, false);
motor liftR2(PORT6, ratio36_1, false);

motor_group lift(liftL1, liftL2, liftR1, liftR2);

//Pneumatic
digital_out latchDown = digital_out(Brain.ThreeWirePort.A);

//GPS
gps DrivetrainGPS = gps(PORT4, 0.00, 0.00, mm, -180); //port, x, y, units, angle
smartdrive Drivetrain = smartdrive(leftWheels, rightWheels, DrivetrainGPS, 319.19, 320, 40, mm, 1);
long map(long x, long in_min, long in_max, long out_min, long out_max)
 {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void vexcodeInit(void) {
  Brain.setTimer(0, msec);
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain GPS
  wait(200, msec);
  DrivetrainGPS.calibrate();
  Brain.Screen.print("Calibrating GPS for Drivetrain");
  // wait for the GPS calibration process to finish
  while (DrivetrainGPS.isCalibrating()) {
    wait(25, msec);
  }

  //Set Drivetrain Velocity
  Drivetrain.setHeading(DrivetrainGPS.heading(), degrees);

  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}