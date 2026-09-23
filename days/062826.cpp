#include <iostream> 
using namespace std; 


int main() { 
    //5 here is a LITERAL; cannot be changed throughout the running of the program
    cout << 5 << '\n'; 

    cout << "Enter a number please: " << '\n'; 
    cout << "Enter a second number please: " << '\n'; 

    int x, y; 
    
    cin >> x >> y; 

    cout << "Your first number is: " << x << " and your second number is: " << y << '\n';

    // Select line(s) of code then press 'ctrl + /' in order to instantly comment it out. 
    return 0; 
}
