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
#include "routineRampSide.h"
#include "autonSkills.h"

using namespace vex;
competition Competition;

void userControl(){
  while(1){
    arcadeDrive();
    //tankDrive();
    liftControl();
    liftToggle();
  }
}
void Autonomous(){
  //uncomment the routine we want to execute
  aimatCorner();
  //rampSide();
  //autonProgram();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Competition.drivercontrol(userControl);
  Competition.autonomous(Autonomous);
  
}
