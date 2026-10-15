// wow... it has been almost two weeks since i last coded.. 
#include <iostream>
#include <string>
#include <vector> 

enum class bookingStatus {
    Available,
    Reserved
};

class Seat {
    private: 
        int seatNumber;
        std::string row; 
        bookingStatus status; 
    
    public: 
        Seat(int seatNum, std::string rowNum, bookingStatus seatStatus) : seatNumber(seatNum), row(rowNum), status(seatStatus) {

        }

        int getSeatNumber() const {
            return seatNumber;
        }

        std::string getRow() const {
            return row; 
        }

        std::string returnStatus() const {
            switch(status) {
                case bookingStatus::Available:
                    return "Available";
            
                case bookingStatus::Reserved:
                    return "Reserved";
            }
            return " ";
        }

        void reserveSeat() {
            switch(status) { 
                case bookingStatus::Available:
                    status = bookingStatus::Reserved; 
                    std::cout << "Seat reserved." << '\n';
                    break;
                case bookingStatus::Reserved:
                    std::cout << "Sorry, this seat is already reserved." << '\n';
                    break;
            }
            
        }

        void cancelReservation() {
            switch(status) { 
                case bookingStatus::Available:
                    std::cout << "ERROR: this seat is already available." << '\n';
                    break;
                case bookingStatus::Reserved:
                    std::cout << "Canceling reservation..." << '\n';
                    status = bookingStatus::Available;
                    std::cout << "Reservation cancelled. " << '\n'; 
                    break;
            }
            
        }
        

};

class Theater { 
    private:
        std::vector<Seat> seats; 
    
    
    public: 
        Theater(std::vector<Seat> theaterSeats) : seats(theaterSeats) {
            
        }

        int checkSeat() const { 
            int userChoice = 0; 
            std::cout << "Which seat would you like to inspect? " << '\n';
            std::cin >> userChoice;
            while (std::cin.fail() || userChoice < 1 || userChoice > seats.size()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n'); 
                std::cout << "Choose a valid seat." << '\n';
                std::cin >> userChoice;
            }

            return userChoice;
        }

        void viewAllSeats() const { 
            if (seats.empty() == true) { 
                std::cout << "No seats to view." << '\n';
                return; 
            }
            for(const Seat& seat : seats) {
                std::cout << seat.getSeatNumber() << ". " << " Row " << seat.getRow() << " - " << seat.returnStatus() << '\n';
            }
        }

        void inspectSeat() const {
            if (seats.empty() == true) { 
                std::cout << "No seats to inspect." << '\n';
                return; 
            }

            
            int userChoice = checkSeat(); 
            std::cout << "Seat Number: " << seats[userChoice - 1].getSeatNumber() << '\n';
            std::cout << "Row: " << seats[userChoice - 1].getRow() << '\n';
            std::cout << "Availability: " << seats[userChoice - 1].returnStatus() << '\n';
        }
        
        void reserveSeat() { 
            if (seats.empty() == true) {
                std::cout << "No seats to reserve." << '\n';
            }

            int userChoice = checkSeat();

            seats[userChoice - 1].reserveSeat();
        }

        void cancelSeat() { 
            if (seats.empty() == true) {
                std::cout << "No seats to cancel." << '\n';
            }

            int userChoice = checkSeat();

            seats[userChoice - 1].cancelReservation();
        }

        void viewAvailableSeats() { 
            if (seats.empty() == true) { 
                std::cout << "No seats to view." << '\n';
                return; 
            }
            for(const Seat& seat : seats) {
                if (seat.returnStatus() == "Available") {
                    std::cout << seat.getSeatNumber() << ". " << " Row " << seat.getRow() << " - " << seat.returnStatus() << '\n';
                }
            }
        }
        



};

void enterTheater(Theater& theater) {

    int userChoice = 0;
    while(userChoice != 6) {
        std::cout << " === MOVIE THEATER === " << '\n';
        std::cout << "1. View All Seats" << '\n'; 
        std::cout << "2. Inspect Seat" << '\n'; 
        std::cout << "3. Reserve Seat" << '\n'; 
        std::cout << "4. Cancel Reservation" << '\n'; 
        std::cout << "5. View Available Seats" << '\n'; 
        std::cout << "6. Leave" << '\n'; 
        std::cin >> userChoice; 

        while (std::cin.fail() || userChoice < 1 || userChoice > 6) { 
            std::cin.clear();
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid menu option. Try again." << '\n'; 
            std::cin >> userChoice;
        }

        switch (userChoice) {
            case 1:
                theater.viewAllSeats(); 
                break;
            case 2:
                theater.inspectSeat();
                break;
            case 3: 
                theater.reserveSeat();
                break;
            case 4:
                theater.cancelSeat();
                break;
            case 5: 
                theater.viewAvailableSeats();
                break;
            case 6: 

                break; 
        }
    }

    std::cout << "Exiting theater..." << '\n';
    std::cout << "Theater exited." << '\n';
    
}

int main() {
    std::vector<Seat> theaterSeats = {{1, "A", bookingStatus::Available}, {2, "A", bookingStatus::Available},
                                      {3, "A", bookingStatus::Available}, {4, "A", bookingStatus::Available},
                                      {5, "B", bookingStatus::Available}, {6, "B", bookingStatus::Available},
                                      {7, "B", bookingStatus::Available}, {8, "B", bookingStatus::Available}};
    Theater theaterOne {theaterSeats};
    enterTheater(theaterOne); 
    return 0; 
}
