#include<iostream>
using namespace std;

struct singleton_t {
    static
    singleton_t &instance() {
        static singleton_t instance;
        return instance;
    } // instance

    singleton_t(const singleton_t &) = delete; // stop copy constructor
    singleton_t & operator = (const singleton_t &) = delete; // st

    private:
    singleton_t() { cout << "Constructor called " << endl; }
    ~singleton_t() { cout << "Destructor called" << endl; }

    public:
    void out() { printf("out\n"); }
}; // struct singleton_t

int main() {

    singleton_t::instance().out();

    return 0;
}