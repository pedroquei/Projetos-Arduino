#include <AFMotor.h>

AF_DCMotor me(4);
AF_DCMotor md(3);

int st = 18;
int sf = 19;
int se = 15;
int sd = 16;

void setup() {

  me.setSpeed(255);
  md.setSpeed(255);
  me.run(RELEASE);
  md.run(RELEASE);

  pinMode(st, INPUT);
  pinMode(sf, INPUT);
  pinMode(sd, INPUT);
  pinMode(se, INPUT);
  /* LOW = luz apagada */
}

void loop() {

  if (digitalRead(sd)) {
  }

  if (digitalRead(se) == 0) {
    me.run(RELEASE);
    md.run(FORWARD);
  if (digitalRead(sd) == 0){
    me.run(FORWARD);
    md.run(FORWARD);
  }
  } else {

    if (digitalRead(sd) == 0) {
      me.run(FORWARD);
      md.run(RELEASE);
    }
  }
}
