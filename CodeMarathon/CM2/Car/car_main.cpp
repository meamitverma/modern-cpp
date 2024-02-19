#include<iostream>

template<float fuel>
float pump(float additionalOil)requires(fuel >= 10.0f)
{
    // constexpr
    int minFuel = 10.0f;
    if (fuel + additionalOil < minFuel)
    {
        throw std::runtime_error("Car would stop any min ");
    }
    return fuel + additionalOil;
}

// Mandate
template <typename T>
concept MandateWhileDriving = requires(T t) {
    {
        t.accelerator()
    };
    {
        t.applyBrake()
    };
    {
        t.fuel
    };

    requires std::is_same_v<decltype(t.fuel), float>;      // checks if the t.fuel is a float
    requires std::convertible_to<decltype(t.fuel), float>; // is convertible to float
    {pump<10.0f>(t.fuel)};
};


// Interface
class Engine {
    public:
    Engine() = default;
    void virtual start() = 0;
    virtual void applyAccelerator() = 0;
    virtual void applyBrakes() = 0;

    void updateTemperature(float temp) { temperature = temp; }
    void updateRPM(int rpm) { engine_rpm = rpm; }
    void display() {
        std::cout << "----Engine readings----" << std::endl;
        std::cout << "Engine temperature: " << temperature << std::endl;
        std::cout << "Engine RPM: " << engine_rpm << std::endl;
    }

    private:
    float temperature;
    int engine_rpm;
};

class PetrolTank {
    public:
    void updateFuel() { this->fuel = fuel; }
    void display() {
        std::cout << "----Fuel Reading----" << std::endl;
        std::cout << "Fuel : " << fuel << std::endl;
    }

    private:
    float fuel;
};

class AC {
    public:
    void updateMotor(std::string motor_name) { motor = motor_name; }
    void updateTemp(float temp) { temperature = temp; }
    void display() {
        std::cout << "----AC Readings----" << std::endl;
        std::cout << "AC motor: " << motor << std::endl;
        std::cout << "AC temperature: " << temperature << std::endl;
    }

    std::string motor = "AC Motor";
    private:
    float temperature;

};

class Car {
    public:
    Engine *engine;
    Dashboard *dashboard;
    virtual void start(Engine *e) = 0;
};

template<typename T>
auto iot = [](T t){t.display();};

// View
class Dashboard {
    public:
    template<typename Component>
    void displayDetails() {
        // AC ac;
        iot<Component>(Component{});
    } 
};

// Controller
class ServiceManager {
    public:
    template<typename Component>
    ServiceManager(Dashboard dashboard) {
        this->dashboard = dashboard;
    }

    // AC
    // void updateACTemperature(float temp) {
        
    // }

    private:
    Dashboard dashboard; 

};

class Audi : public Car {
    public:
    Audi() {
        std::cout << "Audi spawned" << std::endl;
    }

    void start(Engine *engine) override {
        std::cout << "Audi started" << std::endl;
    }

};

int main() {
    

    Dashboard *dashboard;

    Audi audi;
    Engine *engine;

    audi.start(engine);
    audi.dashboard = dashboard;

    ServiceManager manager();
    iot<AC>(AC{});
    iot<PetrolTank>(PetrolTank{});

    return 0;
}