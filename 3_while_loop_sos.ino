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

  int counter;
  counter = 0;
  
  //- 3 dots
  while (counter < 3) {
    dot();
    counter = counter + 1;
  }
  delay(1000);
  
  
  counter = 0;
  // 3 dashes
  while (counter < 3) {
    dash();
    counter = counter + 1;
  }
  delay(1000);
  
  counter = 0;
  //- 3 dots
  while (counter < 3) {
    dot();
    counter = counter + 1;
  }
  delay(1000);
  
  delay(2000);
  
  
}
