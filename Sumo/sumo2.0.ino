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

  pinMode(st, INPUT);
  pinMode(sf, INPUT);
  pinMode(sd, INPUT);
  pinMode(se, INPUT);
  /* LOW = luz apagada */
}

void loop() {

  if (digitalRead(sd) == 0 && digitalRead(se) == 0) {
    frente();
  }
  if (digitalRead(sd) == 0 && digitalRead(se) == 1) {
    direita();
  }
  if (digitalRead(sd) == 1 && digitalRead(se) == 0) {
    esquerda();
  }
  if (digitalRead(sd) == 1 && digitalRead(se) == 1) {
    parar();
  }
  if (digitalRead(st) == 0 && digitalRead(sf) == 1) {
    frente();
  }
  if (digitalRead(st) == 1 && digitalRead(sf) == 0) {
    tras();
  }
  if (digitalRead(st) == 1 && digitalRead(sf) == 1) {
    parar();
  }
}

void frente() {
  me.run(FORWARD);
  md.run(FORWARD);
}

void tras() {
  me.run(BACKWARD);
  md.run(BACKWARD);
}
void direita() {
  me.run(FORWARD);
  md.run(RELEASE);
}

void esquerda() {
  me.run(RELEASE);
  md.run(FORWARD);
}

void parar() {
  me.run(RELEASE);
  md.run(RELEASE);
}