#include<iostream>
#define CARDNO "123"

enum class FoodPreference { VEG, NON_VEG }; 

class Cruise {
    public:
    virtual bool registerUser(User *user) = 0;
    virtual bool pay(std::string credit_card) = 0;
    virtual bool book() = 0;
    virtual void food(FoodPreference food) = 0;
    // virtual void subscribe() = 0;
    // virtual void build() = 0;

};

class BookingService : Cruise {
    public:
    bool registerUser(User *user) override {
        if (user->getAge() < 18) {  
            std::cout << "Not eligible to travel." << std::endl;
            exit(0);
            return false;
        }

        std::cout << "User registration successfull" << std::endl;
        return true;
    }

    bool pay(std::string card_no) {
        if (card_no != CARDNO) {
            std::cout << "Wrong card number provided." << std::endl;
            return false;
            exit(0);
        }

        std::cout << "Payment successfull" << std::endl;

    }    
    
    
};

class User {
    private:
    int age;
    std::string name;
    
    public:
    User() = default;
    User(std::string name, const int age) {
        this->name = name;
        this->age = age;
    }  

    int getAge() { return this->age; }
};

int main(int argc, char *argv[]) {

    return 0;
}