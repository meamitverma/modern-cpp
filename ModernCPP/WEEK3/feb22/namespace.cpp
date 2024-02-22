#include<iostream>

namespace Wifi_App_Versioning {

    namespace version_1 {

        void transmitPacket() {
            std::cout << "Transmiting Vim xyz protocol ver 1" << std::endl;
        }

    }

    namespace version_2 {

        void transmitPacket() {
            std::cout << "Transmiting Vim xyz protocol ver 2 depreciated" << std::endl;
        }

    }

    inline namespace version_3 {
        [[deprecated("use transmitPacket() version1")]]
        void transmitPacket() {
            std::cout << "Transmiting Vim xyz protocol ver 3 depreciated" << std::endl;
        }

        void transmitPacketVia() {
            std::cout << "Transmiting Vim s protocol ver 3 depreciated." << std::endl;
        }

    }
}

int main() {
    Wifi_App_Versioning::version_1::transmitPacket();
    Wifi_App_Versioning::transmitPacket();
    Wifi_App_Versioning::version_3::transmitPacket();
    return 0;
}


EngineManager
    .SubsribeOn( BackGroundScheduler )
    .ensureAllIOTisON()
    .observeOn( DashboardScheduler );