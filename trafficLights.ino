// Min Prasad Timalsina
// 3 Way Traffic Light System

// Define LED pins
int redLEDA = 13;
int yellowLEDA = 12;
int greenLEDA = 11;
int redLEDB = 10;
int yellowLEDB = 9;
int greenLEDB = 8;
int redLEDC = 7;
int yellowLEDC = 6;
int greenLEDC = 5;
int buttonPin = 2;
int state = 0;

// Function to set red lights
void redLights()
{
  digitalWrite(redLEDA, HIGH);
  digitalWrite(redLEDB, HIGH);
  digitalWrite(redLEDC, LOW);
  digitalWrite(greenLEDC, HIGH);
}

// Function to set green lights
void greenLights()
{
   digitalWrite(greenLEDA, HIGH);
  digitalWrite(greenLEDB, HIGH);
  digitalWrite(greenLEDC, LOW);
  digitalWrite(redLEDC, HIGH);
}

// Function to set yellow lights
void yellowLights()
{
  digitalWrite(yellowLEDA, HIGH);
  digitalWrite(yellowLEDB, HIGH);
  digitalWrite(yellowLEDC, HIGH);
}

// Function to turn off all lights
void turnOffLights()
{
  digitalWrite(redLEDA, LOW);
  digitalWrite(yellowLEDA, LOW);
  digitalWrite(greenLEDA, LOW);
  digitalWrite(redLEDB, LOW);
  digitalWrite(yellowLEDB, LOW);
  digitalWrite(greenLEDB, LOW);
  digitalWrite(redLEDC, LOW);
  digitalWrite(yellowLEDC, LOW);
  digitalWrite(greenLEDC, LOW);
}

// Function to handle button press
void on()
{
  if (state == 0)
  {
    // Print a message when the emergency light is pressed
    Serial.println("Emergency Light Pressed");
    // Activate the emergency lights
    emergencyLights();
    // Reset the state to allow the button to be pressed again
    state = 0;
  }
  else
  {
    // Print a message when the button is pressed again
    Serial.println("Button pressed again");
    Serial.println(state);
    // Reset the state to allow the button to be pressed again
    state = 0;
  }
}

// Function to activate emergency lights
void emergencyLights()
{
  for (int i = 0; i < 10; ++i)  // Blink for 10 seconds
  {
    turnOffLights();
    digitalWrite(redLEDA, HIGH);
    digitalWrite(redLEDB, HIGH);
    digitalWrite(redLEDC, HIGH);
    delay(5000);  // 5000 milliseconds on
    turnOffLights();
    delay(5000);  // 5000 milliseconds off
     digitalWrite(redLEDA, HIGH);
    digitalWrite(redLEDB, HIGH);
    digitalWrite(redLEDC, HIGH);
    delay(5000);  // 5000 milliseconds on
    turnOffLights();
    delay(5000);  // 500 milliseconds off
     digitalWrite(redLEDA, HIGH);
    digitalWrite(redLEDB, HIGH);
    digitalWrite(redLEDC, HIGH);
    delay(5000);  // 5000 milliseconds on
    turnOffLights();
    delay(5000);  // 5000 milliseconds off
  }
}

void setup()
{
  Serial.begin(9600);

  // Set LED pins as output
  pinMode(redLEDA, OUTPUT);
  pinMode(yellowLEDA, OUTPUT);
  pinMode(greenLEDA, OUTPUT);
  pinMode(redLEDB, OUTPUT);
  pinMode(yellowLEDB, OUTPUT);
  pinMode(greenLEDB, OUTPUT);
  pinMode(redLEDC, OUTPUT);
  pinMode(yellowLEDC, OUTPUT);
  pinMode(greenLEDC, OUTPUT);
  pinMode(buttonPin, INPUT);

  // Attach button interrupt
  attachInterrupt(digitalPinToInterrupt(buttonPin), on, RISING);
}

void loop()
{
  // Traffic light control loop
  while (true)
  {
    // All roads red lights for 5 seconds
    turnOffLights();
    redLights();
    delay(5000);

    // All roads yellow lights for 5 seconds
    turnOffLights();
    yellowLights();
    delay(5000);

    // Road A and B green lights, Road C red light for 5 seconds
    turnOffLights();
    greenLights();
    digitalWrite(redLEDC, HIGH); // Turn on Road C red light
    delay(5000);

    // All roads yellow lights for 5 seconds
    turnOffLights();
    yellowLights();
    delay(5000);
  }
}