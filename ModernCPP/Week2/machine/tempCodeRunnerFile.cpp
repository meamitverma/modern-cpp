#include <iostream>
#include<memory>
using namespace std;

class CarState
{
public:
    virtual void start() = 0;
    virtual void accelerate() = 0;
    virtual void applyBrake() = 0;
    virtual void turnOnAC() = 0;
    virtual void pumpFuel(int fuel) = 0;
    virtual void stop() = 0;
};

class Car
{
    CarState* _carState;
    int _carInFuel;
    int _carSpeed;

public:
    Car();
    void setCarState(CarState* _carState);

    // states
    void start();
    void accelerate();
    void applyBrake();
    void turnOnAC();
    void pumpFuel(int fuel);
    void stop();

    // getters and setters
    void setCarInFuel(int fuel);
    void setCarSpeed(int speed);
    int getCarInFuel() const;
    int getCarSpeed() const;
};

Car::Car() {
    _carState = new Stopped(this);
    _carInFuel = 15;
    _carSpeed = 0;
}

void Car::setCarState(CarState* carState) {
    if (NULL != carState)
    {
        _carState = carState;
    }
}

void Car::setCarInFuel(int fuel) {
    _carInFuel = fuel;
}
void Car::setCarSpeed(int speed) {
    _carSpeed = speed;
}
int Car::getCarInFuel() const{
    return _carInFuel;
}
int Car::getCarSpeed() const {
    return _carSpeed;
}

void Car::start() {
    _carState->start();
}
void Car::accelerate() {
    _carState->accelerate();
}
void Car::applyBrake() {
    _carState->applyBrake();
}
void Car::turnOnAC() {
    _carState->turnOnAC();
}
void Car::pumpFuel(int fuel) {
    _carState->pumpFuel(fuel);
}
void Car::stop() {
    _carState->stop();
}


// STOP
class Stopped : public CarState
{
    Car* _pCar;

public:
    Stopped(Car* pCar)
    {
        _pCar = pCar;
    }
    ~Stopped(){};

    void start()
    {
        std::cout << "Car is starting" << std::endl;
        // if (_pCar->getCarInFuel() > 0)
        // {
        //     std::cout << "Car Started" << std::endl;
        //     _pCar->setCarState(new Started(_pCar));
        // }
    }

    void accelerate()
    {
        std::cout << "Car needs to be started first" << std::endl;
    }

    void applyBrake()
    {
        std::cout << "Already stopped" << std::endl;
    }

    void turnOnAC()
    {
        std::cout << "Car need to be started" << std::endl;
    }

    void pumpFuel(int fuel)
    {
        std::cout << "Car fueled up" << std::endl;
        // _pCar->setCarInFuel(fuel);
    }

    void stop()
    {
        std::cout << "Car stopped" << std::endl;
        // _pCar->setCarState(new Stopped(_pCar));
    }
};

// // PUMP
// class Pump : public CarState
// {
//     Car *_pCar;

// public:
//     Pump(Car *pCar)
//     {
//         _pCar = pCar;
//     }

//     void start()
//     {
//         std::cout << "Car is getting pumped up" << std::endl;
//     }

//     void accelerate()
//     {
//         std::cout << "Car needs to be started first" << std::endl;
//     }

//     void applyBrake()
//     {
//         std::cout << "Already stopped" << std::endl;
//     }

//     void turnOnAC()
//     {
//         std::cout << "Car need to be started" << std::endl;
//     }

//     void pumpFuel(int fuel)
//     {
//         std::cout << "Car fueling up" << std::endl;
//         _pCar->setCarInFuel(fuel);
//         _pCar->setCarState(new Pump(_pCar));
//     }

//     void stop()
//     {
//         std::cout << "Car on stop" << std::endl;
//     }
// };

// // BRAKE
// class Brake : public CarState
// {
//     Car *_pCar;

// public:
//     Brake(Car *pCar)
//     {
//         _pCar = pCar;
//     }

//     void start()
//     {
//         std::cout << "Car already started" << std::endl;
//     }

//     void accelerate()
//     {
//         std::cout << "Brake is been applied" << std::endl;

//     }

//     void applyBrake()
//     {
//         std::cout << "Applying brake" << std::endl;
//         _pCar->setCarState(new Brake(_pCar));
//     }

//     void turnOnAC()
//     {
//         std::cout << "AC turned on" << std::endl;
//     }

//     void pumpFuel(int fuel)
//     {
//         std::cout << "Car needs to be stopped" << std::endl;
//     }

//     void stop()
//     {
//         std::cout << "Brake has been applied " << std::endl;
//     }
// };

// // Accelerate
// class Accelerate : public CarState
// {
//     Car *_pCar;

// public:
//     Accelerate(Car *pCar)
//     {
//         _pCar = pCar;
//     }

//     void start()
//     {
//         std::cout << "Car has already started" << std::endl;
//     }

//     void accelerate()
//     {
//         std::cout << "Car acclerated" << std::endl;
//         _pCar->setCarSpeed(_pCar->getCarSpeed() + 10);
//         _pCar->setCarState(new Accelerate(_pCar));
//     }

//     void applyBrake()
//     {
//         std::cout << "Applying brake" << std::endl;
//         _pCar->setCarState(new Brake(_pCar));
//     }

//     void turnOnAC()
//     {
//         std::cout << "Turned on AC" << std::endl;
//     }

//     void pumpFuel(int fuel)
//     {
//         std::cout << "Car needs to be stopped" << std::endl;
//     }

//     void stop()
//     {
//         std::cout << "Car is running, apply brakes" << std::endl;
//     }
// };

// // START
// class Started : public CarState
// {
//     Car *_pCar;

// public:
//     Started(Car *pCar)
//     {
//         _pCar = pCar;
//     }

//     void start()
//     {
//         std::cout << "Car is starting" << std::endl;
//         if (_pCar->getCarInFuel() > 0)
//         {
//             std::cout << "Car started" << std::endl;
//             _pCar->setCarState(new Started(_pCar));
//         }
//     }

//     void accelerate()
//     {
//         std::cout << "Car acclerated" << std::endl;
//         _pCar->setCarSpeed(_pCar->getCarSpeed() + 10);
//         _pCar->setCarState(new Accelerate(_pCar));
//     }

//     void applyBrake()
//     {
//         std::cout << "Applying brake" << std::endl;
//         _pCar->setCarState(new Brake(_pCar));
//     }

//     void turnOnAC()
//     {
//         std::cout << "Turned on AC" << std::endl;
//     }

//     void pumpFuel(int fuel)
//     {
//         std::cout << "Car needs to be stopped" << std::endl;
//     }

//     void stop()
//     {
//         std::cout << "Apply brakes" << std::endl;
//     }
// };



int main()
{  

    std::cout << "Welcome to Tesla!" << std::endl;
    Car car;
    car.start();

    return 0;
}