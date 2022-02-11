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
  moveForward(100, 100, 10);     
  latchDown.set(0);

  //lift a little to not drag
  liftAuton(0.5, 10, 10);
  moveForward(-20, 55, 10);     //-45, 48,10

  //dropping yellow goal
  turnClockwise(-20, 20, 10);     //turns left  
  moveForward(80, 50, 10);
  turnClockwise(-20, 20, 10);     //turns left
  liftAuton(240, 40, 5);
  wait(1, sec);  
  moveForward(60, 25, 10);
  liftAuton(-2, 20, 5);
  wait(1, sec);

  latchDown.set(1);


}