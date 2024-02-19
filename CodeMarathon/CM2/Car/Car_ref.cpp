#include <iostream>
using namespace std;
enum class CarType
{
    Mercedes,
    Ferrari
};
class Engine
{
public:
    // Engine() = default ;
    Engine()
    {
        cout << "Base engine created..." << endl;
    }
    void virtual start() = 0;
};
class AmgEngine : public Engine
{
public:
    void start() override
    {
        cout << " AMGengine started " << endl;
    }
};
class FerrariEngine : public Engine
{
public:
    void start() override
    {
        cout << " Ferrari Engine started " << endl;
    }
};
class ServiceProviderFactory
{
private:
    Engine *engine;

public:
    Engine *getEngine(CarType carType)
    {
        if (carType == CarType::Mercedes)
        {
            engine = new AmgEngine;
        }
        else if (carType == CarType::Ferrari)
        {
            engine = new FerrariEngine;
        }
        else
        {
            cout << "Requested engine not found !!" << endl;
            return nullptr;
        }
        return nullptr;
    }
};

class Car
{
private:
public:
    Car()
    {
        cout << "base car created..." << endl;
    }
    Engine *engine;
    virtual void start(Engine *e) = 0;
};
class BenzCar : public Car
{
public:
    void start(Engine *engine)
    {
        cout << "Benz car started " << endl;
        this->engine = engine;
        engine->start();
    }
};
class FerrariCar : public Car
{
public:
    void start(Engine *engine)
    {
        cout << "Ferrari car started " << endl;
        this->engine = engine;
        engine->start();
    }
};

int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "Engine provider !\n";
    ServiceProviderFactory *serviceProviderFactory = new ServiceProviderFactory;
    Engine *engine = serviceProviderFactory->getEngine(CarType::Ferrari);
    FerrariCar car;
    car.start(engine);
    return 0;
}