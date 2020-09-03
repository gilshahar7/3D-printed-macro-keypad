#include <Arduino.h>

// ---------------------------------
// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20

// Pin definitions
#define BUTTON_PIN1 20
#define BUTTON_PIN2 21
#define BUTTON_PIN3 15
#define BUTTON_PIN4 18
#define BUTTON_PIN5 19
#define BUTTON_PIN6 10
#define BUTTON_PIN7 16
#define BUTTON_PIN8 14

byte oldVal = 0; // Used to compare volume levels
// ---------------------------------

#include "Keyboard.h"

// Button helper class for handling press/release and debouncing
class button {
public:
  const char key;
  const uint8_t pin;

  button(uint8_t k, uint8_t p) : key(k), pin(p){}

  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      return; // Nothing to see here, folks
    }

    lastPressed = millis();

    state ? Keyboard.press(key) : Keyboard.release(key);
    pressed = state;
  }

  void update(){
    press(!digitalRead(pin));
  }

private:
  const long debounceTime = 30;
  unsigned long lastPressed;
  boolean pressed = 0;
} ;

// Button objects, organized in array
button buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1},
  {BUTTON_KEY2, BUTTON_PIN2},
  {BUTTON_KEY3, BUTTON_PIN3},
  {BUTTON_KEY4, BUTTON_PIN4},
  {BUTTON_KEY5, BUTTON_PIN5},
  {BUTTON_KEY6, BUTTON_PIN6},
  {BUTTON_KEY7, BUTTON_PIN7},
  {BUTTON_KEY8, BUTTON_PIN8},
};

const uint8_t NumButtons = sizeof(buttons) / sizeof(button);
const uint8_t ledPin = 17;


void failsafe(){
  for(;;){} // Just going to hang out here for awhile :D
}

void setup() {
  Serial.begin(9600);
  int sensorValue = analogRead(A9); //read the input on analog pin 0

  oldVal = map(sensorValue, 0, 1022, 1, 51);
  // Safety check. Ground pin #1 (RX) to cancel keyboard inputs.
  pinMode(1, INPUT_PULLUP);
  if(!digitalRead(1)){
    failsafe();
  }

  // Set LEDs Off. Active low.
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  TXLED0;

  for(int i = 0; i < NumButtons; i++){
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop() {
  for(int i = 0; i < NumButtons; i++){
    buttons[i].update();
  }

  //VOLUME
  int sensorValue = analogRead(A9); //read the input on analog pin 0
  byte mappedValue = map(sensorValue, 0, 1023, 0, 101);


  if( 3 < (mappedValue - oldVal) || (mappedValue - oldVal) < -3){
    Serial.print("Mapped value is: ");
    Serial.println(mappedValue);
    if (mappedValue <= 3) {
      Serial.println("0");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F13);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 7) {
      Serial.println("4");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F14);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 11) {
      Serial.println("8");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F15);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 15) {
      Serial.println("12");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F16);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 19) {
      Serial.println("16");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F17);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 23) {
      Serial.println("20");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F18);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 27) {
      Serial.println("24");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F19);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 31) {
      Serial.println("28");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F20);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 35) {
      Serial.println("32");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F21);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 39) {
      Serial.println("36");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F22);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 43) {
      Serial.println("40");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F23);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 47) {
      Serial.println("44");
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F24);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 51) {
      Serial.println("48");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F13);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 55) {
      Serial.println("52");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F14);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 59) {
      Serial.println("56");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F15);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 63) {
      Serial.println("60");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F16);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 67) {
      Serial.println("64");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F17);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 71) {
      Serial.println("68");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F18);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 75) {
      Serial.println("72");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F19);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 79) {
      Serial.println("76");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F20);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 83) {
      Serial.println("80");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F21);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 87) {
      Serial.println("84");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F22);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 91) {
      Serial.println("88");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F23);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 94) {
      Serial.println("92");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.write(KEY_F24);
      Keyboard.release(KEY_LEFT_CTRL);
    }
    else if (mappedValue <= 97) {
      Serial.println("96");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F13);
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (mappedValue <= 101) {
      Serial.println("100");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.write(KEY_F14);
      Keyboard.release(KEY_LEFT_CTRL);
      Keyboard.release(KEY_LEFT_ALT);
    }

    oldVal = mappedValue;
  }



}
