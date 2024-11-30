//coil 1
byte MOTOR1_IN1 = 4;
byte MOTOR1_IN2 = 2;
byte ENABLE1 = 3;

//coil 2
byte MOTOR2_IN1 = 8;
byte MOTOR2_IN2 = 7;
byte ENABLE2 = 5;

//coil 3
byte MOTOR3_IN1 = 12;
byte MOTOR3_IN2 = 13;
byte ENABLE3 = 6;

//coil 4
byte MOTOR4_IN1 = A1;
byte MOTOR4_IN2 = A0;
byte ENABLE4 = 9;

//coil 5
byte MOTOR5_IN1 = A2;
byte MOTOR5_IN2 = A3;
byte ENABLE5 = 10;

//coil 6
byte MOTOR6_IN1 = A4;
byte MOTOR6_IN2 = A5;
byte ENABLE6 = 11;

uint16_t period = 1000L; // Speed

byte potentiometer = A7;
byte value = 0;
byte currentDelay = 200;
byte increment = 10;
byte finalDelay = 20;

void magnetPairOne(byte voltage,byte polarity){
  analogWrite(ENABLE1,voltage);
  analogWrite(ENABLE4,voltage);
  
  if(polarity == 0){
    digitalWrite(MOTOR1_IN1,HIGH);
    digitalWrite(MOTOR1_IN2,LOW);
    digitalWrite(MOTOR4_IN1,LOW);
    digitalWrite(MOTOR4_IN2,HIGH);
  }
  if(polarity == 1){
    digitalWrite(MOTOR1_IN1,LOW);
    digitalWrite(MOTOR1_IN2,HIGH);
    digitalWrite(MOTOR4_IN1,HIGH);
    digitalWrite(MOTOR4_IN2,LOW);
  }
}

void magnetPairTwo(byte voltage,byte polarity){
  analogWrite(ENABLE2,voltage);
  analogWrite(ENABLE5,voltage);
  
  if(polarity == 0){
    digitalWrite(MOTOR2_IN1,HIGH);
    digitalWrite(MOTOR2_IN2,LOW);
    digitalWrite(MOTOR5_IN1,LOW);
    digitalWrite(MOTOR5_IN2,HIGH);
  }
  if(polarity == 1){
    digitalWrite(MOTOR2_IN1,LOW);
    digitalWrite(MOTOR2_IN2,HIGH);
    digitalWrite(MOTOR5_IN1,HIGH);
    digitalWrite(MOTOR5_IN2,LOW);
  }
}

void magnetPairThree(byte voltage,byte polarity){
  analogWrite(ENABLE3,voltage);
  analogWrite(ENABLE6,voltage);
  
  if(polarity == 0){
    digitalWrite(MOTOR3_IN1,HIGH);
    digitalWrite(MOTOR3_IN2,LOW);
    digitalWrite(MOTOR6_IN1,LOW);
    digitalWrite(MOTOR6_IN2,HIGH);
  }
  if(polarity == 1){
    digitalWrite(MOTOR3_IN1,LOW);
    digitalWrite(MOTOR3_IN2,HIGH);
    digitalWrite(MOTOR6_IN1,HIGH);
    digitalWrite(MOTOR6_IN2,LOW);
  }
}

void setup() {
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(ENABLE1, OUTPUT);

  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
  pinMode(ENABLE2, OUTPUT);

  pinMode(MOTOR3_IN1, OUTPUT);
  pinMode(MOTOR3_IN2, OUTPUT);
  pinMode(ENABLE3, OUTPUT);

  pinMode(MOTOR4_IN1, OUTPUT);
  pinMode(MOTOR4_IN2, OUTPUT);
  pinMode(ENABLE4, OUTPUT);

  pinMode(MOTOR5_IN1, OUTPUT);
  pinMode(MOTOR5_IN2, OUTPUT);
  pinMode(ENABLE5, OUTPUT);

  pinMode(MOTOR6_IN1, OUTPUT);
  pinMode(MOTOR6_IN2, OUTPUT);
  pinMode(ENABLE6, OUTPUT);
  
  pinMode(potentiometer, INPUT);

  magnetPairOne(255,0);
  delay(5000);
}

void loop() {
  value = analogRead(potentiometer);
  finalDelay = map(value, 0, 1023, 100, 20); 

  magnetPairOne(255,0);
  magnetPairTwo(0,0);
  magnetPairThree(0,0);
  delay(currentDelay);
  magnetPairOne(0,0);
  magnetPairTwo(255,0);
  magnetPairThree(0,0);
  delay(currentDelay);
  magnetPairOne(0,0);
  magnetPairTwo(0,0);
  magnetPairThree(255,0);
  delay(currentDelay);

  if (currentDelay > finalDelay) {
    currentDelay = currentDelay - increment;
  }
  else if (currentDelay < finalDelay){
    currentDelay = currentDelay + increment;
  }
  else {
    currentDelay = finalDelay;
  }
}
