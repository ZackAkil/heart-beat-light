
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
//  Serial.println(constrain(sensorValue, 500, 550));
  Serial.println(sensorValue);

  delay(2);
}
