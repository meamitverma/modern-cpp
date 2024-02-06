#include <iostream>
#include <type_traits>

/*
    Results of a class while testing.
    adding a Pump to it..
    variable expression
    function recursion
    fold expression

    expression lValue rValue xValue  pValue
    perfect forwarding

    expressions
    structural bindings
    aggregate
    initializer list vs constructors
*/

// rules
// compulsion on every classes
// a class has requirements
template <typename T>
concept MandateWhileDriving = requires(T t) {
    {
        t.accelerator()
    };
    {
        t.applyBrake()
    };
    {
        t.fuel
    };

    requires std::is_same_v<decltype(t.fuel), float>;      // checks if the t.fuel is a float
    requires std::convertible_to<decltype(t.fuel), float>; // is convertible to float
    // requires ( t.fuel >= 10 );
};

class Engine
{
public:
    void accelerator()
    {
        std::cout << "Pump the accelerator..." << std::endl;
    }
    void applyBrake()
    {

        std::cout << "Applply the brakes" << std::endl;
    }
    void notRelatedToEngine()
    {
        std::cout << "This fun not related to engine..." << std::endl;
    }

    float fuel = 20.5f;
};

class Car
{

public:
    template <MandateWhileDriving T>
    void drive(T arg)
    {
        arg.accelerator();
        arg.applyBrake();
        arg.notRelatedToEngine();
    }
};

int main()
{
    Car myCar;
    Engine engine;
    myCar.drive(engine);

    return 0;
}