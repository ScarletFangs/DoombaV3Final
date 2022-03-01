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
#include "GPSRoutine.h"
//-------------
#include "routineRampSide.h"
#include "autonSkills.h"

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
//   //BlueSafeGoalSide();   //Blue is slot 2
//   //RedSafeGoalSide();    // Red is slot 1
//   //middlePriority();
//   //bluemiddlePriority();
//   score130points();
  
// }

//---Menu---
int tempStatus = 0;
void menuSetup(){
  menuCONFIG();
  notificationHUD("Robot: OK");
}
void Autonomous(){
  if(getValues(AUTON_COLOR)== BLUE){
    if(getValues(AUTON_TYPE) == GOALSIDE){
      //Blue goalside
      BlueSafeGoalSide();
    }else if(getValues(AUTON_TYPE) == MIDDLE){
      //Blue middle goal (usc)
      bluemiddlePriority();
    }else if(getValues(AUTON_TYPE) == SKILLS){
      score130points();
      printf("skills");
    }
  }else if(getValues(AUTON_COLOR)==RED){
      if(getValues(AUTON_TYPE) == GOALSIDE){
      //Red goalside
      RedSafeGoalSide();
    }else if(getValues(AUTON_TYPE) == MIDDLE){
      //Red middle goal (usc)
      redmiddlePriority();
    }else if(getValues(AUTON_TYPE) == SKILLS){
      //skills
      score130points();
    }
  }
  notificationHUD("Auton: Done");
}
void userControl(){
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
