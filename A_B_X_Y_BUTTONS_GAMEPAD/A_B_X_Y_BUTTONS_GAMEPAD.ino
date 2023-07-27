#include <Arduino.h>
#include <BleGamepad.h> 

BleGamepad bleGamepad;
BleGamepadConfiguration bleGamepadConfig;

void setup() {
  // put your setup code here, to run once:

  bleGamepadConfig.setAutoReport(false);
  bleGamepadConfig.setControllerType(CONTROLLER_TYPE_GAMEPAD);
  bleGamepad.begin(&bleGamepadConfig);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  if (bleGamepad.isConnected()) {
    
  if (digitalRead(13) == HIGH){
    digitalWrite(2,HIGH);
    bleGamepad.press(BUTTON_5);
    bleGamepad.sendReport();
  }else{
    bleGamepad.release(BUTTON_5);
    bleGamepad.sendReport();
    digitalWrite(2,LOW);
  }

  if (digitalRead(12) == HIGH){
    digitalWrite(2,HIGH);
    bleGamepad.press(BUTTON_2);
    bleGamepad.sendReport();
  }else{
    bleGamepad.release(BUTTON_2);
    bleGamepad.sendReport();
    digitalWrite(2,LOW);
  }

  if (digitalRead(14) == HIGH){
    digitalWrite(2,HIGH);
    bleGamepad.press(BUTTON_4);
    bleGamepad.sendReport();
  }else{
    bleGamepad.release(BUTTON_4);
    bleGamepad.sendReport();
    digitalWrite(2,LOW);
  }

  if (digitalRead(32) == HIGH){
    digitalWrite(2,HIGH);
    bleGamepad.press(BUTTON_1);
    bleGamepad.sendReport();
  }else{
    bleGamepad.release(BUTTON_1);
    bleGamepad.sendReport();
    digitalWrite(2,LOW);
  }


  }

  
//  Serial.print("13 - ");
//  Serial.println(digitalRead(13));
//  Serial.print("12 - ");
//  Serial.println(digitalRead(12));
//  Serial.print("14 - ");
//  Serial.println(digitalRead(14));
//  Serial.print("32 - ");
//  Serial.println(digitalRead(32));
//
//  delay(1000);

}
