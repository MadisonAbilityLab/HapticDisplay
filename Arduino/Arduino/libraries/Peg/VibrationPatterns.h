/*
* Author: James Wedum
* Date: 5/17/2023
*
* Description: This file contains the definitions for the various virbration patterns that can be used.
*/

#ifndef VibrationPatterns_h
#define VibrationPatterns_h

#include "Arduino.h"

class VibrationPatterns{
    public:
        void play(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        

    private:
        unsigned long currentTime;
        unsigned long previousTime;
        unsigned long deltaTime;
        int patternNumber;
        void pattern1(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        void pattern2(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        void pattern3(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        void pattern4(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        void pattern5(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        void shortPulse(int vibrationMotorPositivePin, int vibrationMotorNegativePin);
        void longPulse(int vibrationMotorPositivePin, int vibrationMotorNegativePin);

};

#endif