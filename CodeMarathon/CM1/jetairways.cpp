// AMIT KUMAR VERMA
// 219379

#include <bits/stdc++.h>
using namespace std;
 
class JetAir; // Forward declaration
 
// Observer interface
class FlightObserver
{
public:
    virtual void flightOnTime() = 0;
    virtual void flightDelayed() = 0;
};
 
class JetAir
{
private:
    vector<class FlightObserver *> observers;
 
public:
    void registerObserver(FlightObserver *observer)
    {
        observers.emplace_back(observer);
    }
 
    void unregisterObserver(FlightObserver *observer)
    {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
        {
            observers.erase(it);
        }
    }
 
    void setState(int state)
    {
        notify(state);
    }
 
    void notify(int state)
    {
        for (auto observer : observers)
        {
            if (state)
            {
                observer->flightOnTime();
            }
            else
            {
                observer->flightDelayed();
            }
        }
    }
};
 
// Base class for users
class User : public FlightObserver
{
private:
    string name;
 
public:
    User(const string &userName) : name(userName)
    {
        cout << name << " object created." << endl;
    }
 
    // Implement FlightObserver interface
    void flightOnTime() override
    {
        cout << name << ": Flight on Time." << endl;
    }
 
    void flightDelayed() override
    {
        cout << name << ": Flight Delayed." << endl;
    }
};
 
int main(int argc, const char *argv[])
{
    cout << "Welcome to Jet Airway" << endl;
    JetAir jetAir;
 
    // Create users
    User arun("Arun");
    User venkatesh("Venkatesh");
    User suresh("Suresh");
 
    // Register users with JetAir
    jetAir.registerObserver(&arun);
    jetAir.registerObserver(&venkatesh);
    jetAir.registerObserver(&suresh);
 
    jetAir.setState(0); // Flight delayed
 
    // Unregister Arun
    jetAir.unregisterObserver(&arun);
 
    return 0;
}