#include<iostream>
#include<future>

// void threadFun( std::promise< int > &prom) {
void threadFun( std::promise< int > &&prom) {

    std::this_thread::sleep_for(std::chrono::seconds( 3 ));
    prom.set_value( 393 ); // rValue

}

int main() {

    std::cout << "Future promise! \n";
    std::promise< int > myPromise;
    std::future< int > handleToFuture = myPromise.get_future();
    std::cout << "Fire the thread" << std::endl;

    // std::thread t1{threadFun, std::ref(myPromise)};
    std::thread t1{threadFun, std::move(myPromise)};
    std::cout << "In main thread " << handleToFuture.get() << std::endl;
    t1.join();
    std::cout << "End of my code" << std::endl;

    return 0;
}