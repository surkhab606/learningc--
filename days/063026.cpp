#include <iostream>
using namespace std; 

int main() {
    //int x { 5 };                // this is a literal. 5 will be placed in the .exe and CANNOT be changed
    //int y;                      // whatever value y ends up being will be placed in MEMORY, thus it CAN be changed.
 
    //cout << 1 + 2 << '\n';      // this works! will print 3 

    cout << "Enter a number: "; 
    int userFirstNum {}; 
    cin >> userFirstNum; 

    cout << "Enter a second number: "; 
    int userSecondNum {}; 
    cin >> userSecondNum; 

    cout << userFirstNum << " + " << userSecondNum << " is " << userFirstNum + userSecondNum << '\n';
    cout << userFirstNum << " - " << userSecondNum << " is " << userFirstNum - userSecondNum << '\n';



    return 0; 
}
