#include <Ultrasonic.h>

const int buzzer = 10;
const int led = 11;
const int trigPin = 12;
const int echoPin = 13;

Ultrasonic ultrasonic(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  int distancia = (ultrasonic.Ranging(CM));

  switch(distancia) {
    case 20:
    case 19:
    case 18:
    case 17:
    case 16:
      tone(buzzer, 500);
      digitalWrite(led, HIGH);
      delay(100);
    case 15:
    case 14:
    case 13:
    case 12:
    case 11:
      tone(buzzer, 1000);
      digitalWrite(led, HIGH);
      delay(50);
    case 10:
    case 9:
    case 8:
    case 7:
    case 6:
      tone(buzzer, 1500);
      digitalWrite(led, HIGH);
      delay(25);
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
      tone(buzzer, 2000);
      digitalWrite(led, HIGH);
      delay(12);
    default:
      digitalWrite(led, LOW);
      noTone(buzzer);
      delay(200);
  }

  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
}
