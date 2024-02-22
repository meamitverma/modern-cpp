#include <iostream>
 
template<typename... States>
class StateMachine{
    private:
    std::tuple<States...> states;
 
    public:
    StateMachine(States... args): states( std::make_tuple(std::move(args)...)){}
 
    void displayVariousStates(){
        std::cout<< "States..." << std::endl;
        displayStates<0>();  
        std::cout<<"\n";
    }
 
    template<size_t Index>
    void displayStates(){
        if constexpr(Index <sizeof...(States)){
            std::cout << typeid(std::get<Index>(states)).name() << " ";
            displayStates< Index + 1>();
        }
    }
};
 
struct NoCard{};
struct HasCard{};
struct HasPin{};
 
int main(){
    std::cout << "tuples states...\n";
 
    NoCard noCard;
    HasCard hasCard;
    HasPin hasPin;
 
    StateMachine<NoCard, HasCard, HasPin> sm(noCard,hasCard,hasPin);     //<NoCard, HasCard, HasPin> go in typename (template)
    sm.displayVariousStates();
 
}