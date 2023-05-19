#include "Arduino.h"
#include "VibrationPatterns.h"

/* 
* Duty cycle constants for vibration patterns in milliseconds.
* (The compiler should inline these, if not then constants should be hard coded in the functions)
*/
const int DUTY_CYCLE = 500;
const int HALF_CYCLE = DUTY_CYCLE/2;
const int QUARTER_CYCLE = DUTY_CYCLE/4;
const int TENTH_CYCLE = DUTY_CYCLE/10;
const int TWO_TENTHS_CYCLE = TENTH_CYCLE * 2;

void VibrationPatterns::shortPulse(int vibrationMotorPositivePin, int vibrationMotorNegativePin){
    currentTime = millis();
    deltaTime = currentTime - previousTime;
    if(deltaTime < TENTH_CYCLE){
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < TWO_TENTHS_CYCLE){
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else{
        previousTime = currentTime;
    }
}

//Pattern 1 is continuous vibration
void VibrationPatterns::pattern1(int vibrationMotorPositivePin, int vibrationMotorNegativePin){
    digitalWrite(vibrationMotorPositivePin, HIGH);
    digitalWrite(vibrationMotorNegativePin, LOW);
}

//Pattern 2 is a 50% duty cycle
void VibrationPatterns::pattern2(int vibrationMotorPositivePin, int vibrationMotorNegativePin){
    currentTime = millis();
    deltaTime = currentTime - previousTime;
    if(deltaTime < HALF_CYCLE){
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < DUTY_CYCLE){
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else{
        previousTime = currentTime;
    }
}

//Pattern 3 is a 25% duty cycle
void VibrationPatterns::pattern3(int vibrationMotorPositivePin, int vibrationMotorNegativePin){
    currentTime = millis();
    deltaTime = currentTime - previousTime;
    if(deltaTime < QUARTER_CYCLE){
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < DUTY_CYCLE){
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else{
        previousTime = currentTime;
    }
}

//Pattern 4 is a long pulse followed by a short pulse (30% on -> 10% off -> 10% on -> 10% off)
void VibrationPatterns::pattern4(int vibrationMotorPositivePin, int vibrationMotorNegativePin){
    currentTime = millis();
    deltaTime = currentTime - previousTime;
    if(deltaTime < TWO_TENTHS_CYCLE + TENTH_CYCLE){    //30% on
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < TWO_TENTHS_CYCLE + TWO_TENTHS_CYCLE){ //10% off
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < HALF_CYCLE){ //10% on
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < DUTY_CYCLE){
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else{
        previousTime = currentTime;
    }
}

//Pattern 5 is two short pulses followed by a long pulse (10% on -> 10% off -> 10% on -> 10% off -> 30% on)
void VibrationPatterns::pattern5(int vibrationMotorPositivePin, int vibrationMotorNegativePin){
    currentTime = millis();
    deltaTime = currentTime - previousTime;
    if(deltaTime < TENTH_CYCLE){    //10% on
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < TWO_TENTHS_CYCLE){ //10% off
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < TENTH_CYCLE + TWO_TENTHS_CYCLE){ //10% on
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < TWO_TENTHS_CYCLE + TWO_TENTHS_CYCLE){ //10% off
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < HALF_CYCLE + TWO_TENTHS_CYCLE){ //30% on
        digitalWrite(vibrationMotorPositivePin, HIGH);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else if(deltaTime < DUTY_CYCLE){
        digitalWrite(vibrationMotorPositivePin, LOW);
        digitalWrite(vibrationMotorNegativePin, LOW);
    }
    else{
        previousTime = currentTime;
    }
}