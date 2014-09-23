/*
 * This sketch signals an output pin to turn on and off
 */

int relay_pin = 12; // This is the Arduino pin the relay is connected to
int led_pin = 13;   // 13 is the pin for the Arduino's built in LED

void setup() {
  // Setup the serial port at 9600 baud
  Serial.begin(9600);

  // Set the relay pin to be an output
  pinMode(relay_pin, OUTPUT);

  pinMode(led_pin, OUTPUT);
}

void loop() {
  // Turn on the relay and led
  Serial.println("ON");
  digitalWrite(relay_pin, HIGH);
  digitalWrite(led_pin, HIGH);

  // Wait a second
  delay(1000);

  // Turn off the relay and led
  Serial.println("OFF");
  digitalWrite(relay_pin, LOW);
  digitalWrite(led_pin, LOW);

  // Wait another second
  delay(1000);
}
