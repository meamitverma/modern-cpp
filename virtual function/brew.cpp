#include<iostream>
using namespace std;

class Brew{
public:
    void boilWater() {
        cout << "Boil Water" << endl;
    }
    void boilMilk() {
        cout << "Boil Milk" << endl;
    }
    void pourItInMug() {
        cout << "Pour it in mug" << endl;
    }
    virtual void AddsCondiments1()=0;
    virtual void AddsCondiments2()=0;
    virtual void AddsCondiments3()=0;

    void execute() {

        boilWater();
        boilMilk();
        AddsCondiments1();
        AddsCondiments2();
        pourItInMug();

    }
};

class Tea : public Brew {
public:
    void AddsCondiments1() override {
        cout << "Steep the tea bag.." << endl;
    }
    void AddsCondiments2() override {
        cout << "Add Lime.." << endl;
    }
    void AddsCondiments3() override {
        cout << "Add Sugar.." << endl;
    }
};

class Coffee : public Brew {
public:
    void AddsCondiments1() override {
        cout << "Grinded Fresh Coffee Bean.." << endl;
    }
    void AddsCondiments2() override {
        cout << "Add Cinnamon.." << endl;
    }
    void AddsCondiments3() override {
        cout << "Add Sugar.." << endl;
    }
};


int main() {

    cout << "Using pure virtual function\n";
    Brew *brew = new Tea();
    brew->execute();
    
    return 0;
}