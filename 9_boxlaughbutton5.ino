/*
Morse code sheet: https://drive.google.com/file/d/1liBuEK5mu3E04ymCv_On7b9cEDAkBJO1/view
Color guide: https://www.rapidtables.com/web/color/RGB_Color.html

Challenges:
1) Wire the button and code it open when you press, and close when you don't press
2) Reverse #1
3) When you press the button, make it laugh.  When not pressed, just close.
4) Combine the potentiometer and button sensors to do something

*/

#include <Servo.h>

#define RED 3
#define BLUE 5
#define GREEN 6

int counter;
Servo myServo;

void setup() {
  
  
  pinMode(RED,OUTPUT); //- RED
  pinMode(BLUE,OUTPUT); //- BLUE
  pinMode(GREEN,OUTPUT); //- GREEN
  
  pinMode(2,INPUT_PULLUP); //- BUTTON PIN
  pinMode(4,OUTPUT); //-HEAD LED
  pinMode(7,OUTPUT); //-HEAD LED
  
  
  pinMode(9,OUTPUT);
  
  rgbOff();
  
  Serial.begin(9600);
  myServo.attach(9);
  
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

void rgbWithPotentiometer(int potentiometer) {
  
  if (potentiometer == 0) {
    rgbOff();
  }
  if (potentiometer > (146*1)) {
    rgbRed();
  }
  if (potentiometer > (146*2)) {
    rgbOrange();
  }
  if (potentiometer > (146*3)) {
    rgbYellow();
  }
  if (potentiometer > (146*4)) {
    rgbGreen();
  }
  if (potentiometer > (146*5)) {
    rgbBlue();
  }
  if (potentiometer > (146*6)) {
    rgbIndigo();
  }
  if (potentiometer > (146*7)) {
    rgbViolet();
  }
}

void rainbowFadePotentiometer() {
  
  int potentiometer;
  potentiometer = analogRead(A0);
  
  while (potentiometer == 0) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-red
  rgbFade(RED,0,255);
  rgbFade(BLUE,0,0);
  rgbFade(GREEN,0,0);
  
  while (potentiometer < (146*1)) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-orange
  rgbFade(RED,255,255);
  rgbFade(GREEN,0,205);
  rgbFade(BLUE,0,0);
  
  while (potentiometer < (146*2)) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-yellow
  rgbFade(RED,255,222);
  rgbFade(GREEN,205,255);
  rgbFade(BLUE,0,0);

  while (potentiometer < (146*3)) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-green
  rgbFade(RED,222,0);
  rgbFade(BLUE,0,0);
  rgbFade(GREEN,255,255);
  
  while (potentiometer < (146*4)) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-blue
  rgbFade(RED,0,0);
  rgbFade(BLUE,0,255);
  rgbFade(GREEN,255,0);
  
  while (potentiometer < (146*5)) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-indigo
  rgbFade(RED,0,0);
  rgbFade(GREEN,0,247);
  rgbFade(BLUE,255,255);
  
  while (potentiometer < (146*6)) {
    //-do nothing
    potentiometer = analogRead(A0);
  }
  
  //-violet
  rgbFade(RED,0,179);
  rgbFade(GREEN,247,0);
  rgbFade(BLUE,255,255);
  
  /*
  //-fade all off
  rgbFade(RED,179,0);
  rgbFade(GREEN,0,0);
  rgbFade(BLUE,255,0);

  delay(2000);

*/

}

void boxLaugh() {
  myServo.write(80); //-open 
  digitalWrite(7,HIGH);
  digitalWrite(4,HIGH);
  delay(200);
  
  myServo.write(0); //-close
  digitalWrite(7,LOW);
  digitalWrite(4,LOW);
  delay(200);
  
  
}

void loop() {
  
  int potentiometer;
  int counter;
  potentiometer = analogRead(A0);
  
  Serial.println(potentiometer);
  delay(100);
  
  
  if (digitalRead(2)==LOW) {
    //-open the box
    myServo.write(80);
    rgbOrange();
    digitalWrite(7,HIGH);
    digitalWrite(4,HIGH);
    
    counter=0;
    while (counter<5) {
      boxLaugh();
      counter++;
    }
    
  }
  else if (digitalRead(2)==HIGH) {
    // close the box
    myServo.write(0); //-close 
    rgbRed();
    digitalWrite(7,LOW);
    digitalWrite(4,LOW);
  }
  

}
