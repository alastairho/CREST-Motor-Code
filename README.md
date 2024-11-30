# CREST Motor Code
 
This code runs a DIY brushless DC motor. It is uploaded into an Arduino nano. Controlling 6 different H-Bridges (2 per 1 board) to control 6 different electromagnets which drive the rotor.

The H-Bridges take in 3 inputs each.

- EN pins - There is **1 EN pin per H-Bridge**. These are **enable pins**. They control the voltage going through the H-Bridge. 0 being none and 255 meaning the full voltage. Thus they need to be controlled using `analogWrite(enablepin,value)`

- IN pins - There are **2 IN pins per H-Bridge**. Lets calls these **input pins**. These can be used to control the polarity of the electromagnet by changing the direction of the current. This can be done by using `digitalWrite(inpin,HIGH/LOW)`. For example if you want the current to go one way you can do:
```
digitalWrite(MOTOR1_IN1,HIGH);
digitalWrite(MOTOR1_IN2,LOW);
```
or the other way:
```
digitalWrite(MOTOR1_IN1,LOW);
digitalWrite(MOTOR1_IN2,HIGH);
```

In the code I have named the enable pins `ENABLE#` and the input pins `MOTOR#_IN#` # being a number.

We also have a potentiometer connected to the Arduino, this changes the speed of the motor.
