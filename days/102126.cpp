#include <vector>
#include <iostream>
#include <string> 

enum class MonsterStatus { 
    Contained,
    Hurt,
    Unknown,
    Unleashed
};

enum class GeneralStatus { 
    OK,
    Unknown,
    WARNING, 
    DeathsConfirmed
};

enum class RoomType { 
    Biomedical,
    Engineering,
    Administrative, 
    Medical,
    VIP
};

class Monster { 
    private: 
        int health;
        std::string name; 
        int damage;
        MonsterStatus status; 
    
    public:
        Monster(int monsterHealth, std::string monsterName, int monsterDamage, MonsterStatus monsterStatus) : 
            health(monsterHealth), name(monsterName), damage(monsterDamage), status(monsterStatus) {
                if (health > 0) {
                    health = 0; 
                }
            }
        
        int getHealth() {
                return health;
        }

        std::string getName() {
            return name;
        }

        int getDamage() { 
            return damage; 
        }

        std::string statusToString() { 
            switch(status) { 
                case (MonsterStatus::Contained):
                    return "Asset: Contained"; 
                    break; 
                
                case (MonsterStatus::Hurt):
                    return "Asset: Hurt"; 
                    break; 
                
                case (MonsterStatus::Unknown):
                    return "Asset: Unknown"; 
                    break; 
                
                case (MonsterStatus::Unleashed):
                    return "Asset: Unleashed"; 
                    break; 
            }
        }

};

class Room { 
    private: 
        GeneralStatus roomStatus;
        RoomType type;
        int roomNumber;
    public: 
        Room (GeneralStatus status, RoomType roomType, int num) : 
            roomStatus(status), type(roomType), roomNumber(num) {

            }
        
        std::string roomStatusToString() { 
            switch(roomStatus) { 
                case (GeneralStatus::DeathsConfirmed):
                    return "Deaths Confirmed"; 
                    break; 
                
                case (GeneralStatus::OK):
                    return "OK"; 
                    break; 
                
                case (GeneralStatus::Unknown):
                    return "Unknown"; 
                    break; 
                
                case (GeneralStatus::WARNING):
                    return "WARNING"; 
                    break; 
            }
        }
        
        std::string roomTypeToString() { 
            switch(type) { 
                case (RoomType::Administrative):
                    return "Administrative"; 
                    break; 
                
                case (RoomType::Biomedical):
                    return "Biomedical"; 
                    break; 
                
                case (RoomType::Engineering):
                    return "Engineering"; 
                    break; 
                
                case (RoomType::Medical):
                    return "Medical"; 
                    break; 
                case (RoomType::VIP):
                    return "VIP";
                    break;
            }
        }

        int getRoomNumber() {
            return roomNumber;
        }
};

class Facility {
    private: 
        std::vector<Room> rooms {};
        int facilityNumber; 
        GeneralStatus facStatus; 
    public: 
        Facility (std::vector<Room> facRooms, int facNum, GeneralStatus status) :
            rooms(facRooms), facilityNumber(facNum), facStatus(status) {

            }
        
        void scanAllRooms() {
            for (Room room : rooms) {
                std::cout << "Room " << room.getRoomNumber() << '\n';
                std::cout << "Block: " << room.roomTypeToString() << '\n';
                std::cout << "Status: " << room.roomStatusToString() << '\n';
                std::cout << " ------------------ " << '\n';
            }
        }

        void inspectRoom() {
            int userChoice = 0;
            std::cout << "ENTER ROOM # TO INSPECT: " << '\n';
            std::cin >> userChoice; 
            while (std::cin.fail() || userChoice < 1 || userChoice > rooms.size()) {
                std::cout << "INVALID ROOM NUMBER. PLEASE TRY AGAIN: " << '\n';
                std::cin >> userChoice;
            }

            std::cout << "Room " << rooms[userChoice - 1].getRoomNumber() << '\n';
            std::cout << "Block: " << rooms[userChoice - 1].roomTypeToString() << '\n';
            std::cout << "Status: " << rooms[userChoice - 1].roomStatusToString() << '\n';
        }

        




        
};

void controlFacility(Monster& monster, Facility& facility) {
    int userChoice = 0;
    while (userChoice != 6) {
        std::cout << " ==== COMPURISE | FACILITY MGMT SOFTWARE ===" << '\n';
        std::cout << " 1. SCAN ALL ROOMS" << '\n';
        std::cout << " 2. INSPECT ROOM" << '\n';
        std::cout << " 3. ASSET STATUS" << '\n';
        std::cout << " 4. MANAGE ASSET" << '\n';
        std::cout << " 5. MANUAL RESET" << '\n';
        std::cout << " 6. EXIT" << '\n';
        std::cin >> userChoice;

        while (std::cin.fail() || userChoice < 1 || userChoice > 6) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "INVALID OPTION. PLEASE TRY AGAIN. " << '\n';
            std::cin >> userChoice;
        }

        switch (userChoice) {
            case 1: 
                facility.scanAllRooms();
                break;
            case 2: 
                facility.inspectRoom();
                break;
            case 3: 
                monster.statusToString(); 
                break;
            case 4: 

                break;

            // COMPURISE NOTES: IN CASE OF A 'LOST' OR 'UNCONTAINABLE' FACILITY, YOU MAY 
            // RESET THE STATUS OF ALL ROOMS WITHIN THE FACILITY IN ORDER TO ALLEVIATE
            // SHAREHOLDER DEMANDS.
            case 5: 
                break;
            case 6: 
                break;
        }
    }

    std::cout << "GOODBYE." << '\n';
}

int main() { 
    std::vector<Room> facRooms = {{GeneralStatus::OK, RoomType::Administrative, 1},
                                  {GeneralStatus::DeathsConfirmed, RoomType::Biomedical, 2},                         
                                  {GeneralStatus::Unknown, RoomType::Engineering, 3},
                                  {GeneralStatus::Unknown, RoomType::Engineering, 4},
                                  {GeneralStatus::WARNING, RoomType::VIP, 5}};

    Facility fac1 {facRooms, 1, GeneralStatus::DeathsConfirmed};
    Monster zekrom {100, "Zekrom", 150, MonsterStatus::Unleashed};
    controlFacility(zekrom, fac1); 
    return 0; 
}
