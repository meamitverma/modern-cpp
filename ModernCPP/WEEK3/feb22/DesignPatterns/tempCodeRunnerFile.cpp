#include<iostream>
#include<vector>
#include<algorithm>
 
class Observer;
 
class Subject{
    //virtual void attach();   //create a virtual class first and then implement in separate class
    public:
    std::vector<Observer*> views; //use reference wrapper instead
    int value;
    void attach(Observer* obs){
        views.emplace_back(obs);
    }
    void detach(Observer* obs){
       views.erase( std::remove(views.begin(), views.end(), obs),views.end() ); //somehting to check in this statement
    }
    //----state changes..registered users need to be modified
    void setValue(int val){
        value=val;
        notify();
    }
    int getValue(){
        return value;   
    }
    void notify();
};
 
class Observer{
    Subject* model;
    int denom;
 
    public:
    Observer(Subject* mod, int div){
        model=mod;
        denom=div;
 
        model->attach(this);
    }
    virtual void update()=0;
 
    protected:
 
    Subject* getSubject(){
        return model; //this
    }
    int getDivisor(){
        return denom;
    }
 
};
 
void Subject::notify(){
    for(int i=0; i<views.size(); i++){
        views[i]->update();
    }
}
class DivObserver : public Observer{
    public:
 
    DivObserver(Subject* mod, int div) : Observer(mod, div){}
 
    void update() override {
        int v = getSubject()->getValue(), d= getDivisor();
        std::cout<<v<<" / "<<d<<" is "<<v/d<<std::endl;
    }
};
 
class AddObserver : public Observer{
 
    public:
    AddObserver(Subject* mod, int div) : Observer(mod, div){}
 
    void update() override {
        int v = getSubject()->getValue(), d= getDivisor();
        std::cout<<v<<" + "<<d<<" is "<<v+d<<std::endl;
    }
};
 
int main(int argc, const char* argv[]){
    std::cout<<"Observer\n";
    Subject subj;
    DivObserver(&subj, 4);
    DivObserver(&subj, 3);
    AddObserver(&subj, 12);
    subj.setValue(14);
    
    return 0;
}
