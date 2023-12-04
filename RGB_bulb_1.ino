// define pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define BUTTON 2

// define color mode
int mode = 0;

void setup() {
  // setup LED lights
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // setup button with an internal pull-up resistor
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // Check if button is pressed (logic is inverted due to INPUT_PULLUP)
  if (digitalRead(BUTTON) == LOW) {
    mode++; // Increment mode
    if (mode > 7) { // If mode exceeds 7, reset to 0
      mode = 0;
    }
    delay(400); // Debounce delay to avoid reading the button multiple times due to mechanical "bounce"
  }

  switch (mode) {
    case 0: // Off
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      break;
    case 1: // White
      analogWrite(RED, 255);
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 255);
      break;
    case 2: // Red
      analogWrite(RED, 255);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 0);
      break;
    case 3: // Orange
      analogWrite(RED, 255);
      analogWrite(GREEN, 75);
      analogWrite(BLUE, 0);
      break;
    case 4: // Yellow
      analogWrite(RED, 255);
      analogWrite(GREEN, 220);
      analogWrite(BLUE, 0);
      break;
    case 5: // Green
      analogWrite(RED, 0);
      analogWrite(GREEN, 255);
      analogWrite(BLUE, 0);
      break;
    case 6: // Blue
      analogWrite(RED, 0);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 255);
      break;
    case 7: // Violet
      analogWrite(RED, 100);
      analogWrite(GREEN, 0);
      analogWrite(BLUE, 255);
      break;
  }
}

