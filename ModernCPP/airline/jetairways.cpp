#include<iostream>
#include<vector>
#include<algorithm>

// Implementation
// 1. Create a interface iFlightStatus for communication across class
// 2. Create a JetAirways  which will reg and communicate with users
// 3. Create a customer class You Me and others
// 4. Lets have a vector to store the user credentials in JetAIr
// 5. When ever the state of JetAir changes ( Pilot on leave or weather is bad or runway is bad, etc.) 0 / 1
// 6. Notify all the users
/*
    notifuUsers() {
        for (user : users) {
            user->notify();
        }
    }
*/

// std::vector< iFlightStatus > users
// users.emplace_back (pratham);
// users.emplace_back (suresh);
// users.emplace_back (virpaksh);


class iFlightStatus {
    public:
    virtual void flightOnTime() = 0;
    virtual void flightDelayed() = 0;
};

class JetAirways {
    private:
    std::vector< iFlightStatus* > users;

    public:
    // register
    void _register(iFlightStatus *iFlightUser ) {
        users.emplace_back( iFlightUser );
    }

    // unregister
    void unregister(iFlightStatus *iFlightUser) {
        auto it = std::find(users.begin(), users.end(), iFlightUser);
        // user found
        if (it != users.end()) {
            // delete the element
            users.erase(it);
        }
    }

    // setState
    void setState(int state) {
        notify(state);
    }

    // notify
    void notify(int state) {
        if (state) {
            for (auto cUser : users) {
                cUser->flightOnTime();
            }
        }
        else {
            for (auto cUser : users) {
                cUser->flightDelayed();
            }
        }
    }

    int getUsers() {
        return users.size();
    }

};


// customers
class Suresh : public iFlightStatus {
    public:
    Suresh() {
        std::cout << "Suresh object created." <<  std::endl;
    }
    void flightOnTime() override{
        std::cout << "Flight on Time." << std::endl;
    }
    void flightDelayed() override{
        std::cout << "Flight Delayed" << std::endl;
    }
};
class Arun : public iFlightStatus {
    public:
    Arun() {
        std::cout << "Arun object created." <<  std::endl;
    }

    void flightOnTime() override{
        std::cout << "Flight on Time." << std::endl;
    }
    void flightDelayed() override{
        std::cout << "Flight Delayed" << std::endl;
    }
};
class Venkatesh : public iFlightStatus {
    public:
    Venkatesh() {
        std::cout << "Venkatesh object created." <<  std::endl;
    }
    void flightOnTime() override{
        std::cout << "Flight on Time." << std::endl;
    }
    void flightDelayed() override{
        std::cout << "Flight Delayed" << std::endl;
    }
};


int main() {

    std::cout << "Welcome to the Jet Airway" << std::endl;
    JetAirways jetair;
    Arun arun;
    Venkatesh venkatesh;
    Suresh suresh;

    jetair._register(&arun);
    jetair._register(&suresh);
    jetair._register(&venkatesh);

    jetair.setState(0); // Pilot
    jetair.getUsers();

    return 0;
}