#include<iostream>
#include<memory>

// EngineManager
//     .SubsribeOn( BackGroundScheduler )
//     .ensureAllIOTisON()
//     .observeOn( DashboardScheduler );
class EngineManager {
public:
    EngineManager subscribeOn() {
        std::cout << "subscribe" << std::endl;
    }

    EngineManager ensureAllIOTisOn() {
        std::cout << "on" << std::endl;
    }

    void observeOn() {
        std::cout << "observe" << std::endl;
    }
};

class Bill : public std::enable_shared_from_this<Bill> {
public:
    std::shared_ptr<Bill> brand( const std::string brandName ) {
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
        // double//
        std::cout << "Product: " << product_ << std::endl; 
    }


private:
    std::string product_;
    int cost_;
    int tax_;
};

void simpleCode() {
    std::shared_ptr<Bill> bill = std::make_shared<Bill>();

    bill
    ->brand("Brand")
    ->cost(10.0)
    ->tax(120)
    ->display();
}

int main() {
    // EngineManager engineManager;
    // engineManager.subscribeOn().ensureAllIOTisOn().observeOn();

    simpleCode();
    

    return 0;
}

