/*
Morse code sheet: https://drive.google.com/file/d/1liBuEK5mu3E04ymCv_On7b9cEDAkBJO1/view
*/

void setup() {
  pinMode(7,OUTPUT);
}

void dot() {
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100); 
}

void dash() {
  digitalWrite(7,HIGH);
  delay(300);
  digitalWrite(7,LOW);
  delay(100);
}


void loop() {

  // 3 dots
  dot();
  dot();
  dot();
  delay(1000);
  
  // 3 dashes
  dash();
  dash();
  dash();
  delay(1000);
  
  // 3 dots
  dot();
  dot();
  dot();
  delay(1000);
  
  delay(2000);
  
  
}
