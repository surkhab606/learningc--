#include <iostream>
#include <string>
#include <vector>

enum class RunwayStatus { 
    Open,
    Occupied, 
    Closed
};

class Runway { 
    private:
        RunwayStatus status; 
        std::string letter; 
    public: 
        Runway(RunwayStatus runwayStatus, std::string runwayLetter) : status(runwayStatus), letter(runwayLetter) {

        }

        std::string statusToString() const {
            switch(status) { 
                case (RunwayStatus::Closed): 
                    return "Closed"; 
                case (RunwayStatus::Open): 
                    return "Open"; 
                case (RunwayStatus::Occupied): 
                    return "Occupied";  
            }

            return "";
        }


        std::string getRunwayLetter() const {
            return letter;
        }

        std::string getRunwayStatus() const {
            return statusToString(); 
        }

        void assignAircraft() { 
            switch(status) {
                case (RunwayStatus::Closed): 
                    std::cout << "ERROR1: WARNING! RUNWAY CLOSED. CANNOT PERFORM ACTION." <<'\n'; 
                    break;
                case (RunwayStatus::Open): 
                    std::cout << "Assigned aircraft to runway." <<'\n'; 
                    status = RunwayStatus::Closed;
                    break;
                case (RunwayStatus::Occupied): 
                    std::cout << "ERROR2: *EXTREME DANGER* RUNWAY OCCUPIED!" <<'\n'; 
                    std::cout << "NO ACTIONS PERFORMED." <<'\n'; 
                    break;
            }
        }

        void clearOccupiedRunway() {
            switch(status) {
                case (RunwayStatus::Closed): 
                    std::cout << "ERROR1: WARNING! RUNWAY CLOSED. CANNOT PERFORM ACTION." <<'\n';
                    break;
                case (RunwayStatus::Open): 
                    std::cout << "ERROR3: RUNWAY OPEN. CANNOT PERFORM ACTION." <<'\n'; 
                    break;

                case (RunwayStatus::Occupied): 
                    std::cout << "Clearing unoccupied runway..." <<'\n'; 
                    status = RunwayStatus::Open; 
                    std::cout << "Runway unoccupied." <<'\n'; 
                    break;
            }
        }

        void closeRunway() {
            switch(status) {
                case (RunwayStatus::Closed): 
                    std::cout << "ERROR1: WARNING! RUNWAY CLOSED. CANNOT PERFORM ACTION." <<'\n';
                    break;
                case (RunwayStatus::Open): 
                    std::cout << "Closing runway..." <<'\n'; 
                    status = RunwayStatus::Closed; 
                    std::cout << "Runway closed." <<'\n'; 
                    break;


                case (RunwayStatus::Occupied): 
                    std::cout << "ERROR2: *EXTREME DANGER* RUNWAY OCCUPIED!" <<'\n'; 
                    std::cout << "NO ACTIONS PERFORMED." <<'\n'; 
                    break;
            }
        }

        void openRunway() {
            switch(status) {
                case (RunwayStatus::Closed): 
                    std::cout << "Opening runway..." <<'\n'; 
                    status = RunwayStatus::Open; 
                    std::cout << "Runway opened." <<'\n'; 
                    break;
                case (RunwayStatus::Open): 
                    std::cout << "ERROR3: RUNWAY OPEN. CANNOT PERFORM ACTION." <<'\n'; 
                    break;

                case (RunwayStatus::Occupied): 
                    std::cout << "ERROR2: *EXTREME DANGER* RUNWAY OCCUPIED!" <<'\n'; 
                    std::cout << "NO ACTIONS PERFORMED." <<'\n'; 
                    break;
            }
        }

};

class Airport {
    private:
        std::vector<Runway> runways; 
    public:
        Airport(std::vector<Runway> airportRunways) : runways(airportRunways) {

        }

        int checkRunway() const { 
            int userChoice = 0; 
            std::cout << "Which runway would you like to inspect? (A = 1, B = 2, ...)" << '\n';
            std::cin >> userChoice;
            while (std::cin.fail() || userChoice < 1 || userChoice > runways.size()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                std::cout << "Choose a valid runway number." << '\n';
                std::cin >> userChoice;
            }

            return userChoice;
        }

        void viewAllRunways() const {
            for(const Runway& runway : runways) {
                std::cout << "Runway " << runway.getRunwayLetter() << '\n';
                std::cout << "Runway " << runway.getRunwayStatus() << '\n';
                std::cout << '\n';
            }
        }

        void inspectRunway() const {
            if (runways.empty() == true) { 
                std::cout << "No runways to inspect." << '\n';
                return; 
            }

            
            int userChoice = checkRunway(); 
            std::cout << "Runway Letter: " << runways[userChoice - 1].getRunwayLetter() << '\n';
            std::cout << "Status: " << runways[userChoice - 1].getRunwayStatus() << '\n';
        }
        
        void assignAircraftToRunway() {
            if (runways.empty() == true) { 
                std::cout << "No runways to assign." << '\n';
                return; 
            }

            int userChoice = checkRunway(); 
            runways[userChoice - 1].assignAircraft(); 
        }

        void clearOccupiedRunway() {
            if (runways.empty() == true) { 
                std::cout << "No runways to clear." << '\n';
                return; 
            }

            int userChoice = checkRunway(); 
            runways[userChoice - 1].clearOccupiedRunway(); 
        }

        void closeRunway() {
            if (runways.empty() == true) { 
                std::cout << "No runways to close." << '\n';
                return; 
            }

            int userChoice = checkRunway(); 
            runways[userChoice - 1].closeRunway(); 
        }

        void reOpenRunway() {
            if (runways.empty() == true) { 
                std::cout << "No runways to re-open." << '\n';
                return; 
            }

            int userChoice = checkRunway(); 
            runways[userChoice - 1].openRunway(); 
        }

        
};

void enterAirportMenu(Airport& airport) { 
    int userChoice = 0;
    while (userChoice != 7) {
        std::cout << " === ManageAir3D: AIRPORT RUNWAY CONTROL SOFTWARE === " << '\n';
    std::cout << " Option 1. View All Runways" << '\n';
    std::cout << " Option 2. Inspect Runway" << '\n';
    std::cout << " Option 3. Assign Aircraft To Runway" << '\n';
    std::cout << " Option 4. Clear Occupied Runway" << '\n';
    std::cout << " Option 5. Close Runway" << '\n';
    std::cout << " Option 6. Reopen Runway" << '\n';
    std::cout << " Option 7. Exit Software" << '\n';
    std::cin >> userChoice;

    while (std::cin.fail() || userChoice < 1 || userChoice > 7) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please input a valid menu option." <<'\n';
        std::cin >> userChoice; 
    }

    switch (userChoice) {
        case 1:
            airport.viewAllRunways(); 
            break;
        case 2:
            airport.inspectRunway();
            break;
        case 3:
            airport.assignAircraftToRunway(); 
            break;
        case 4:
            airport.clearOccupiedRunway(); 
            break;
        case 5:
            airport.closeRunway();
            break;  
        case 6:
            airport.reOpenRunway(); 
            break;
        case 7:
            break;
        }
    }
    
    std::cout << "Goodbye." << '\n';
}   

int main() {
    std::vector<Runway> runways = {{RunwayStatus::Closed, "A"}, {RunwayStatus::Open, "B"},
                                   {RunwayStatus::Occupied, "C"}, {RunwayStatus::Occupied, "D"},
                                   {RunwayStatus::Open, "E"}};
    Airport airport {runways};
    enterAirportMenu(airport); 
    return 0; 

}


