#include <iostream>

// fff0
class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }

    ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }
};

// 11ec       :        fff0
class Derived : public Base
{   
    public:
    Derived()
    {
        std::cout << "Derived Constructor" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main(int argc, char *argv[])
{   // fff0          11ec
    Base *base = new Derived;
    delete base;// 11ec

    return 0;
}