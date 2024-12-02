// Motor control pin definitions
byte motorPins[6][3] = {
  {4, 2, 3},   // Coil 1: IN1, IN2, ENABLE
  {8, 7, 5},   // Coil 2
  {12, 13, 6}, // Coil 3
  {A1, A0, 9}, // Coil 4
  {A2, A3, 10},// Coil 5
  {A4, A5, 11} // Coil 6
};
byte potentiometer = A7;

byte increment = 10;
int value = 0;
int currentDelay = 750;
int finalDelay = 750;

void setCoil(byte motorIndex, byte voltage, byte polarity) {
  analogWrite(motorPins[motorIndex][2], voltage); // Set ENABLE pin
  //analogWrite(motorPins[motorIndex + 3][2], voltage);
  if (polarity == 0) {
    digitalWrite(motorPins[motorIndex][0], HIGH); // MOTOR1_IN1, MOTOR2_IN1, MOTOR3_IN1, MOTOR4_IN1, MOTOR5_IN1, MOTOR6_IN1
    digitalWrite(motorPins[motorIndex][1], LOW);
  } else {
    digitalWrite(motorPins[motorIndex][0], LOW);
    digitalWrite(motorPins[motorIndex][1], HIGH);
  }
}

void setup() {
  for (byte i = 0; i <= 6; i++) {
    pinMode(motorPins[i][0], OUTPUT); // IN1
    pinMode(motorPins[i][1], OUTPUT); // IN2
    pinMode(motorPins[i][2], OUTPUT); // ENABLE
  }

  pinMode(potentiometer, INPUT);

  setCoil(0, 255, 0);
  delay(5000);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(potentiometer);
  finalDelay = map(value, 0, 1023, 20, 1000); //Maps the values of potentiometer into finalDelay values
  Serial.println(currentDelay);

  for (byte i = 0; i <= 6; i++) {
    setCoil(i, 255, 0); // Activate coil with polarity 0
    delay(currentDelay);
    setCoil(i, 0, 0);   // Deactivate coil

      //Adjust currentDelay towards finalDelay (Set by potentiometer)
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
}
