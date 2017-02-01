#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_TEMPERATURE_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>


#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/* Reserve a byte for Temperature value. */
int tempValue = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  printNew("OneSheeld init...",0);
  /* Start communication. */
  OneSheeld.begin();
  delay(1000);
  printNew("Successful!",0);
  delay(1000);
  printNew("Get Temp.", 1);
  delay(3000);
}

void loop() {
  /* Always get Temperature sensor value. */
  tempValue = TemperatureSensor.getValue();

  printValues("Temperature:", tempValue);
  
  Terminal.println(tempValue);
}




void printNew(String buff, int vert_position) {
  lcd.clear();

  if (vert_position % 2 == 0) {
    vert_position = 0;
  } else {
    vert_position = 1;
  }

  
  lcd.setCursor(0, vert_position);
  lcd.print(buff);
}
void printNew(String buff, int hor_position, int vert_position) {
  
  lcd.clear();

  if (vert_position % 2 == 0) {
    vert_position = 0;
  } else {
    vert_position = 1;
  }
  if ((hor_position > 16) || (hor_position < 0)) {
    vert_position = 0;
  } 
  lcd.setCursor(hor_position, vert_position);
  lcd.print(buff);
}
void printValues(String buff1, String buff2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(buff1);
  lcd.setCursor(5,0);
  lcd.print(buff2);
}

void printValues(String buff1, int buff2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(buff1);
  lcd.setCursor(14,1);
  lcd.print(buff2, DEC);
  delay(500);
}

