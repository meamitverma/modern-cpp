#include<iostream>
#include<thread>
#include<future>
#include<vector>

int main() {

    std::thread t1([](){std::cout << "Thread 1 running" << std::endl;});
    std::thread t2([](){std::cout << "Thread 2 running" << std::endl;});
    std::thread t3([](){std::cout << "Thread 3 running" << std::endl;});


    std::vector<std::thread> threads{t1, t2, t3};

    return 0;
}