/*
Final Project Spring 2019
Author: Justin Szaro
*/
//Downloads the library for the LCD Screen
#include <LiquidCrystal.h>
//Initializes the LCD screen and sets the pin numbers.
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
//Sets the speakers pin to pin 7.
const int speakerPin = 7;
//Sets the on/off button to pin 6
const int onOffButtonPin = 6;
//Sets the change note button to pin 9.
const int changeNoteButtonPin = 9;
//Initialzies the changeNoteButtonState variable and sets it to 0.
int changeNoteButtonState = 0;
//Initializes the onOffButtonState variable and sets it to 0.
int onOffButtonState = 0;
//Sets are varible i to 0. It will be used to iterate a loop later.
int i = 0;
//Makes a list of Strings with the notes on a guitar.
String notes[] = {"E2", "A2", "D3", "G3", "B3", "E4"};
//Makes a list of doubles with the frequencies that correspond with the notes on a guitar.
double frequencies[] = {82.41, 110.00, 146.83, 196.00, 246.94, 329.63};
void setup() {
 //Makes the speakerPin an output.
 pinMode(speakerPin, OUTPUT);
 //Makes the onOffButtonPin an input.
 pinMode(onOffButtonPin, INPUT);
 //Makes the onOffButtonPin an input.
 pinMode(changeNoteButtonPin, INPUT);
 //Startes the LCD with 2 columns and 20 rows.
 lcd.begin(2, 20);
 //Clears the lcd screen of any data.
 lcd.clear();
}
void loop() {
 //Reads the state of the onOffButton
 onOffButtonState = digitalRead(onOffButtonPin);
 //If the button is pushed
 if (onOffButtonState == HIGH) {
 //Shut off the speaker
 noTone(speakerPin);
 //Stops the program for 3 seconds.
 delay(3000);
 //Reads the state of the onOffButton
 onOffButtonState = digitalRead(onOffButtonPin);
 //If the button is pushed
 if (onOffButtonState == HIGH) {
 //Set the speakers tone to the current note's frequency
 tone(speakerPin, frequencies[i - 1]);
 //Stop the program for three seconds.
 delay(3000);
 }
 }
 //Reads the state of the change note button
 changeNoteButtonState = digitalRead(changeNoteButtonPin);
 //if the change note button is pushed
 if (changeNoteButtonState == HIGH) {
 //set the tone of the speaker to the frequency of the current note
 tone(speakerPin, frequencies[i]);
 //Clears the LCD Screen
 lcd.clear();
 //Sets the cursor to the first row of the first column.
 lcd.setCursor(0, 0);
 //Makes a new string by concatinating "Note: " with the name of the current note.
 String string1 = "Note: " + notes[i];
 //Prints out the string "Note: " and prints out the current note name on the LCD screen
 lcd.print(string1);
 //Sets the cursor to the first row.
 lcd.setCursor(0, 1);
 //Makes a new string by concatinating "Frequency: " with the current frequency of the note.
 String string2 = "Frequency: " + String(frequencies[i]);
 //Prints the created string onto the LCD.
 lcd.print(string2);
 //Iterates the variable i.
 i = i + 1;
 //If the variable i has a value greater than 5.
 if (i > 5) {
 //Set variable i to 0.
 i = 0;
 }
 //Stop the program for half a second.
 delay(500);
 //Read the state of the changeNoteButton
 changeNoteButtonState = digitalRead(changeNoteButtonPin);
 }

}
