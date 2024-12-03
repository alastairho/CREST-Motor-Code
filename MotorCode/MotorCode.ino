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
byte button = 0;

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

void delayUpdate(){
  int value = analogRead(potentiometer);
  int finalDelay = map(value, 0, 1023, 20, 150); //Maps the values of potentiometer into finalDelay values
  Serial.println(currentDelay);

  if (finalDelay > 100) {   //Allows 2 different speed modes, demostrator (slow speed), adjustable (high speed)
    finalDelay = 750;
  }
  else {
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
}

void permanent(){
  for (byte i = 0; i <= 6; i++) {
    long recordedTime = millis();
    while (currentDelay >= millis()-recordedTime){
      setCoil(i, 128, 0); // Activate coil with polarity 0
      setCoil((i+3)%7, 128, 1);
      delayUpdate(); //Increments the currentDelay towards finalDelay
    }
    setCoil(i, 0, 0);   // Deactivate coil
    setCoil((i+3)%7, 0, 0);
    delayUpdate();
  }
}

void synchronous(){
  for (byte i = 0; i <= 6; i++) {
    long recordedTime = millis();
    while (currentDelay >= millis()-recordedTime){
      if (i % 2 == 0){
        setCoil(i, 128, 1); // Activate coil with polarity 0
        setCoil((i+3)%7, 128, 0);
      }else{
        setCoil(i, 128, 0); // Activate coil with polarity 0
        setCoil((i+3)%7, 128, 1);
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

  setCoil(0, 255, 0); //Set motor to starting position
  delay(2500);
  Serial.begin(9600); //Allows debugging using the serial monitor
}

void loop() {
  if (button == LOW){
    permanent();
  }
  else{
    synchronous();
  }
}
