#include<iostream>
#include<future> // async threads, promise
#include<thread>

void increment () {
    for (int i = 0; i < 100000; i++) {
        for (int i1 = 0; i1 < 100000; i1++) {

        }
    }
}

// int() -> function pointer
// anything given to packaged_task converted to asynchronous task
// we use std::packaged_task, which can be used to wrap any target called as async calls
std::packaged_task< int() > task ( []() {
    std::this_thread::sleep_for(std::chrono::seconds( 3 ));
    return 123;
});


int main() {

    std::future< int > handleResult = task.get_future();
    std::thread( std::move(task)).detach();
    std::cout << "Waiting" << std::endl;
    handleResult.wait();
    std::cout << "Done!" << " Future Result is " << handleResult.get() << std::endl;
    
    return 0;
}