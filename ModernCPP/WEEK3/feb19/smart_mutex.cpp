#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

template< typename Func, typename Iterator>
void executeThreads(Func&& func, Iterator begin, Iterator end) {
    std::vector< std::thread > threads;
    for (auto it = begin; it != end; it++) {
        std::lock_guard < std::mutex > lock(std::mutex);
        std::this_thread::sleep_for(std::chrono::seconds(3)); // block for 3 sec
        threads.emplace_back( std::forward<Func>(func), std::ref( *it ));
    }

    for (auto& thread : threads) {
        std::cout << thread.get_id() << std::endl;
        thread.join();
    }
}

// void processValue(int& value) {
//     std::cout << "Value processed : " << value << std::endl;
// }

void processValue(int& value) {
    std::string iot[5] = {"Oil Filter IOT", "Petrol IOT", "Piston", "Cumbersion"};
    std::cout << "\t State Started : " <<  std::endl;
    std::cout << "\t State Processing: " <<  std::endl;
    std::cout << "IOT processed : " << iot[value] << std::endl;
    std::cout << "\t State Process Completed: " <<  std::endl;
}

int main() {

    std::cout << "Mutex \n";
    std::vector<int> values = {1,2,3,4,5};
    executeThreads(processValue, values.begin(), values.end());
    std::vector<std::thread> thread2;

    return 0;
}