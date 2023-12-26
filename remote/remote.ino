#include <IRremote.h>
#include <AFMotor.h>

IRrecv receptor(14);

decode_results resultado;

AF_DCMotor m4(4);
AF_DCMotor m3(3);

void setup()
{

  Serial.begin(9600);
  receptor.enableIRIn();
}
void loop()
{
  m3.setSpeed(255);
  m4.setSpeed(255);

  int i = 11111111;

  if (receptor.decode(&resultado)) {
    int x = resultado.value;
    Serial.println(x);
    if (x == -8161) {
      m3.run(BACKWARD);
      m4.run(BACKWARD);
    }
    if (x == -12241) {
      m3.run(FORWARD);
      m4.run(FORWARD);
    }
    if (x == -4081) {
      m3.run(RELEASE);
      m4.run(RELEASE);
    }
    if (x == 3724) {
      m3.setSpeed(50);
      m4.setSpeed(50);
      m3.run(BACKWARD);
      m4.run(FORWARD); 
    }
    if (x == 100000) {
      m3.run(FORWARD);
      m4.run(BACKWARD);
    }
  }
  receptor.resume();






}
