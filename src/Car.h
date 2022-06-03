#include "Engine.h"
class Car {

    public:
        Car(int frontLeftPin, int frontRightPin, int rearLeftPin, int rearRightPin);

        void stop();

        void move(int speed, int direction);

    private:
        
    Engine* frontLeft;
    Engine* frontRight;
    Engine* rearLeft;
    Engine* rearRight;
};