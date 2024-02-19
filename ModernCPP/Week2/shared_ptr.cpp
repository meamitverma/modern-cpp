//Shared pointer
//imp for state machine code
#include<memory>
#include<bits/stdc++.h>
class MyClass : public std::enable_shared_from_this< MyClass>{
    // private:
    // void print(){
    //     std::cout << "Hello I'm in MyClass"<<std::endl;
    // }
    
    public:
    int32_t i = 123;
    MyClass2 myclass2;
    std::shared_ptr< MyClass> getShared(){
        //return(*this);
        return shared_from_this();
    }
    void print(){
        std::cout << "Hello I'm in MyClass"<<std::endl;
    }
    void getvarandObject(){
        i = 567;
        std::cout<< "getvarandObject " << i  << std::endl;
        myclass2.printofclass2();
    }
};
 
class MyClass2{
    public:
    void printofclass2(){
        std::cout << "Haaaaallo I'm in MyClass2"<<std::endl;
    }
};
 
int main(int argc, const char * argv[]){
    std::cout<< " Enable shared ptr..!\n"<<std::endl;
    std::shared_ptr< MyClass > obj = std::make_shared< MyClass >();
    std::shared_ptr< MyClass > sharedobj = obj->getShared();
    sharedobj->print();
    sharedobj->myclass2.printofclass2();
    /*
    use getvarandobject when print func is private...
    sharedobj->getvarandObject();
    */
 
    return 0;
}