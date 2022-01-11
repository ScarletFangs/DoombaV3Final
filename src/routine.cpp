#include "vex.h"
#include "routine.h"
#include "autonomous-functions.h"
#include "robot-config.h"
#include "driving-functions.h"

using namespace vex;
using namespace std;

void goalside(){
  moveForward(100, 50, 10);

  //pneumatic();
  //pneumatic();
}