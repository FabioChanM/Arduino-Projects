int ledrojo=2 ;
int ledblanco=3;
int ledverde=4;


void setup() {
 pinMode(ledrojo, OUTPUT);
  pinMode(ledblanco, OUTPUT);
   pinMode(ledverde, OUTPUT);
   digitalWrite (ledrojo, LOW);
   digitalWrite (ledblanco, LOW);
   digitalWrite (ledverde, LOW);
}

void loop() {
  delay(1000);
 digitalWrite (ledrojo, HIGH);

 delay(2000);
 digitalWrite (ledrojo, LOW);
digitalWrite (ledblanco, HIGH);
delay(3000);
digitalWrite (ledblanco, LOW);
digitalWrite (ledverde, HIGH);
delay(2000);
 digitalWrite (ledverde, LOW);
}
