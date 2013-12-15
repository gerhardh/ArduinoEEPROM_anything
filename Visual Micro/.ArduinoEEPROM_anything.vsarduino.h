//Board = Arduino Uno
#define __AVR_ATmega328P__
#define ARDUINO 105
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

//
//
void serialEvent();
void runTest();

#include "D:\applications\arduino-1.0.5\hardware\arduino\variants\standard\pins_arduino.h" 
#include "D:\applications\arduino-1.0.5\hardware\arduino\cores\arduino\arduino.h"
#include "D:\projects-arduino\ArduinoEEPROM_anything\ArduinoEEPROM_anything.ino"
#include "D:\projects-arduino\ArduinoEEPROM_anything\EEPROMAnything.h"
