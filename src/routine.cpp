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
//line left/right with stick, top right small wheel touch
//angle left a little according to goal in front
//Alignment(rampside):
//NOT STARTING IN CORNER SQUARE
//front left tip wheel on corner that touches 4 squares
void aimatCorner(){
  liftAuton(0, 10, 10);     //push lift to bottom
  latchDown.set(1);           //open
  moveForward(105, 55, 10);     
  latchDown.set(0);
  moveForward(-80, 55, 10);

  //dropping yellow goal
  turnClockwise(-40, 20, 10);     //turns left
  moveForward(20, 20, 10);
  latchDown.set(1);
  moveForward(-40, 30, 10);

  //grabbing personal
  turnClockwise(-14, 20, 10);     
  moveForward(36, 25, 10);
  latchDown.set(0);
  moveForward(-75, 30, 10);

  //position for ramp, moving and lifting lift
  turnClockwise(-46, 20, 10);     
  liftAuton(120, 50, 10);       
  moveForward(50, 20, 10);

  //PLAN B FORCE IN
  turnClockwise(-17.5, 15, 10);   //-18,15,10
  moveForward(15, 10, 10);
  latchDown.set(1);


  // //PLAN A REGULAR ALIGN
  // //turn into ramp and drop
  // turnClockwise(-14, 15, 10);    //turning against ramp   
  // moveForward(25, 20, 10);       //get closer to drop
  // latchDown.set(1);

  // //position for driver 
  // moveForward(-20, 20, 10);      
  // turnClockwise(35, 20, 10);
}