/*
  Author: 
  Learning Intention: The students will learn how to connect and control a servo motor.
  Success Criteria:
    1. I understand how to connect the servo motor
    2. I can manually write different degrees of movement to the servo
    3. I can map a potentiometer to a servo and control its movement
    4. I understand that a 180deg servo angle of movement is set by a frequency signal sent from the microcontroller

  Student Notes: 
to reset the servo to 0 degrees compile the lines:
  int val = 0;
  myServo.write(val);
  Documentation:
    https://www.sparkfun.com/servos
    https://github.com/arduino-libraries/Servo <-- We are still using this library

  Schematic:
    https://www.tinkercad.com/things/lQ9RyYJRoLn?sharecode=MKlN0A7R0WGodkdTRKkPJO7I8PeI5L_GCR7pCclQ0qM
    https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/10.servoMotor/Bootcamp-servoMotor.png
*/

//(THIS LINE IS WRONG REMOVE IT) The Servo-h library is built into Ardunio IDE there is no need to side load it like the Ultrasonic Sensor library

//this line loads the  servo
#include <Servo.h>
//creating a servo object
Servo myServo;

unsigned static int myServoPin = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("config@9600");
  Serial.println("------------------");

  //configures myServo to the pin
  myServo.attach(myServoPin);
}

// The loop function runs over and over again forever
void loop() {
  //reset servo to 0
  int val = 0;
  myServo.write(val);
  //delays are still bad generally but this is an example of when you can choose to use it
  delay(250);

  //slowly sweep the servo 180*
  for (int i=0; i<=180; i++){ //i<180 would not make servo spin 180*, i<= does
    myServo.write(i);
    delay(50);
  }
    for (int y=180; y<=0; y--){ //y<=0 again makes the servo spin the full 180*
    myServo.write(y);
    delay(50);
  }
}

