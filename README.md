# CREST Motor Code
 
This code runs a DIY brushless DC motor. It is uploaded into an Arduino nano. Controlling 6 different H-Bridges (2 per 1 board) to control 6 different electromagnets which drive the rotor.

The H-Bridges take in 3 inputs each.

*EN pins - There is **1** EN pin per H-Bridge. These control the voltage going through the H-Bridge. 0 being none and 255 meaning the full voltage. Thus they need to be controlled using `analogWrite(enablepin,value)`

*IN pins - There are **2** IN pins per H-Bridge. These can be used to control the polarity of the electromagnet by changing the direction of the current. This can be done by using `digitalWrite(inpin,HIGH/LOW)`. For example if you want the current to go one way you can do:
```
digitalWrite(m1p1,HIGH);
digitalWrite(m1p2,LOW);
```
or the other way:
```
digitalWrite(m1p1,LOW);
digitalWrite(m1p2,HIGH);
```

We also have a potentiometer connected to the Arduino, this changes the speed of the motor.
