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
  moveForward(-40, 55, 10);     //-45, 48,10

  //dropping yellow goal
  turnClockwise(-20, 20, 10);     //turns left  //orignial: turnClockwise(-20, 20, 10); 
  moveForward(75, 20, 10);
  turnClockwise(-16, 20, 10);     //turns left
  liftAuton(240, 50, 5);
  wait(2, sec);  
  moveForward(40, 20, 10);
  liftAuton(-2, 20, 5);
  wait(1, sec);
  latchDown.set(1);

  //go to remove red from corner
  moveForward(-10, 20, 10);
  liftAuton(-120, 10, 10);   //push lift to the bottom
  turnClockwise(-20, 20, 10); 
  moveForward(100, 100, 10);
  latchDown.set(0);
  moveForward(-120, 100, 10);
  turnClockwise(20, 20, 10);
  liftAuton(240, 50, 5);
  moveForward(10, 20, 10);
  liftAuton(-2, 20, 5);
  wait(1, sec);
  latchDown.set(1);

//-------------------------------------------
 //ORIGINAL CODE HERE


  // liftAuton(0, 10, 10);     //push lift to bottom
  // latchDown.set(1);           //open
  // moveForward(101.5, 100, 10);     
  // latchDown.set(0);
  // moveForward(-75, 48, 10);

  // //dropping yellow goal
  // turnClockwise(-10, 20, 10);     //turns left
  // moveForward(37, 20, 10);
  // latchDown.set(1);
  // moveForward(-40, 30, 10);

  // //grabbing personal
  // turnClockwise(-12, 20, 10);     
  // moveForward(23, 25, 10);
  // latchDown.set(0);
  // moveForward(-85, 30, 10);

  // //position for ramp, moving and lifting lift
  // turnClockwise(-53, 20, 5);     
  // liftAuton(120, 50, 5);       
  // moveForward(20, 20, 5);

  // //PLAN B FORCE IN
  // turnClockwise(-17.5, 15, 5);   //-18,15,10
  // moveForward(15, 10, 5);
  // latchDown.set(1);


  // // //PLAN A REGULAR ALIGN
  // // //turn into ramp and drop
  // // turnClockwise(-14, 15, 10);    //turning against ramp   
  // // moveForward(25, 20, 10);       //get closer to drop
  // // latchDown.set(1);

  // // //position for driver 
  // // moveForward(-20, 20, 10);      
  // // turnClockwise(35, 20, 10);
}