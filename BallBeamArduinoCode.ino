
// note: for my beam to be horizontal, Servo Motor angle should be 102 degrees.







#include<Servo.h>
#include<PID_v1.h>

const int servoPin = 9; //Servo Pin

float Kp = 0.2; //Initial Proportional Gain
float Ki = 0; //Initial Integral Gain
float Kd = 0.5; //Intitial Derivative Gain
double Setpoint, Input, Output, ServoOutput;



PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT); //Initialize PID object, which is in the class PID.




Servo myServo; //Initialize Servo.


void setup()
{

Serial.begin(9600); //Begin Serial
myServo.attach(servoPin); //Attach Servo

Input = readPosition(); //Calls function readPosition() and sets the balls
// position as the input to the PID algorithm



myPID.SetMode(AUTOMATIC); //Set PID object myPID to AUTOMATIC
myPID.SetOutputLimits(-90,90); //Set Output limits to -80 and 80 degrees.
}

void loop()
{

Setpoint = 20;
Input = readPosition();

myPID.Compute(); //computes Output in range of -80 to 80 degrees

ServoOutput=100+Output; // 102 degrees is my horizontal
myServo.write(ServoOutput); //Writes value of Output to servo


}





float readPosition() {
delay(10); //Don't set too low or echos will run into eachother.



const int pingPin = 11; //Trig Pin Arduino 7
const int pingPin2 = 12; //Echo Pin Arduino 6


long duration, cm;
unsigned long now = millis();
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);


pinMode(pingPin, INPUT);
duration = pulseIn(pingPin2, HIGH);

cm = duration/(29*2);






if(cm > 35) // 30 cm is the maximum position for the ball // make 35
{cm=30;} // make 30


Serial.println(cm);

return cm; //Returns distance value.
}
