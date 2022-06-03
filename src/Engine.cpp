#include "Engine.h"
#include <Arduino.h>
int pin;

Engine::Engine(int pin) {
            this -> pin = pin;
            pinMode(pin, OUTPUT);
        }


void Engine::setSpeed(int speed) {
    int newSpeed = speed;
    if (newSpeed < 0) {
        newSpeed *= -1;
    }
    analogWrite(pin, newSpeed);
}

void Engine::stop() {
    this->setSpeed(0);
}