#include<iostream>

template < typename State >
struct TransactionTo {
    template< typename Machine >
    void execute( Machine& machine ) {
        machine.template transactionTo < State >();
    }
};

struct Machine {
    template< typename State >
    void transactionTo() {
        std::cout << "Is transaction with state : ";
    }
};

struct MyState {};
struct YourState {};


int main() {

    Machine machine;
    TransactionTo < YourState > transaction;
    transaction.execute( machine );
    
    return 0;
}