#include "Arduino.h"
#include "Peg.h"
#include "VibrationPatterns.h"

/*
* This is the "play" of the displacement. It is the threshold for when the peg is considered to be at the target position.
* This is a constant that should be tuned to the specific hardware.
* Setting too high may cause the peg to oscillate.
* Setting too low may cause the peg to never reach the target position.
*/
const int DISPLACEMENT_THRESHOLD = .1;

/*
* Constructor for the peg.
*/
Peg::Peg(int vibrationMotorPositivePin, int vibrationMotorNegativePin, int servoMotorEnablePin, int servoMotorDirectionPin, int row, int column){
    this->vibrationMotorPositivePin = vibrationMotorPositivePin;
    this->vibrationMotorNegativePin = vibrationMotorNegativePin;
    this->servoMotorEnablePin = servoMotorEnablePin;
    this->servoMotorDirectionPin = servoMotorDirectionPin;
    this->row = row;
    this->column = column;
    VibrationPatterns vibrationPattern;
    this->touched = false;
    this->moving = false;
    this->verticalDisplacement = 0;
}

/*
* Sets up the pins for the peg. This should be called by the setup function.
*/
void Peg::begin(){
    pinMode(vibrationMotorPositivePin, OUTPUT);
    pinMode(vibrationMotorNegativePin, OUTPUT);
    pinMode(servoMotorEnablePin, OUTPUT);
    pinMode(servoMotorDirectionPin, OUTPUT);
}

/* 
* Plays the vibration pattern for the peg. This should be called by the update function.
*/
void Peg::playVibrationPattern(){
    this->vibrationPattern.play(vibrationMotorPositivePin, vibrationMotorNegativePin);
}


/* 
* Motor and direction control functions. These should be called by the update function.
* Moves the peg up by one step. This should be non-blocking and use the time fields to determine when to stop.
*/
void Peg::moveUp(){
    digitalWrite(servoMotorDirectionPin, HIGH);
    digitalWrite(servoMotorEnablePin, HIGH);
}

/* 
* Motor and direction control functions. These should be called by the update function.
* Moves the peg down by one step.
*/
void Peg::moveDown(){
    digitalWrite(servoMotorDirectionPin, LOW);
    digitalWrite(servoMotorEnablePin, HIGH);
}

/*
* Field to tell the peg what vibration pattern it should play when called. This should be exposed to the main program as part of the API.
*/
void Peg::setVibrationPattern(int vibrationPattern){
    //TODO implement this
}

/*
* Field to tell the peg where it should be. This should be exposed to the main program as part of the API.
*/
void Peg::setTargetPosition(double position){
    this->tagetPosition = position;
}

/*
* This should be set by the main program when the peg is touched, based on the I2C communication.
* When the peg is first touched, the timer should be set to the current time. This will be used to play the vibration pattern without spin locking the processor.
*/
void Peg::setTouched(boolean touched){
    //set the timer when the peg is first touched.
    if(touched && !this->touched){
        this->currentTime = millis();
        this->previousTime = currentTime;
    }
    this->touched = touched;
}

/* 
* Primary update loop for the peg. This will move the peg to the target position, play the vibration pattern, and update fields.
* The goal of the construction is to prevent spin locking the processor in either the vibration or movement functions.
* This will allow for all pegs to move and vibrate at the same time, within hardware limitations.
*/
void Peg::update(){
    //Move the peg to the target position.
    if(verticalDisplacement < tagetPosition - DISPLACEMENT_THRESHOLD){
        moving = true;
        moveUp();
    } else if(verticalDisplacement > tagetPosition + DISPLACEMENT_THRESHOLD){
        moving = true;
        moveDown();
    } else {
        digitalWrite(servoMotorEnablePin, LOW);
        moving = false;
    }

    //Play vibration pattern if the peg is touched.
    if(touched){
        vibrating = true;
        playVibrationPattern();
    } else {
        vibrating = false;
    }
}


/*
* Getters for the peg.
*/
boolean Peg::isTouched(){
    return touched;
}

boolean Peg::isMoving(){
    return moving;
}

boolean Peg::isVibrating(){
    return vibrating;
}

double Peg::getDisplacement(){
    return verticalDisplacement;
}

int Peg::getRow(){
    return row;
}

int Peg::getColumn(){
    return column;
}
