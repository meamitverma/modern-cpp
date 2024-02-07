#include<iostream>



int main() {

    std::cout << "Mutable!\n";

    int ammo{ 10 };
    auto shoot {
        [ammo]() mutable {
            --ammo;
            std::cout << "Pew! " << ammo << " shot's left" << std::endl;
        }
    };

    shoot();
    shoot();

    return 0;
}