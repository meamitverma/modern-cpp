#include<iostream>
#include<vector>

class JetAir {
    private:
    std::vector<Customer*> customers;

    public:
    virtual void registerUser() = 0;
    virtual void deregisterUser() = 0;
};

class Pilot {
    private:
    std::string name;
    bool isAvailable = false;

    public:
    bool getAvailability() {
        return this->isAvailable;
    }
};

class Customer {
    private:
    std::string name;

    public:
    std::string getName() { return this->name; }

};

int main() {
    
    
    return 0;
}