#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <functional>
 
enum class Threadstate {
    Running,
    Completed,
    Errored
};
 
void run_with_callback(const std::function<void(Threadstate)>& callback) {
    thread_local bool prints = false; // Define thread-local variable
    try {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (!prints) {
            callback(Threadstate::Running);
            prints = true;
        }
        callback(Threadstate::Completed);
    }
    catch (...) {
        if (!prints) {
            callback(Threadstate::Running);
            prints = true;
        }
        callback(Threadstate::Errored);
    }
}
 
int main() {
    std::cout << "thread callback" << std::endl;
    std::vector<std::future<void>> futures; // Changed the future type to void
 
    auto callBack = [](Threadstate state) {
        switch (state) {
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
 
    for (int i = 0; i < 5; ++i) {
        decltype(auto) f = std::async(std::launch::async, [&callBack]() { run_with_callback(callBack); }); // Using a lambda to capture callBack
        futures.emplace_back(std::move(f));
    }
 
    for (auto& f : futures) {
        f.wait(); // Wait for each task to complete
    }
 
    return 0;
}
 