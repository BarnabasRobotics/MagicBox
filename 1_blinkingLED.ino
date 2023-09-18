/*
Challenges:
1) See how fast you can get the light to blink
*/

void setup() {
  pinMode(7,OUTPUT);
}

void loop() {

  digitalWrite(7,HIGH);
  delay(2000);
  digitalWrite(7,LOW);
  delay(2000);
  
  digitalWrite(7,HIGH);
  delay(200);
  digitalWrite(7,LOW);
  delay(200);
  
  delay(2000);
  
  
}
