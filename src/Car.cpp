#include "Car.h"
Car::Car(int frontLeftPin, int frontRightPin, int rearLeftPin, int rearRightPin) {
    frontLeft = new Engine(frontLeftPin);
    frontRight = new Engine(frontRightPin);
    rearLeft = new Engine(rearLeftPin);
    rearRight = new Engine(rearRightPin);            
}

void Car::stop() {
    frontLeft->stop();
    frontRight->stop();
    rearLeft->stop();
    rearRight->stop();
}


void Car::move(int speed, int direction) {
    double rightMultiplier = 1;
    double leftMultiplier = 1;
    if (direction < 0) {
        leftMultiplier = (direction / 100.0);
    } else if (direction > 0) {
        rightMultiplier = (direction / 100.0);
    }
    frontLeft->setSpeed(speed * leftMultiplier);
    frontRight->setSpeed(speed * rightMultiplier);
    rearLeft->setSpeed(speed*leftMultiplier);
    rearRight->setSpeed(speed*rightMultiplier);
}