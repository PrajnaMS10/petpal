const int trigPin = 9;//transmission of the wave
const int echoPin = 10;//Return of the wave
const int trigPi = 7;
const int echoPi = 8;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,  16, 2); //tells address 

long duration;
int distance;
long duration2;
int distance2;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPi, OUTPUT);
pinMode(echoPi, INPUT);
Serial.begin(9600);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.init();
lcd.backlight();
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);


digitalWrite(trigPi, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPi, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPi, LOW);
  duration2 = pulseIn(echoPi, HIGH);
  distance2= duration2*0.034/2;
  Serial.print("Distance2: ");
  Serial.println(distance2);
  delay(100);

if(distance<10)
{
lcd.setCursor(0,0); //set the cursor to column 0 and line 1
lcd.print(distance);
lcd.print("cm");
lcd.setCursor(3,0);
lcd.print(" ");
}
else if(distance>=10 && distance<100)
{
lcd.setCursor(0,0); //set the cursor to column 0 and line 1
lcd.print(distance);
lcd.print("cm");
lcd.setCursor(4,0);
lcd.print(" ");
}
else
{
  lcd.setCursor(0,0); //set the cursor to column 0 and line 1
  lcd.print(distance);
  lcd.print("cm");
}

if(distance2<10)
{
lcd.setCursor(0,1); //set the cursor to column 0 and line 1
lcd.print(distance2);
lcd.print("cm");
lcd.setCursor(3,1);
lcd.print(" ");
}
else if(distance2>=10 && distance2<100)
{
lcd.setCursor(0,1); //set the cursor to column 0 and line 1
lcd.print(distance2);
lcd.print("cm");
lcd.setCursor(4,1);
lcd.print(" ");
}
else
{
  lcd.setCursor(0,1); //set the cursor to column 0 and line 1
lcd.print(distance2);
lcd.print("cm");
}

}