#include "vex.h"
#include "driving-functions.h"

//Drive
void tankDrive(){
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis2.value())){
    leftWheels.spin(reverse, controller1.Axis3.value()*1.5, pct);
    rightWheels.spin(fwd, controller1.Axis2.value()*1.5,pct);
  }else{
    leftWheels.stop(coast);
    rightWheels.stop(coast);
  }
}

void arcadeDrive(){
  if(abs(controller1.Axis3.value())>5||abs(controller1.Axis1.value())){
    leftWheels.spin(reverse,controller1.Axis3.value()*1.85+controller1.Axis1.value(),pct);
    rightWheels.spin(fwd, controller1.Axis3.value()*1.85-controller1.Axis1.value(),pct);
  }else{
    leftWheels.stop(coast);
    rightWheels.stop(coast);
  }
}

//4 Bar
void liftControl(){
  if(controller1.ButtonL1.pressing()){
    //lift.spin(fwd);
    lift.spin(fwd, 35.0, pct);
  }else if(controller1.ButtonL2.pressing()){
    //lift.spin(reverse);
    lift.spin(reverse, 25.0, pct);
  }else{
    lift.stop(hold);
  }
}

/*
void liftToggle(){
  if(controller1.ButtonA.pressing()){
    latchDown.set(1);
    printf("pressing\n");
  }else{
    latchDown.set(0);                                         
    printf("not\n");
  }
}*/

bool toggle = false;
bool stopper = false;
void liftToggle(){
  if(toggle){
    latchDown.set(1);
  }else{
    latchDown.set(0);
  }

  if(controller1.ButtonA.pressing()){
    if(!stopper){
      toggle = !toggle;
      stopper = true;
    }
  }else{
    stopper = false;
  }
  wait(20,msec);
} 