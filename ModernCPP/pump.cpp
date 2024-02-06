#include <iostream>

using namespace std;

template <int fuel>

float pump(int additionalOil)
    requires(fuel >= 10)
{
    // constexpr
    int minFuel = 10.0f;
    if (fuel + additionalOil < minFuel)
    {
        throw std::runtime_error("Car would stop any min ");
    }
    return fuel + additionalOil;
}

int main()
{

    try
    {
        cout << "Pump : " << pump<20>(20.0f) << endl;
    }
    catch (const std::runtime_error(&e))
    {
        cout << "Exception : " << e.what() << endl;
    }

    return 0;
}