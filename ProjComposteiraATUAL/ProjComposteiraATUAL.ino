#include <dht.h>

#define BZ 2
#define HT 3
#define PM 4
#define LA 5
#define CC 6

dht DHT;

int i = 0;
float TI;
float T = 0;


void setup() {
  Serial.begin(9600);
  pinMode(HT, INPUT);
  pinMode(LA, OUTPUT);
  pinMode(PM, OUTPUT);
  pinMode(CC, OUTPUT);
  pinMode(BZ, OUTPUT);
  digitalWrite(BZ, HIGH);
  delay(100);
  digitalWrite(BZ, LOW);
}

void loop()
{
  digitalWrite(PM, HIGH);
  delay(5000);
  digitalWrite(PM, LOW);

  if (i >= 1) {

    int readData = DHT.read11(HT);
    float H = DHT.humidity;
    T = DHT.temperature;

    digitalWrite(HT, LOW);

    Serial.print("    Temperature = ");
    Serial.print(T);

    if (H >= 61) {
      digitalWrite(LA , LOW);
      digitalWrite(PM , HIGH);
      delay(500);
    } else {
      digitalWrite(PM , LOW);
    }

    if (H <= 49) {
      digitalWrite(PM , LOW);
      digitalWrite(LA , HIGH);
      delay(500);
    } else {
      digitalWrite(LA , LOW);
    }

    Serial.print(" °C ");
    Serial.print("    Humidity = ");
    Serial.print(H);
    Serial.println(" % ");
  } else {

    TI = DHT.read11(HT);
    TI = DHT.temperature;
    delay(1000);

  }
  Serial.print("Temperatura inicial: ");
  Serial.print(TI);


  if (i >= 6) {
    if ( TI == T ) {
      digitalWrite(CC , HIGH);
      digitalWrite(BZ, HIGH);
      delay(200);
      digitalWrite(BZ, LOW);
      digitalWrite(LA , LOW);
      digitalWrite(PM , LOW);
      Serial.print("  COMPOSTO CURADO ");
      delay(10000);
      digitalWrite(CC , LOW);
    }
  } else {
    digitalWrite(CC , LOW);

  }
  i++;

  delay(30000);
}
