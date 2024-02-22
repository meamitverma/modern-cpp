#include<bits/stdc++.h>
using namespace std;

// 1dc2f
class Animal {
private:
    string type;
public:
    Animal() : type("Animal"){}

    // Phase1
    // string getType() {
    //     return type;
    // }

    // Phase2
    // string virtual getType() {
    //     return type;
    // }

    // Phase3
    string virtual getType() = 0;
};


//    ff00         1c2f
class Dog : public Animal {
private:
    std::string type;
public:
    Dog() : type("I'm a Dog"){}
    std::string getType() {
        return type;
    }

};

class Cat : public Animal {
private:
    std::string type;
public:
    Cat() : type("I'm a Cat"){}
    std::string getType() {
        return type;
    }

};

void printAnimalName(Animal * animal) {
    cout << animal->getType() << endl;
}

int main(int argc, const char *argv[]) {

    cout << "Virtual Function! \n";

    // Phase             1c2f
    // this is not allowed when it's a pure virtual function
    // Animal *animal = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    // cout << dog->getType() << endl;
    // cout << cat->getType() << endl;

    printAnimalName(dog);
    printAnimalName(cat);

    return 0;
}