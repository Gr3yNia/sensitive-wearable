#include <Adafruit_CircuitPlayground.h>

#define lightPin A1
#define pressurePin A4
#define ledPin A2

int lightValue;
int pressureValue;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(ledPin, OUTPUT);
}

void loop() {

  lightValue = analogRead(lightPin);
  pressureValue = analogRead(pressurePin);

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print("\tPressure: ");
  Serial.println(pressureValue);

  // LIGHT SENSOR → LED
  if (lightValue < 5) {   // dark
  digitalWrite(ledPin, HIGH);
} else {                 // bright
  digitalWrite(ledPin, LOW);
}

  // PRESSURE SENSOR → TONES
  if (pressureValue > 780) {

    int pitch = map(pressureValue, 780, 1023, 300, 1200);

    CircuitPlayground.playTone(pitch, 80);
  }

  delay(100);
}
