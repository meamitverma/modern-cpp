#include <iostream>
#include <mutex>
#include <vector>
#include <memory>
#include <thread>
#include <functional> // Add this header for std::function
 
enum class Threadstate {
    Running,
    Completed,
    Errored
};
 
class Sensor {
public:
    virtual void readData() = 0;
};
 
class RPM_Sensor : public Sensor {
public:
    void readData() override {
        // Simulated RPM sensor reading
        std::cout << "Reading RPM sensor data..." << std::endl;
        // You can add logic here to change state based on sensor data
    }
};
 
class OilPressure_Sensor : public Sensor {
public:
    void readData() override {
        // Simulated oil pressure sensor reading
        std::cout << "Reading Oil Pressure sensor data..." << std::endl;
        // You can add logic here to change state based on sensor data
    }
};
 
class SensorManager {
private:
    std::vector<std::shared_ptr<Sensor>> vecSensor;
    std::mutex mutex;
    std::function<void(Threadstate)> callback; // Callback function
 
public:
    SensorManager(std::function<void(Threadstate)> cb) : callback(cb) {} // Constructor to set callback
 
    void addSensor(std::shared_ptr<Sensor> sensor) {
        vecSensor.emplace_back(sensor);
    }
 
    void readSensorData() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
 
            std::lock_guard<std::mutex> lock(mutex);
            for (const auto& sensor : vecSensor) {
                sensor->readData(); // Read data from each sensor
            }
            callback(Threadstate::Running); // Report task is running
        }
    }
};
 
int main() {
    std::cout << "Thread callback" << std::endl;
 
    auto callBack = [](Threadstate state) {
        switch(state) {
            case Threadstate::Running:
                std::cout << "Thread is running" << std::endl;
                break;
            case Threadstate::Completed:
                std::cout << "Thread is completed successfully" << std::endl;
                break;
            case Threadstate::Errored:
                std::cout << "Error encountered" << std::endl;
                break;
        }
    };
 
    SensorManager manager(callBack);
    manager.addSensor(std::make_shared<RPM_Sensor>());
    manager.addSensor(std::make_shared<OilPressure_Sensor>());
 
    std::thread sensorThread(&SensorManager::readSensorData, &manager);
    sensorThread.join();
 
    return 0;
}