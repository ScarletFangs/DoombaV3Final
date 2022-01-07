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

using namespace vex;
competition Competition;

//testing Git

void userControl(){
  while(1){
    arcadeDrive();
    liftControl();
    liftToggle();
  }
}
void Autonomous(){
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Competition.drivercontrol(userControl);
  Competition.autonomous(Autonomous);
  
}
