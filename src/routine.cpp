#include "vex.h"
#include "routine.h"
#include "autonomous-functions.h"
#include "robot-config.h"
#include "driving-functions.h"
#include "GPS.h"

using namespace vex;
using namespace std;

//Grab side yellow goal in front
//Alignment(goalside):
//NOT STARTING IN CORNER SQUARE
//line left/right with stick, top right small wheel touch
//angle left a little according to goal in front
//Alignment(rampside):
//NOT STARTING IN CORNER SQUARE
//front left tip wheel on corner that touches 4 squares
void aimatCorner(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(105, 55, 10);     
  moveForward(100, 100, 10);     
  latchDown.set(0);

  //lift a little to not drag
  liftAuton(0.5, 10, 10);
  moveForward(-20, 55, 10);     //-45, 48,10

  //dropping yellow goal
  turnClockwise(-20, 20, 10);     //turns left
  moveForward(80, 50, 10);
  turnClockwise(-20, 20, 10);     //turns left
  liftAuton(240, 50, 5);
  wait(1, sec);  
  moveForward(60, 25, 10);
  liftAuton(-2, 20, 5);
  wait(1, sec);
  latchDown.set(1);

  //go to remove red from corner
  moveForward(-10, 10, 10);
  liftAuton(-120, 10, 10);   //push lift to the bottom
  turnClockwise(-20, 20, 10); 
  moveForward(100, 100, 10);
  latchDown.set(0);
  moveForward(-150, 10, 10);
  turnClockwise(21, 20, 10);
  liftAuton(240, 50, 5);
  wait(1, sec);
  moveForward(25, 20, 10);
  liftAuton(-2, 20, 5);
  wait(1, sec);
  latchDown.set(1);

}


void aimatCornerGPS(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(100, 100, 10); 
  latchDown.set(0);
  liftAuton(0.5, 10, 10);
  moveForward(-20, 55, 10);

  //gps to align to middle of ramp
  DriveToTargetXY(570, 0, 32, 65);
  Drivetrain.stop();
  wait(1, sec);
  DriveToHeading(93, 25, 3);      //95 degree 

  liftAuton(240, 30, 5);
  wait(1, sec);
  moveForward(55, 25, 10);
  wait(1,sec);
  latchDown.set(1);

  moveForward(-25, 10, 10);
  wait(1, sec);
  liftAuton(-125, 10, 10);
  DriveToHeading(0, 25, 10);

  //go for blue 
  DriveToTargetXY(1020, 1290, 32, 65);
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
  DriveToHeading(270, 25, 3);

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


