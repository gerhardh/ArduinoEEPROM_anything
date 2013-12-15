#include "EEPROMAnything.h"

struct config_t
{
	long test; 
} configuration;

String inputCommand = "";
boolean inputComplete = false;

void setup()
{
	Serial.begin(19200);		
	inputCommand.reserve(200);
	
	Serial.println("Ready! Please send 'test' to run eeprom test.");
}

void loop()
{
	 if (inputComplete) 
	 {		 
		 Serial.print("inputCommand=");
		 Serial.println(inputCommand);
		 inputCommand.trim();
		 if (inputCommand == "test")
		 {
			 runTest();
		 }		 		 		 
		 inputCommand = "";
		 inputComplete = false;
	 }
}

void serialEvent() 
{
	while (Serial.available()) 
	{		
		char inChar = (char)Serial.read();		
		inputCommand += inChar;		
		if (inChar == '\n') 
		{
			inputComplete = true;
		}
	}
}
/*
 * Run eeprom test
 */
void runTest()
{
	Serial.println("start eeprom test");
	
	configuration.test = 123;
	
	EP_READ_BLOCK(0, configuration);
	
	Serial.print("first read => test=");
	Serial.println(configuration.test);
	
	configuration.test = 123;
	
	EP_WRITE_BLOCK(0, configuration);
	delay(500);
	EP_READ_BLOCK(0, configuration);
	
	Serial.print("after saved => test=");
	Serial.println(configuration.test);
	
	Serial.println("end eeprom test");
}