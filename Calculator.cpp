#include<iostream>

// interface
// abstract class
class Calculator {
    public:
    virtual int add(int x, int y) = 0;
    virtual int sub(int x, int y) = 0;
    virtual int mul(int x, int y) = 0;
    virtual float div(int x, int y) = 0;
};

class BasicCalulator : public Calculator {
    public:
    int add(int x, int y) override {
        return x + y;
    }  
    int sub(int x, int y) override{
        return x - y;
    }
    int mul(int x, int y) override {
        return x * y;
    }
    float div(int x, int y) override{
        return x / (y * 1.0);
    }
};

class User {
    public:
    virtual void requestAdd(Calculator *calc, int x, int y) = 0;
    virtual void requestSub(Calculator *calc, int x, int y) = 0;
    virtual void requestMul(Calculator *calc, int x, int y) = 0;
    virtual void requestDiv(Calculator *calc, int x, int y) = 0;
};

class Tom : public User {
    public:
    void requestAdd(Calculator *calc, int a, int b) override{
        int sum = calc->add(a, b);
        std::cout << "Sum = " << sum << std::endl;
    }
    void requestSub(Calculator *calc, int a, int b) override{
        int subtraction = calc->sub(a, b);
        std::cout << "Sum = " << subtraction << std::endl;
    }
    void requestMul(Calculator *calc, int a, int b) override {
        int multiplication = calc->mul(a, b);
        std::cout << "Sum = " << multiplication << std::endl;
    }
    void requestDiv(Calculator *calc, int a, int b) override{
        float division = calc->div(a, b);
        std::cout << "Sum = " << division << std::endl;
    }
};

int main() {

    Calculator *calc = new BasicCalulator();
    User *user = new Tom();
    int x = 3, y = 2;
    user->requestAdd(calc, x, y);
    user->requestSub(calc, x, y);
    user->requestMul(calc, x, y);
    user->requestDiv(calc, x, y);
 
    return 0;
}