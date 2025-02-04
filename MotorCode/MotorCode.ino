// Motor control pin definitions
byte motorPins[6][3] = {
  {18, 19, 11},   // Coil 1: IN1, IN2, ENABLE
  {17, 16, 10},   // Coil 2
  {15, 14, 9}, // Coil 3
  {13, 12, 6}, // Coil 4
  {8, 7, 5},// Coil 5
  {2, 4, 3} // Coil 6
};
byte potentiometer = A7;
byte button = 0;
byte buttonRead = LOW;
byte buttonState = LOW;
byte buttonPrev = LOW;
unsigned long pressedTime = 0;
unsigned long debounce = 200UL;

byte increment = 10;
int currentDelay = 750;

void setCoil(byte motorIndex, byte voltage, byte polarity) {
  analogWrite(motorPins[motorIndex][2], voltage); // Set ENABLE pin
  if (polarity == 0) {
    digitalWrite(motorPins[motorIndex][0], HIGH); // MOTOR1_IN1, MOTOR2_IN1, MOTOR3_IN1, MOTOR4_IN1, MOTOR5_IN1, MOTOR6_IN1
    digitalWrite(motorPins[motorIndex][1], LOW);
  } else {
    digitalWrite(motorPins[motorIndex][0], LOW);
    digitalWrite(motorPins[motorIndex][1], HIGH);
  }
}

void delayUpdate() {
  int finalDelay = 0;
  int value = analogRead(potentiometer);

  if (value > 950) {   //Allows 2 different speed modes, demostrator (slow speed), adjustable (high speed)
    finalDelay = 750;
  }
  else {
    finalDelay = map(value, 0, 1023, 20, 150); //Maps the values of potentiometer into finalDelay values
    //Adjust currentDelay towards finalDelay
    if (currentDelay > finalDelay) {
      currentDelay = currentDelay - increment;
    }
    else if (currentDelay < finalDelay) {
      currentDelay = currentDelay + increment;
    }
    else {
      currentDelay = finalDelay;
    }
  }
  //Serial.println(value);
  //Serial.println(finalDelay);
}

void permanent() {
  for (byte i = 0; i <= 6; i++) {
    long recordedTime = millis();
    while (currentDelay >= millis() - recordedTime) {
      setCoil(i, 128, 0); // Activate coil with polarity 0
      setCoil((i + 3) % 7, 128, 1);
      delayUpdate(); //Increments the currentDelay towards finalDelay
    }
    setCoil(i, 0, 0);   // Deactivate coil
    setCoil((i + 3) % 7, 0, 0);
    delayUpdate();
  }
}

void synchronous() {
  for (byte i = 0; i <= 6; i++) {
    long recordedTime = millis();
    while (currentDelay >= millis() - recordedTime) {
      if (i % 2 == 0) {
        setCoil(i, 128, 1); // Activate coil with polarity 0
        setCoil((i + 3) % 7, 128, 0);
      } else {
        setCoil(i, 128, 0); // Activate coil with polarity 0
        setCoil((i + 3) % 7, 128, 1);
      }
      delayUpdate(); //Increments the currentDelay towards finalDelay
    }
    setCoil(i, 0, 0);   // Deactivate coil
    delayUpdate();
  }
}

void setup() {
  for (byte i = 0; i <= 6; i++) {
    pinMode(motorPins[i][0], OUTPUT); // IN1
    pinMode(motorPins[i][1], OUTPUT); // IN2
    pinMode(motorPins[i][2], OUTPUT); // ENABLE
  }

  pinMode(potentiometer, INPUT);
  pinMode(button, INPUT);

  setCoil(0, 255, 0); //Set motor to starting position
  delay(2500);
  Serial.begin(9600); //Allows debugging using the serial monitor
}

void loop() {
  buttonRead = digitalRead(button);
  
  if (buttonRead == HIGH && buttonPrev == LOW && millis() - pressedTime > debounce)
  {
    if (buttonState == HIGH){
      buttonState = LOW;
    }
    else {
      buttonState = HIGH;
    }
    pressedTime = millis();
  }

  if (buttonState == LOW) {
    permanent();
    Serial.println("Permanet");
  }
  else if (buttonState == HIGH) {
    synchronous();
    Serial.println("Synchronous");
  }

  buttonPrev = buttonRead;

}
