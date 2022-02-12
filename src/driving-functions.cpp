#include "vex.h"
#include "driving-functions.h"

//Drive
void tankDrive(){
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis2.value())){
    leftWheels.spin(fwd, controller1.Axis3.value()*1.4, pct);
    rightWheels.spin(fwd, controller1.Axis2.value()*1.4,pct);
  }else{
    leftWheels.stop(hold);
    rightWheels.stop(hold);
  }
}

void tankDriveToggle(){
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis2.value())){
    leftWheels.spin(fwd, controller1.Axis3.value()*1.4, pct);
    rightWheels.spin(fwd, controller1.Axis2.value()*1.4,pct);
  }else{
    leftWheels.stop(coast);
    rightWheels.stop(coast);
  }
}

void arcadeDrive(){
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis1.value())){

    leftWheels.spin(reverse,controller1.Axis3.value()*1.55+controller1.Axis1.value()*0.5,pct);
    rightWheels.spin(fwd, controller1.Axis3.value()*1.55-controller1.Axis1.value()*0.5,pct);

    leftWheels.spin(fwd,controller1.Axis3.value()*1.55+controller1.Axis1.value()*0.48,pct);
    rightWheels.spin(fwd, controller1.Axis3.value()*1.55-controller1.Axis1.value()*0.48,pct);

  }else{
    leftWheels.stop(hold);
    rightWheels.stop(hold);
  }
}

//4 Bar
void liftControl(){
  if(controller1.ButtonR1.pressing()){
    lift.spin(fwd, 55.0, pct);
  }else if(controller1.ButtonR2.pressing()){
    lift.spin(reverse, 30.0, pct);
  }else{
    lift.stop(hold);
  }
}

//Latch
bool toggle = false;
bool stopper = false;
void liftToggle(){
  if(toggle){
    latchDown.set(1);
  }else{
    latchDown.set(0);
  }

  if(controller1.ButtonA.pressing()||controller1.ButtonL1.pressing()){
    if(!stopper){
      toggle = !toggle;
      stopper = true;
    }
  }else{
    stopper = false;
  }
  wait(20,msec);
} 