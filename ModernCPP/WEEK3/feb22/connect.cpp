#include<iostream>
#include<memory>

class Connect {
public:
    // virtual destructor
    virtual ~Connect() {}
    virtual void use_BT_AUX() = 0; // Use interface seg principle
};

class AUX : public Connect {
public:
    void use_BT_AUX() override {
        std::cout << "GOD CONNECTED WITH AUX" << std::endl;
    }
};

class BT : public Connect {
public:
    void use_BT_AUX() override {
        std::cout << "GOD CONNECTED WITH BT" << std::endl;
    }
};

class Pannel {
protected:
    std::shared_ptr< Connect > plugin;
public:
    virtual ~Pannel() = default;
    virtual void usePlugin() = 0;
    void setConnect(std::shared_ptr< Connect > _plugin) {       
        plugin = _plugin;
    }    
};

class CellPhone : public Pannel {
public:
    void usePlugin() override {
        plugin->use_BT_AUX();
    }
};

class GoogleMaps : public Pannel {
public:
    void usePlugin() override {
        plugin->use_BT_AUX();
    }
};

int main() {

    std::cout << "Connecting BT AUX to the Media Pannel!\n";
    
    auto aux = std::make_shared< AUX >();
    auto bt = std::make_shared< BT >();

    auto mediaPlayer = std::make_unique< CellPhone >();
    
    mediaPlayer->setConnect( bt );
    mediaPlayer->usePlugin();
    
    mediaPlayer->setConnect( aux );
    mediaPlayer->usePlugin();



    return 0;
}