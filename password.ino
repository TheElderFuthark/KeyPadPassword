#include <string.h>
#include <Wire.h>
#include <Keypad.h>


using namespace std;


const int LED_RED = 13;
const int LED_GREEN = 2;

const int MILLI = 2000;
const int MILLI_SHORT = 500;

const byte ROWS = 4;
const byte COLS = 4;

const String PASSWORD = "1234";
char KEY_PAD[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

byte pinsRow[ROWS] = {12, 11, 10, 9};
byte pinsCol[COLS] = {8, 7, 6, 5};

Keypad keyPad = Keypad(makeKeymap(KEY_PAD), 
  pinsRow, 
  pinsCol, 
  ROWS, 
  COLS
);

String keyCurrent = "";
String enterPassword = "";


void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  Serial.begin(9600);
}


void loop() { 
  while(true) {
    keyCurrent = keyPad.getKey();

    if(keyCurrent == "#") {
      break; 
    } else {
      enterPassword += keyCurrent;
    } 
    
  }
    
    
  if(enterPassword == PASSWORD) {
    for(int x = 0; x < 4; x++) {
      digitalWrite(LED_GREEN, HIGH);
      delay(MILLI_SHORT);
            
      digitalWrite(LED_GREEN, LOW);
      delay(MILLI_SHORT);
    } 
  } else {
    digitalWrite(LED_RED, HIGH);
    delay(MILLI);
 
    digitalWrite(LED_RED, LOW);
    delay(MILLI_SHORT);
  }


  if(sizeof(enterPassword) >= 1) {
    enterPassword = "";
    keyCurrent = "";
  }

}
