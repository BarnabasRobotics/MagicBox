/*
Morse code sheet: https://drive.google.com/file/d/1liBuEK5mu3E04ymCv_On7b9cEDAkBJO1/view
Color guide: https://www.rapidtables.com/web/color/RGB_Color.html

Challenges:
1) Test Potiometer by reading it out on Serial Monitor
2) Fade red light using potentiometer (resolution=3)
3) Fade red light using potentiometer (resolution=6);
4) Fade red light using potentiometer (resolution=10);
5) Change colors of RGB based on potentiometer
6) Change (digital) through rainbow colors as you turn the potentiomter
7) Fade (analog) through rainbow as you turn the potentiometer

*/

#define RED 3
#define BLUE 5
#define GREEN 6

int counter;

void setup() {
  
  pinMode(RED,OUTPUT); //- RED
  pinMode(BLUE,OUTPUT); //- BLUE
  pinMode(GREEN,OUTPUT); //- GREEN
  pinMode(7,OUTPUT);
  
  rgbOff();
  
  Serial.begin(9600);
  
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
  analogWrite(RED,0);
  analogWrite(BLUE,0);
  analogWrite(GREEN,0); 
}


void rgbRed() {
  analogWrite(RED,255);
  analogWrite(BLUE,0);
  analogWrite(GREEN,0);
}

void rgbBlue() {
  analogWrite(RED,0);
  analogWrite(BLUE,255);
  analogWrite(GREEN,0);
}

void rgbGreen() {
  analogWrite(RED,0);
  analogWrite(BLUE,0);
  analogWrite(GREEN,255);
}

void rgbOrange() {
  analogWrite(RED,255);
  analogWrite(GREEN,205);
  analogWrite(BLUE,0);
}

void rgbYellow() {
  analogWrite(RED,222);
  analogWrite(GREEN,255);
  analogWrite(BLUE,0);
}

void rgbIndigo() {
  analogWrite(RED,0);
  analogWrite(GREEN,247);
  analogWrite(BLUE,255);
}

void rgbViolet() {
  analogWrite(RED,179);
  analogWrite(GREEN,0);
  analogWrite(BLUE,255);
}

void rgbFade(int color,int startValue, int endValue) {
  
  int counter;
  
  if (startValue < endValue) {
    //- increment 
    counter = startValue;
    while (counter <= endValue) {
      analogWrite(color,counter);
      counter = counter + 1;
      delay(20);
    }
  }
  
  if (startValue > endValue) {
    //- decrement
    counter = startValue;
    while (counter >= endValue) {
      analogWrite(color,counter);
      counter = counter - 1;
      delay(20);
    }
    
  }
}

void rainbowFade() {
  
  //-red
  rgbFade(RED,0,255);
  rgbFade(BLUE,0,0);
  rgbFade(GREEN,0,0);
  
  //-orange
  rgbFade(RED,255,255);
  rgbFade(GREEN,0,205);
  rgbFade(BLUE,0,0);
  
  //-yellow
  rgbFade(RED,255,222);
  rgbFade(GREEN,205,255);
  rgbFade(BLUE,0,0);
  
  //-green
  rgbFade(RED,222,0);
  rgbFade(BLUE,0,0);
  rgbFade(GREEN,255,255);
  
  //-blue
  rgbFade(RED,0,0);
  rgbFade(BLUE,0,255);
  rgbFade(GREEN,255,0);
  
  //-indigo
  rgbFade(RED,0,0);
  rgbFade(GREEN,0,247);
  rgbFade(BLUE,255,255);
  
  //-violet
  rgbFade(RED,0,179);
  rgbFade(GREEN,247,0);
  rgbFade(BLUE,255,255);
  
  //-fade all off
  rgbFade(RED,179,0);
  rgbFade(GREEN,0,0);
  rgbFade(BLUE,255,0);

  delay(2000);

}

void loop() {
  
  int potentiometer;
  potentiometer = analogRead(A0);
  
  Serial.println(potentiometer);
  delay(100);
  
  if (potentiometer == 0) {
    analogWrite(RED,0);
  }
  if (potentiometer > 500) {
    analogWrite(RED,128);
  }
  if (potentiometer > 1000) {
    analogWrite(RED,255);
  }
  
  
  
  
  
}
