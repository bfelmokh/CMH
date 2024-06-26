/*
  LiquidCrystal Library - Hello World

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 url: https://www.tinkercad.com/things/b2wqoxpBhVR-copy-of-lcd-without-pot/editel?tenant=circuits
 * A pin to 5v / 220ohm
 * K pin to GND
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC/vdd pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3) - 1k/440ohm

  http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
#include <DHT.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht11_1(6,DHT11);

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht11_1.begin();
}
float getTemp(DHT dht_temp){
    float tempC = dht_temp.readTemperature();
    if (isnan(tempC)){
      Serial.println("\n Failed to read temperature from DHT sensor!");
    } else {
      Serial.print("Temperature: ");
      Serial.print(tempC);
      Serial.print("°C");
      return(tempC);
    }
    return(0);
}
float getHumi(DHT dht_humi){
    float humi = dht_humi.readHumidity();
    if (isnan(humi)){
      Serial.println("\n Failed to read humidity from DHT sensor!");
    } else {
      Serial.print(" Humidity: ");
      Serial.print(humi);
      Serial.println("%");
      return(humi);
    }
    return(0);
}
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print( "hello");
  lcd.setCursor(1,1);
  lcd.print("Mecatronique !");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(1,1);
  lcd.print(getTemp(dht11_1));
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidite: ");
  lcd.setCursor(1,1);
  lcd.print(getHumi(dht11_1));
  delay(2000);
  lcd.clear();

}
 