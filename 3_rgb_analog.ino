/*
Morse code sheet: https://drive.google.com/file/d/1liBuEK5mu3E04ymCv_On7b9cEDAkBJO1/view

Challenges:
1) Make police car light pattern
2) Red Blink, Green Blink, Blue Blink
3) Colors of the rainbow (ROYGBIV)

Color guide: https://www.rapidtables.com/web/color/RGB_Color.html
*/

#define RED 3
#define BLUE 5
#define GREEN 6

void setup() {
  
  pinMode(RED,OUTPUT); //- RED
  pinMode(BLUE,OUTPUT); //- BLUE
  pinMode(GREEN,OUTPUT); //- GREEN
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

void rgbOff() {
  digitalWrite(RED,LOW);
  digitalWrite(BLUE,LOW);
  digitalWrite(GREEN,LOW); 
}


void loop() {
  analogWrite(RED,255);
  analogWrite(BLUE,0);
  analogWrite(GREEN,255);
  
}
