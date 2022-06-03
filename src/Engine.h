class Engine {
    private:
        int pin;
    public:
        Engine(int pin);

        void setSpeed(int speed);

        void stop();

        //void changeDirection();
};