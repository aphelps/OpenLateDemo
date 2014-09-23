/*
 * This sketch listens for signals over the serial port and enables an external
 * relay based on commands from the input stream.
 */

int relay_pin = 12; // This is the Arduino pin the relay is connected to
int led_pin = 13;   // 13 is the pin for the Arduino's built in LED

#define ON_VALUE "on"
#define OFF_VALUE "off"

void setup() {
  // Setup the serial port at 9600 baud
  Serial.begin(9600);

  // Set the relay pin to be an output
  pinMode(relay_pin, OUTPUT);

  pinMode(led_pin, OUTPUT);

  Serial.println("READY");
}

// Data buffer for reading a line from the serial port
char data[256];
int data_ptr = 0;

void loop() {
  if (Serial.available()) {
    boolean line_done = false;

    // Read into the buffer one character at a time
    while ((Serial.available() > 0) && (data_ptr < 256)) {
      char value = Serial.read();

      if (value == '\n') {
	// End of line, null terimate the string and break out
	data[data_ptr] = '\0';
	line_done = true;
	break;
      }

      data[data_ptr] = value;
      data_ptr++;
    }

    if (line_done) {
      Serial.print("Read line: ");
      Serial.println(data);

      // Handle the completed line
      if (strcmp(data, ON_VALUE) == 0) {
	Serial.println("ON");
	digitalWrite(relay_pin, HIGH);
	digitalWrite(led_pin, HIGH);
      } else if (strcmp(data, OFF_VALUE) == 0) {
	Serial.println("OFF");
	digitalWrite(relay_pin, LOW);
	digitalWrite(led_pin, LOW);
      }

      data_ptr = 0; // Reset the data pointer
    }
  }
}
