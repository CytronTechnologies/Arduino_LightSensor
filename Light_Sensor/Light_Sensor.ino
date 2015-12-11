/*
  Modify from Liquid Crystal example
  For Light Sensor
  Using BBFuino from Cytron Technologies with 8x2 character LCD
  If you have inquiry, welcome to discuss in our technical forum: forum.cytron.com.my
  
  The circuit:
 * 8x2 character LCD to BBFuino
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Light Sensor module to BBFuino
 *VCC to 5V 
 *GND to GND
 *DO to D2
 *AO to AO
 */
  
// include the library code:
#include <LiquidCrystal.h>

#define Analog  A0  //Analog output of Light Sensor Module connected to A0 of BBFuino
#define Digital 2   //Digital Output of Light Sensor Module connected to D2 of BBfuino
#define LED     13  //LED at D13 pin

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //assign the LCD interface pin

//Global variable
int AnalogValue = 0;  //to store analog value

void setup() {
  //setup the input or output pin
  pinMode(LED, OUTPUT);
  pinMode(Digital, INPUT);
  pinMode(Analog, INPUT);
  digitalWrite(LED, LOW);  //off LED  
  // set up the LCD's number of columns and rows: 
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.print("Light");
  lcd.setCursor(0,1);
  lcd.print("Sensor");
  delay(1000);  //delay for 1 second
  lcd.clear();
  lcd.print("AN:");
  lcd.setCursor(0,1); //2nd line
  lcd.print("Di:");
}

void loop() {
  AnalogValue = analogRead(Analog);
  //display analog value from light sensor 
  lcd.setCursor(3, 0);  //set LCD cursor to be after AN:
  lcd.print(AnalogValue);  //display the ADC value from AO of light sensor
  lcd.print("   ");    //clear the previous printed value if have
  
  //display digital status
  lcd.setCursor(3, 1);
  if(digitalRead(Digital) == 1) // if digital input is high
  {
    lcd.print(1);
    digitalWrite(LED,HIGH);
  }
  else 
  {
    lcd.print(0); 
    digitalWrite(LED,LOW);
  }
  delay(300);
}

