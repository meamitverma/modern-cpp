#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


class Engine {
    public:
    virtual void display() = 0;
};
class Petrol : public Engine {
    
    void display() {
        std::cout << "Fuel IOT" << std::endl;
    }
    
};
class OilFilter : public Engine {
    void display() {
        std::cout << "Oil Filter IOT" << std::endl;
    }
};
class Piston : public Engine {
    void display() {
        std::cout << "Piston IOT" << std::endl;
    }
};
class Battery : public Engine {
    void display() {
        std::cout << "Battery IOT" << std::endl;
    }
};
class Combustion : public Engine {
    void display() {
        std::cout << "Combustion IOT" << std::endl;
    }
};


template <typename Func, typename Iterator>
void executeThreads(Func &&func, Iterator begin, Iterator end)
{
    std::vector<std::thread> threads;
    for (auto it = begin; it != end; it++)
    {
        std::lock_guard<std::mutex> lock(std::mutex);
        std::this_thread::sleep_for(std::chrono::seconds(3)); // block for 3 sec
        threads.emplace_back(std::forward<Func>(func), std::ref(*it));
    }

    for (auto &thread : threads)
    {
        std::cout << thread.get_id() << std::endl;
        thread.join();
    }
}

void processEnginerIOTs(Engine *engine)
{
    // std::string iot[5] = {"Oil Filter IOT", "Petrol IOT", "Piston", "Combustion", "Battery"};
    std::cout << "\t State Started : " << std::endl;
    std::cout << "\t State Processing: " << std::endl;
    std::cout << "IOT processed : " << std::endl;
    engine->display();
    std::cout << "\t State Processes Completed: " << std::endl;
}

int main()
{

    std::cout << "Mutex \n";
    std::vector<Engine*> iots{new Petrol,new OilFilter, new Battery};
    // std::vector<int> values = {1, 2, 3, 4, 5};
    executeThreads(processEnginerIOTs, iots.begin(), iots.end());
    std::vector<std::thread> thread2;

    return 0;
}