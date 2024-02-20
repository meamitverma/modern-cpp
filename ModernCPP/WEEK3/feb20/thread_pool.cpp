
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <functional>
#include <future>
using namespace std ;

class ThreadPool{
    
    private :
    std::vector< std::thread >           workers     ;
    std::queue< std::function< void() >> queuedTasks ;
    std::mutex                           queueMutex  ;
    std::condition_variable              condition   ;
    
    bool                                stop         ;
    
    
    public :
    
    ThreadPool( size_t numThreads ) : stop( false ){
        for( size_t i = 0 ; i < numThreads ; ++i ){
            cout << " ------ "<< i << " Thread created " << endl;
            workers.emplace_back(
                                 [ this ]{
                                     while( true ){
                                         std::function< void() > pullAsynctaskFromQueueToExecute;
                                         {
                                             //***-> gets fired when we are  notify from the queue
                                             std::unique_lock< std::mutex> lock( queueMutex);
                                             condition.wait(lock, [ this ]{ return stop || !queuedTasks.empty(); });
                                             if( stop && queuedTasks.empty()) return ;
                                             
                                             pullAsynctaskFromQueueToExecute = std::move( queuedTasks.front() );
                                             queuedTasks.pop();
                                             
                                         }
                                         cout << "State : Lambda is ready for the execution " << endl ;
                                         pullAsynctaskFromQueueToExecute();
                                     }// while( true )
                                 }// lambda
                                 );  // workers.emplace_back
        }// for
    } // ThreadPool Constructor
    
    template<typename F , typename... Args>
    auto enqueue(F&& f , Args&&... args) ->  std::future< typename std::invoke_result< F, Args...> ::type>
    {
        using returnType = typename std::invoke_result< F, Args...>::type;
        
        
       // std::bind(  std::forward<F>(f) ,std::forward< Args >( args)... ) );
        
//      auto x =   std::make_shared< std:: packaged_task< returnType>>
//        ( std::bind(
//          std::forward<F>(f), std::forward<Args>(args)...));
        
        cout << " State : Lambda invoked " << endl ;
        auto prepareAsyncTask = std::make_shared< std::packaged_task< returnType() >> (
            std::bind( std::forward< F >( f ) , std::forward< Args >( args)... ));
        
        // lets get the handle of our async task..
        std::future< returnType > result = prepareAsyncTask->get_future();
        {
            std::cout << "State : Lambda is prepared for execution "<< endl ;
            std::unique_lock<std::mutex> lock( queueMutex );
            if( stop ) throw std::runtime_error("Enqueue on stoped thread pool");
            
            queuedTasks.emplace( [ prepareAsyncTask ] () { ( *prepareAsyncTask)(); });
            condition.notify_one();
            return  result ;
            
        }
        
        
        
    }// end of enqueue
    
    ~ThreadPool(){
        {
            std::unique_lock<std::mutex > lock( queueMutex);
            stop = true ;
        }
        condition.notify_all();
        for( std::thread& worker : workers ){
            worker.join();
        }
    }  //~ThreadPool closing
    
}; // End of the ThreadPool

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Thread Pool!\n";
    ThreadPool pool( 4 );
    auto task1 =  pool.enqueue([](){cout << "Task 1 executed..." << endl ; });
    auto task2 =  pool.enqueue([](){cout << "Task 2 executed..." << endl ; });
    
    auto task3 =  pool.enqueue([](int a, int b ){cout << "Task 3 executed..." << a+b << endl ; }, 10,20);
    
      [](){cout << "Hey there! ";}();
    
    
    return 0;
}
