#include<iostream>
#include<future>
#include<vector>
#include<functional>
#include<condition_variable>

enum class ThreadState {
    Running, 
    Completed, 
    Errored
};

void run_with_callback( const std::function< void( ThreadState )>& callback, size_t threadNumber) {
    std::thread t( [callback](){
        try {
            callback(ThreadState::Completed);
        
        }
        catch (...) {
            callback( ThreadState::Errored);
        }
 
    });

    // Report task is running
        
        callback(ThreadState::Running);
        t.join();
}

int main() {

    std::vector< std::future< ThreadState >> futures;

    auto callback = []( ThreadState state, size_t threadNum ) {
        switch( state ){
            case  ThreadState::Running:
                std::cout << "Thread " << threadNum << " is Running" << std::endl;
                break;
            case  ThreadState::Completed:
                std::cout << "Thread " << threadNum << " is Completed" << std::endl;
                break;
            case  ThreadState::Errored:
                std::cout << "Thread " << threadNum << " Errored" << std::endl;
                break;
        }
    };

    for (int i = 0; i < 5; i++) {
        decltype( auto ) f  = std::async( std::launch::async, run_with_callback, callback);
    }

    for (auto &f : futures) {
        auto state = f.get();
        callback( state );
    }

    return 0;
}