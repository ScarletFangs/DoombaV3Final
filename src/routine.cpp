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
  moveForward(120, 55, 10);
  latchDown.set(0);
  moveForward(-80, 55, 10);

  //dropping yellow goal
  turnClockwise(-37, 20, 10);
  moveForward(20, 20, 10);
  latchDown.set(1);
  moveForward(-40, 30, 10);

<<<<<<< Updated upstream
  //grabbing red
  turnClockwise(-12, 20, 10);
  moveForward(50, 25, 10);
=======
  //grabbing personal
  turnClockwise(-15, 20, 10);     
  moveForward(36, 25, 10);
>>>>>>> Stashed changes
  latchDown.set(0);
  moveForward(-75, 30, 10);

//NATE'S EDIT STARTS HERE
  //position for ramp
  turnClockwise(-47, 20, 10);
  liftAuton(120, 10, 10);
  moveForward(50, 20, 10);
  turnClockwise(-13, 15, 10); 
  moveForward(30, 20, 10);
  latchDown.set(1);
  moveForward(-40, 20, 10);
  turnClockwise(35, 20, 10);
  //moveForward(20, 7, 10);


 //BELOW ARE THE OUTLINE OF THE NEXT STEPS
 //lift hinge
  
 //move forward just a lil bit (distance: 3 or 5)
 // moveForward(5, 20, 10);
 //detach th clamp (release goal)
  //latchDown.set(1);
  //move back
  //moveForward(-10, 20, 10);

}