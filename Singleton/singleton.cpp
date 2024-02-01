#include <iostream>

class Singleton
{
private:
    static Singleton *instance; // only one instance
    static int ref_count;

    // private constructor
    Singleton()
    {
        std::cout << "Object is created" << std::endl;
    }

public:
    static Singleton getInstance()
    {
        std::cout << "Called singleton get instance" << std::endl;

        // if not nullptr
        if (!instance)
        {

            instance = new Singleton;

            ref_count++;
            std::cout << "Holding ref to the user " << ref_count << " log." << std::endl;
        }

        ref_count++;
        std::cout << "Holding ref to the user " << ref_count << " log." << std::endl;

        return *instance;
    }

    int getRefCounter() {
        return ref_count;
    }

    int clearRefCounter() {
        std::cout << std::endl << "user Logged out "  << ref_count << " log." << std::endl;
        return ref_count--;
    }

    // destructor
    ~Singleton()
    {
        if (ref_count == 0)
        {
            std::cout << std::endl
                      << "All user Logged out Deleting the object..." << ref_count << std::endl;

            
            delete instance;
        }
    }
};

Singleton *Singleton::instance = nullptr;
int Singleton::ref_count = 0;

int main()
{
    std::cout << "Hello, World\n";
    Singleton singleton = Singleton::getInstance();
    Singleton singleton1 = Singleton::getInstance();
    Singleton singleton2 = Singleton::getInstance();
    Singleton singleton3 = Singleton::getInstance();
    Singleton singleton4 = Singleton::getInstance();
    Singleton singleton5 = Singleton::getInstance();

    std::cout << "People using " << singleton1.getRefCounter() << std::endl;
    
    std::cout << "A guy moved out of Singleton " << singleton1.clearRefCounter() << std::endl;

    std::cout << "People using " << singleton1.getRefCounter() << std::endl;

    // Singleton::getInstance();
    // Singleton::getInstance();
    // Singleton::getInstance();
    // Singleton::getInstance();

    return 0;
}