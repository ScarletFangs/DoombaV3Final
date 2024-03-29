#include "vex.h"
#include "routine.h"
#include "autonomous-functions.h"
#include "robot-config.h"
#include "driving-functions.h"
#include "GPS.h"

using namespace vex;
using namespace std;

//Blue is slot 2
void BlueSafeGoalSide(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(100, 100, 10); 
  latchDown.set(0);
  liftAuton(0.5, 10, 10);
  moveForward(-90, 55, 10);
  DriveToHeading(88, 25, 3);
  latchDown.set(1);
  moveForward(-22, 20, 10);

  //grab blue go other side
  DriveToTargetXY(900, 1330, 25, 85);
  //DriveToHeading(-10, 27, 3);
  moveForward(25, 20, 10);
  wait(1, sec);
  latchDown.set(0);

  //back to other side
  DriveToTargetXY(930, -600, 32, 65);
  wait(1, sec);
  DriveToHeading(180, 25, 3); //turn
  latchDown.set(1);
  moveForward(-10, 10, 10);

  //middle
  DriveToTargetXY(900, 0, 32, 65);
  wait(1, sec);
  DriveToHeading(259, 25, 3);
  DriveToTargetXY(0, 0, 32, 65);
  latchDown.set(0);
  DriveToTargetXY(900, 0, 32, 65);
}

//Red is slot 1
void RedSafeGoalSide(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(100, 100, 10); 
  latchDown.set(0);
  liftAuton(0.5, 10, 10);
  moveForward(-90, 55, 10);
  DriveToHeading(268, 25, 3);
  latchDown.set(1);
  moveForward(-22, 20, 10);

  //grab blue go other side
  DriveToTargetXY(-900, -1330, 25, 85);
  //DriveToHeading(-10, 27, 3);
  moveForward(25, 20, 10);
  wait(1, sec);
  latchDown.set(0);

  //back to other side
  DriveToTargetXY(-930, 600, 32, 65);
  wait(1, sec);
  DriveToHeading(0, 25, 3); //turn
  latchDown.set(1);
  moveForward(-10, 10, 10);

  //middle
  DriveToTargetXY(-900, 0, 32, 65);
  wait(1, sec);
  DriveToHeading(79, 25, 3);
  DriveToTargetXY(0, 0, 32, 65);
  latchDown.set(0);
  DriveToTargetXY(-900, 0, 32, 65);
}

void aimatCornerGPS(){
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("LiftL1 temp: %f/n", liftL1.temperature());
    Brain.Screen.print("LiftL2 temp: %f/n", liftL2.temperature());
    Brain.Screen.print("LiftR1 temp: %f/n", liftR1.temperature());
    Brain.Screen.print("LiftR2 temp: %f/n", liftR2.temperature());
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(100, 100, 10); 
  latchDown.set(0);
  liftAuton(0.5, 10, 10);
  moveForward(-20, 55, 10);

  //gps to align to middle of ramp
  DriveToTargetXY(570, 75, 32, 65);
  Drivetrain.stop();
  wait(1, sec);
  DriveToHeading(91, 25, 3);      //93 almos work      

  liftAuton(240, 30, 5);
  wait(1, sec);
  moveForward(55, 25, 10);
  //liftAuton(-3, 10, 10);
  //wait(1,sec);
  latchDown.set(1);

  moveForward(-25, 10, 10);
  wait(1, sec);
  liftAuton(-125, 10, 10);
  DriveToHeading(0, 25, 10);

  //go for blue 
  DriveToTargetXY(900, 1330, 25, 85);
  //DriveToHeading(-10, 27, 3);
  moveForward(25, 20, 10);
  wait(1, sec);
  latchDown.set(0);

  //back to other side
  DriveToTargetXY(930, -600, 32, 65);
  wait(1, sec);
  DriveToHeading(180, 25, 3); //turn
  latchDown.set(1);

  //middle
  DriveToTargetXY(900, 0, 32, 65);
  wait(1, sec);
  DriveToHeading(259, 25, 3);
  moveForward(60, 40, 10);
  latchDown.set(0);
  moveForward(-60, 40, 10);
}




//Grab middle goal
void rampSide(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(155, 55, 10);     
  latchDown.set(0);
  moveForward(-142, 55, 10);
  turnClockwise(-40, 20, 10);
  latchDown.set(1);
  moveForward(-15, 20, 10);
  turnClockwise(40, 20, 10);
}


void redmiddlePriority()
{
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(125,100,10);
  latchDown.set(0);
  moveForward(-30, 100, 10);
  DriveToTargetXY(-1000, -1200, 32, 65);
  liftAuton(240, 30, 5);
  latchDown.set(1);
  moveForward(15, 80, 10);
  liftAuton(-220, 50, 10);
  // moveForward(-30,50,10);
  // DriveToHeading(259, 25, 3);
  // DriveToTargetXY(-310, -10, 32, 65);



}
void bluemiddlePriority()
{
  liftAuton(0, 10, 5);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(125, 100, 100);
  latchDown.set(0);
  moveForward(-30, 100, 10);
  DriveToTargetXY(1000, -1200, 32, 65);
  liftAuton(240, 30, 5);
  latchDown.set(1);
  moveForward(15, 80, 10);
  liftAuton(-220, 50, 10);
  //moveForward(-80, 100, 10);
  //turnClockwise(40, 20, 10);
  //DriveToTargetXY(-310, -10, 32, 65);



}