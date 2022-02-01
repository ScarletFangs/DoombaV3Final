/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Sirena K                                         */
/*    Created:      Thu Dec 30 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "driving-functions.h"
#include "autonomous-functions.h"
#include "routine.h"
//-----NEW-----
#include "customMenu.h"
#include "GPS.h"
//-------------

using namespace vex;
competition Competition;

// //Without Menu
// void userControl(){
//   while(1){
//     arcadeDrive();
//     //tankDrive();
//     liftControl();
//     liftToggle();
//   }
// }
// void Autonomous(){
//   aimatCorner();
// }


//---Menu---
int tempStatus = 0;
void menuSetup(){
  menuCONFIG();
  notificationHUD("Robot: OK");
}
void Autonomous(){
  if(getValues(AUTON_TYPE) == GOALSIDE){
    aimatCorner();
    printf("goal side auton");
  }else if(getValues(AUTON_TYPE) == RAMPSIDE){
    rampSide();
    printf("ramp side auton");
  }else if(getValues(AUTON_TYPE) == MIDDLEGOAL){
    printf("skills");
  }
  notificationHUD("Auton: Done");
}
void userControl(){
  Brain.Screen.clearScreen(green);
  while(1){
    if(getValues(AUTON_DRIVE) == ARCADE){
      arcadeDrive();
      liftToggle();
      liftControl();
    }else if(getValues(AUTON_DRIVE) == TANK){
      tankDrive();
      liftToggle();
      liftControl();
    }
  }
}
void pre_auton (void){
  menuCONFIG();
  notificationHUD("Robot: OK");
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  pre_auton();
  
  Competition.drivercontrol(userControl);
  Competition.autonomous(Autonomous);

  while(1){
    if(tempStatus != currStatus()){
      statusHUD();
      tempStatus = currStatus();
    }
  }
  
}
