//coil 1
int m1p1 = 4;
int m1p2 = 2;
int EN1 = 3;
float strength1 = 0;

//coil 2
int m2p1 = 8;
int m2p2 = 7;
int EN2 = 5;
float strength2 = 0;

//coil 3
int m3p1 = 12;
int m3p2 = 13;
int EN3 = 6;
float strength3 = 0;

//coil 4
int m4p1 = A1; 
int m4p2 = A0;
int EN4 = 9;
float strength4 = 0;

//coil 5
int m5p1 = A2;
int m5p2 = A3;
int EN5 = 10;
float strength5 = 0;

//coil 6
int m6p1 = A4;
int m6p2 = A5;
int EN6 = 11;
float strength6 = 0;

uint32_t period = 1000L; // Speed

int potentiometer = A7;
int value = 0;
int time = 200;
int step = 10;
int maxSpeed = 20;

void setup() {
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(EN1, OUTPUT);

  pinMode(m2p1, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(EN2, OUTPUT);

  pinMode(m3p1, OUTPUT);
  pinMode(m3p2, OUTPUT);
  pinMode(EN3, OUTPUT);

  pinMode(m4p1, OUTPUT);
  pinMode(m4p2, OUTPUT);
  pinMode(EN4, OUTPUT);

  pinMode(m5p1, OUTPUT);
  pinMode(m5p1, OUTPUT);
  pinMode(EN5, OUTPUT);

  pinMode(m6p1, OUTPUT);
  pinMode(m6p2, OUTPUT);
  pinMode(EN6, OUTPUT);

  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  analogWrite(EN3, 255);
  analogWrite(EN4, 255);
  analogWrite(EN5, 255);
  analogWrite(EN6, 255);

  digitalWrite(m2p1,HIGH);
  digitalWrite(m2p2, LOW);
  delay(5000);

  pinMode(potentiometer, INPUT);

}

void loop() {

  value = analogRead(potentiometer);
  uint32_t period = map(value, 0, 255, 10000, 0); 



  digitalWrite(m1p1,HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m4p1,LOW);
  digitalWrite(m4p2, LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2, LOW);
  digitalWrite(m5p1,LOW);
  digitalWrite(m5p2, LOW);
  digitalWrite(m3p1,LOW);
  digitalWrite(m3p2, LOW);
  digitalWrite(m6p1,LOW);
  digitalWrite(m6p2, LOW);
  delay(time);

  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m4p1,LOW);
  digitalWrite(m4p2, LOW);
  digitalWrite(m2p1,HIGH);
  digitalWrite(m2p2, LOW);
  digitalWrite(m5p1,LOW);
  digitalWrite(m5p2, LOW);
  digitalWrite(m3p1,LOW);
  digitalWrite(m3p2, LOW);
  digitalWrite(m6p1,LOW);
  digitalWrite(m6p2, LOW);
  delay(time);

  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m4p1,LOW);
  digitalWrite(m4p2, LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2, LOW);
  digitalWrite(m5p1,LOW);
  digitalWrite(m5p2, LOW);
  digitalWrite(m3p1,HIGH);
  digitalWrite(m3p2, LOW);
  digitalWrite(m6p1,LOW);
  digitalWrite(m6p2, LOW);
  delay(time);

  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m4p1,HIGH);
  digitalWrite(m4p2, LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2, LOW);
  digitalWrite(m5p1,LOW);
  digitalWrite(m5p2, LOW);
  digitalWrite(m3p1,HIGH);
  digitalWrite(m3p2, LOW);
  digitalWrite(m6p1,HIGH);
  digitalWrite(m6p2, LOW);
  delay(time);

  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m4p1,LOW);
  digitalWrite(m4p2, LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2, LOW);
  digitalWrite(m5p1,HIGH);
  digitalWrite(m5p2, LOW);
  digitalWrite(m3p1,LOW);
  digitalWrite(m3p2, LOW);
  digitalWrite(m6p1,LOW);
  digitalWrite(m6p2, LOW);
  delay(time);

  digitalWrite(m1p1,LOW);
  digitalWrite(m1p2, LOW);
  digitalWrite(m4p1,LOW);
  digitalWrite(m4p2, LOW);
  digitalWrite(m2p1,LOW);
  digitalWrite(m2p2, LOW);
  digitalWrite(m5p1,LOW);
  digitalWrite(m5p2, LOW);
  digitalWrite(m3p1,HIGH);
  digitalWrite(m3p2, LOW);
  digitalWrite(m6p1,HIGH);
  digitalWrite(m6p2, LOW);
  delay(time);

  if (time > maxSpeed) {
    time = time - step;
  }
  else {
    time = maxSpeed;
  }
}
