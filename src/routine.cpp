#include "vex.h"
#include "routine.h"
#include "autonomous-functions.h"
#include "robot-config.h"
#include "driving-functions.h"

using namespace vex;
using namespace std;

//Grab side yellow goal in front
//Alignment(goalside):
//NOT STARTING IN CORNER SQUARE
//front left tip wheel on top edge of starting square
//back right corner aligned on right side of square
//Alignment(rampside):
//NOT STARTING IN CORNER SQUARE
//front left tip wheel on corner that touches 4 squares
void aimatCorner(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(120, 55, 10);
  latchDown.set(0);
  moveForward(-130, 55, 10);

  //dropping yellow goal
  turnClockwise(30, 50, 10);
  moveForward(20, 20, 10);
  latchDown.set(1);
  moveForward(-40, 30, 10);

  //grabbing red
  turnClockwise(-13, 15, 10);
  moveForward(50, 25, 10);
  latchDown.set(0);
  moveForward(-40, 30, 10);

//NATE'S EDIT STARTS HERE
  //position for ramp
  turnClockwise(-30, 30, 10);
  moveForward(25, 20, 10);
  turnClockwise(-30, 30, 10); 
  moveForward(35, 20, 10);
  //turnClockwise(-15, 25, 10);
 // moveForward(20,15,10);






}