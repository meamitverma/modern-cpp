#include <iostream>

// fff0
class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }

    // virtual destructor -> deletes the child class too to avoid memory leak
    virtual ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }

    // ~Base()
    // {
    //     std::cout << "Base destructor" << std::endl;
    // }
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
    // without having virtual destructor dervied class is not delted from the memory amd creates the memory leak

    return 0;
}