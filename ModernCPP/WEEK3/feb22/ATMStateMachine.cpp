#include<iostream>
#include<memory>
// Worst way to write state machine
// Enum for ATM states
enum class ATMState {
    IDLE,
    HAS_CARD,
    NO_CARD,
    HAS_PIN,
    NO_CASH
};

std::string CardState[ 7 ] = {
    "IDLE",
    "HAS_CARD",
    "NO_CARD",
    "HAS_PIN",
    "NO_CASH"
};

class ATMmachine : public std::enable_shared_from_this < ATMmachine>{
public:
    ATMState atmState;
    double cashInTheMachine;

    ATMmachine() : atmState(ATMState::HAS_CARD), cashInTheMachine( 5000.0 ) {}

    double getCashFromTheMachine() {
        return cashInTheMachine;
    }

    std::shared_ptr<ATMmachine> getThisPointer() {
        return shared_from_this();
    }

    private:

};

class GetAtmData {
public:
    virtual ATMState getATMState() = 0;
    virtual double getCashFromTheMachine() = 0; 
};

class ATMProxy : public GetAtmData {
public:
    std::shared_ptr< ATMmachine > atmMachine; //atmachine is composed
    ATMProxy(std::shared_ptr< ATMmachine > atmMachineTemp) : atmMachine(atmMachineTemp) {}

    ATMState getATMState() override {
        return atmMachine->atmState;
    }

    double getCashFromTheMachine() override {
        // .........user validation and all checks goes here
        // all logics goes here

        atmMachine->cashInTheMachine -= 500;
        return atmMachine->getCashFromTheMachine();
        // return atmMachine->getCashFromTheMachine() - 500;
    }
};

int main() {

    std::cout << "ATM State Machine" << std::endl;

    // std::shared_ptr< ATMmachine > atmMachine = std::make_shared< ATMmachine >();
    ATMProxy atmProxy(std::make_shared< ATMmachine >() );

    // std::cout << atmMachine->getCashFromTheMachine() << std::endl;
    std::cout << atmProxy.getCashFromTheMachine() << std::endl;

    return 0;
}