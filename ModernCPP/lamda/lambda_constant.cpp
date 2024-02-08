#include<iostream>
#include<array>
#include<algorithm>

struct Car {
    std::string  make{};
    std::string model{};
};

int main() {

    std::array<Car, 3> cars{ 
        { 
            {"Vokswagen", "Gold"}, 
            {"Toyota", "Corolla"}, 
            {"Honda", "Civic"}
        } 
    };

    int comparisions{0};
    std::sort(cars.begin(), cars.end(),
        [&comparisions](const auto &a, const auto &b) {
            ++comparisions;
            return (a.make < b.make);
        }
    );

    std::cout << "Comparision compared ans sorted " << comparisions + 1 << std::endl;
    for (const auto &car : cars) {
        std::cout << car.make << " " << car.model << std::endl;
    }

    

    return 0;
}