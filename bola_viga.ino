#include <Ultrasonic.h>
#include <Servo.h>
#include <PID_v1.h>


const int servoPin = 9;

float Kp= 2.5;
float Ki= 0.2;
float Kd= 0.7;

double Setpoint, Input, Output, ServoOutput;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
Servo myServo;
Ultrasonic ultrasonio (12,11);

void setup() {
int b;
Serial.begin(9600);
myServo.attach(servoPin);
int a = Ultrasonic.Ranging(CM);
if (a! = 51){
  a = b;
}

Input = b;
myPID.SetMode(AUTOMATIC);
myPID.SetOutputLimits (-90,90);

}

void loop() {

int ultima;
Setpoint = 5;
Serial.print(Ultrasonic.Ranging(CM));
int a = Ultrasonic.Ranging(CM);
if (a! = 51){
  b = a;
}

else {
  b = ultima;
}
Input = b;
myPID.Compute();
ServoOutput = 90+Output;
myServo.write(ServoOutput);
ultima = b;

}
