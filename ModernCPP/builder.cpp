//
//  main.cpp
//  Builder
//
//  Created by Sathya Babu on 22/02/24.
//
 
#include <iostream>
#include <string>
#include <memory>
 
class Bill : public std::enable_shared_from_this<Bill> {
public:
    std::shared_ptr<Bill> product(const std::string& productName) {
        product_ = productName;
        return shared_from_this();
    }
 
    std::shared_ptr<Bill> brand(const std::string& brandName) {
        brand_ = brandName;
        return shared_from_this();
    }
 
    std::shared_ptr<Bill> cost(double costAmount) {
        cost_ = costAmount;
        return shared_from_this();
    }
 
    std::shared_ptr<Bill> tax(double taxPercentage) {
        tax_ = taxPercentage;
        return shared_from_this();
    }
 
    void display() const {
        double totalCost = cost_ + (cost_ * (tax_ / 100));
        std::cout << "Product: " << product_ << std::endl;
        std::cout << "Brand: " << brand_ << std::endl;
        std::cout << "Cost: " << cost_ << std::endl;
        std::cout << "Tax: " << tax_ << "%" << std::endl;
        std::cout << "Total Cost (including tax): " << totalCost << std::endl;
    }
 
private:
    std::string product_;
    std::string brand_;
    double cost_;
    double tax_;
};
 
void simpleCode() {
    std::shared_ptr<Bill> bill = std::make_shared<Bill>();
   
    bill
    ->product("pen")
    ->brand("Shefer")
    ->cost(32)
   // ->payBy(Credit/Gpay/cash   )
    ->tax(10)
    ->display();
}
 
int main() {
    simpleCode();
    return 0;
}
/*
 Product: pen
 Brand: Shefer
 Cost: 32
 Tax: 10%
 Total Cost (including tax): 35.2
 Program ended with exit code: 0
 */
 