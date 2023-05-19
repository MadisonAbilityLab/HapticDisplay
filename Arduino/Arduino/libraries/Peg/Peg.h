/*
* Author: James Wedum
* Date: 5/17/2023
*
* Description: This file contains the definitions for individual pins in the haptic array. 
*/

#ifndef Peg_h
#define Peg_h

#include "Arduino.h"
#include "VibrationPatterns.h"

// Pin definitions
class Peg{
    private:
        int vibrationMotorPositivePin;  
        int vibrationMotorNegativePin; 

        int servoMotorEnablePin;
        int servoMotorDirectionPin;

        int row;
        int column;

        VibrationPatterns vibrationPattern;

        boolean touched;
        boolean moving;
        boolean vibrating;

        double verticalDisplacement;
        double tagetPosition;

        void moveUp();
        void moveDown();
        void setDisplacement(double verticalDisplacement);

        unsigned long currentTime;
        unsigned long previousTime;
        unsigned long deltaTime;

    public:
        Peg(int vibrationMotorPositivePin, int vibrationMotorNegativePin, int servoMotorEnablePin, int servoMotorDirectionPin, int row, int column);
        void begin();
        void playVibrationPattern();
        void setVibrationPattern(int vibrationPattern);
        void setTargetPosition(double position);
        void setTouched(boolean touched);
        boolean isTouched();
        boolean isMoving();
        boolean isVibrating();
        double getDisplacement();
        int getRow();
        int getColumn();
        void update();
};


#endif