#include <iostream>
#include <memory>

class CarState {
public:
    virtual void start() = 0;
    virtual void accelerate() = 0;
    virtual void applyBrake() = 0;
    virtual void turnOnAC() = 0;
    virtual void pumpFuel(int fuel) = 0;
    virtual void stop() = 0;
};

class Car {
    CarState* currentState;
    int fuelLevel;
    int speed;

public:
    Car();
    void setState(CarState* state);

    // Actions
    void start();
    void accelerate();
    void applyBrake();
    void turnOnAC();
    void pumpFuel(int fuel);
    void stop();

    // Getters and setters
    void setFuelLevel(int fuel);
    void setSpeed(int speed);
    int getFuelLevel() const;
    int getSpeed() const;
};

Car::Car() : currentState(nullptr), fuelLevel(15), speed(0) {
    setState(new Stopped(this));
}

void Car::setState(CarState* state) {
    if (state != nullptr) {
        currentState = state;
    }
}

void Car::setFuelLevel(int fuel) {
    fuelLevel = fuel;
}

void Car::setSpeed(int speed) {
    this->speed = speed;
}

int Car::getFuelLevel() const {
    return fuelLevel;
}

int Car::getSpeed() const {
    return speed;
}

void Car::start() {
    currentState->start();
}

void Car::accelerate() {
    currentState->accelerate();
}

void Car::applyBrake() {
    currentState->applyBrake();
}

void Car::turnOnAC() {
    currentState->turnOnAC();
}

void Car::pumpFuel(int fuel) {
    currentState->pumpFuel(fuel);
}

void Car::stop() {
    currentState->stop();
}

class Stopped : public CarState {
    Car* car;

public:
    Stopped(Car* car) : car(car) {}

    void start() override {
        std::cout << "Starting the car." << std::endl;
        if (car->getFuelLevel() > 0) {
            std::cout << "Car started." << std::endl;
            car->setState(new Started(car));
        }
    }

    void accelerate() override {
        std::cout << "The car needs to be started first." << std::endl;
    }

    void applyBrake() override {
        std::cout << "The car is already stopped." << std::endl;
    }

    void turnOnAC() override {
        std::cout << "Start the car to turn on the AC." << std::endl;
    }

    void pumpFuel(int fuel) override {
        std::cout << "Fueling up the car." << std::endl;
        car->setFuelLevel(fuel);
    }

    void stop() override {
        std::cout << "The car is already stopped." << std::endl;
    }
};

class Started : public CarState {
    Car* car;

public:
    Started(Car* car) : car(car) {}

    void start() override {
        std::cout << "The car has already started." << std::endl;
    }

    void accelerate() override {
        std::cout << "The car accelerated." << std::endl;
        car->setSpeed(car->getSpeed() + 10);
        car->setState(new Accelerate(car));
    }

    void applyBrake() override {
        std::cout << "Applying brakes." << std::endl;
        car->setState(new Brake(car));
    }

    void turnOnAC() override {
        std::cout << "Turning on AC." << std::endl;
    }

    void pumpFuel(int fuel) override {
        std::cout << "The car needs to be stopped." << std::endl;
    }

    void stop() override {
        std::cout << "Applying brakes." << std::endl;
        car->setState(new Stopped(car));
    }
};

class Accelerate : public CarState {
    Car* car;

public:
    Accelerate(Car* car) : car(car) {}

    void start() override {
        std::cout << "The car has already started." << std::endl;
    }

    void accelerate() override {
        std::cout << "The car accelerated." << std::endl;
        car->setSpeed(car->getSpeed() + 10);
    }

    void applyBrake() override {
        std::cout << "Applying brakes." << std::endl;
        car->setState(new Brake(car));
    }

    void turnOnAC() override {
        std::cout << "Turning on AC." << std::endl;
    }

    void pumpFuel(int fuel) override {
        std::cout << "The car needs to be stopped." << std::endl;
    }

    void stop() override {
        std::cout << "Applying brakes." << std::endl;
        car->setState(new Stopped(car));
    }
};

class Brake : public CarState {
    Car* car;

public:
    Brake(Car* car) : car(car) {}

    void start() override {
        std::cout << "The car has already started." << std::endl;
    }

    void accelerate() override {
        std::cout << "Applying brakes." << std::endl;
        car->setState(new Brake(car));
    }

    void applyBrake() override {
        std::cout << "Applying brakes." << std::endl;
    }

    void turnOnAC() override {
        std::cout << "Turning on AC." << std::endl;
    }

    void pumpFuel(int fuel) override {
        std::cout << "The car needs to be stopped." << std::endl;
    }

    void stop() override {
        std::cout << "Applying brakes." << std::endl;
        car->setState(new Stopped(car));
    }
};

int main() {
    std::cout << "Welcome to Tesla!" << std::endl;
    Car car;
    car.start();
    car.accelerate();
    car.applyBrake();
    car.turnOnAC();
    car.pumpFuel(20);
    car.stop();

    return 0;
}