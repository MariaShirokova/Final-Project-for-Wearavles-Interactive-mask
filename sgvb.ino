#include <Adafruit_Circuit_Playground.h>
#include <Servo.h>
#include <SPI.h>
#include <AP_Sync.h>
AP_Sync sendData(Serial);
#include <CapacitiveSensor.h>
#define CAP_THRESHOLD  500
#define DEBOUNCE 500


uint16_t value2;


int led = 6;
int led1 = 0;
int led2 = 12;
Servo myservo;
int angle = 0; 

float value;
///////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

   myservo.attach(10);
   
   pinMode(led, OUTPUT); // Declare the LED as an output
   pinMode(led1, OUTPUT); // Declare the LED as an output
   pinMode(led2, OUTPUT); // Declare the LED as an output// attaches the servo on digital pin 9 to the servo object

}

///////////////////////////////////////////////////////////////////////////////
void loop() {
 CircuitPlayground.clearPixels();
value = CircuitPlayground.mic.soundPressureLevel(20);

  

  if (value < 76) {
  for (angle = 0; angle < 0; angle += 0) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(angle);              // tell servo to go to position in variable 'pos'
    delay(15);                     // waits 15ms for the servo to reach the position
  }
  }
else {
    for  (angle = 0; angle < 180; angle += 1) { 
    // in steps of 1 degree
    myservo.write(angle);             
    delay(15);  
    }
}

  if (value2>5) {
  CircuitPlayground.setPixelColor(0, 255,   0,   0);
  CircuitPlayground.setPixelColor(1, 255, 128,   0);
  CircuitPlayground.setPixelColor(2,   255, 0,   0);
  CircuitPlayground.setPixelColor(3,  255, 0, 128);
  CircuitPlayground.setPixelColor(4,   255,   0, 0);
  
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  CircuitPlayground.setPixelColor(6, 0x808000);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x0000FF);


value2 = analogRead(5);
  Serial.println(value2);
  delay(100);
  
 digitalWrite(led, HIGH) ;
 digitalWrite(led1, HIGH) ;
digitalWrite(led2 , HIGH) ;
  }
  else {
     digitalWrite(led, LOW) ;
      digitalWrite(led1, LOW) ;
   digitalWrite(led2 , LOW) ;
  }
   Serial.print(value2);
  // print a comma to separate the values
  Serial.print(",");
  
 
  
}
