#include<iostream>

enum class CarType {Mercedes, Ferrari};

class Engine {
    public:
    // Engine() = default;
    Engine() {
        std::cout << "Base engine created..." << std::endl;
    }
    void virtual start() = 0;
};

class AmgEngine : public Engine {
    public:
    void start() override {
        std:: cout << "AMGEngine started" << std::endl;
    }
};

class FerrariEngine : public Engine {
    public:
    void start() override{
        std::cout << "Ferrari Engine started." << std::endl;
    }
};

class ServiceProviderFactory {
    private:
    Engine *engine;

    public:
    Engine *getEngine(CarType carType) {
        if (carType == CarType::Mercedes) {
            engine = new AmgEngine;
        }
        else if (carType == CarType::Ferrari){
            engine = new FerrariEngine;
        }
        else {
            std::cout << "Requested engine not found." << std::endl;
            // NULL -> non literal datatypec
            return nullptr;
        }

        return engine;
    }  
};

class Car {
    private:
    public:
    Car() {
        std::cout << "Base car created..." << std::endl;
    }
    Engine *engine;
    virtual void start(Engine *e) = 0;
};

class baseCar : public Car {
    public:
    void start(Engine *engine) {
        std::cout << "Base car started" << std::endl;
        this->engine = engine;
        engine->start();
    }
};

class FerrariCar : public Car {
    public:
    void start(Engine *engine) {
        std::cout << "Ferrari started" << std::endl;
        this->engine = engine;
        engine->start();
    }
};

int main (int argc, const char *argv[]) {

    std::cout << "Engine \n";
    ServiceProviderFactory *serviceProviderFactory = new ServiceProviderFactory;
    Engine *engine = serviceProviderFactory->getEngine(CarType::Ferrari);
    FerrariCar car;
    car.start(engine);

    return 0;
}