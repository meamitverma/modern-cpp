#include<iostream>
#include<thread>
#include<mutex>


int myCash = 0;
std::mutex m;

void addMoney() {
    m.lock();  // no thread can enter when locked

        ++myCash;
        std::cout << myCash << std::endl;

    m.unlock(); // unlocked, waiting thread can proceed
}

int main() {

    std::cout << "mutex \n";
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    return 0;
}