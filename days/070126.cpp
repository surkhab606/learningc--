#include <iostream>
using namespace std;

                                    //Let's say that you have two functions. Function A calls Function B and Function B
                                    //calls Function A. Which Function should you define first? You know that functions
                                    //need to be defined sequentially, i.e., it needs to be defined before it can be used. 
                                    //But in a case such as this, or when a f(x) is in a different file, where the order of
                                    //definitions is not known, use a f(x) prototype like on line 9. 
int add(int x, int y);              //it includes the return type, identifier, and parameters, but no f(x) body. Now you
                                    //can use the add function whenever.

void printHi() {
    cout << "Hello World" << '\n'; 
}

void doSomething(int) {             //THIS IS VALID. if for some reason you ever need to get rid of a parameter, but this would
                                    //break other function calls and make a lot of work, just do this. add just the type, with
                                    //no name. it will be valid, remove your paramter, but not break any of your f(x) calls. 

}

int doubleNumber(int x) { 

    return 2 * x; 

}

int add(int x, int y) {             //We can define it down here, or even below main. The compiler won't care. 
    return x + y; 
}



int main() { 
    printHi();                      //this is valid and will print out 'Hello World' 
    //cout << printHi() << '\n';    //THIS IS NOT VALID, because void functions return nothing and cout expects a value to print!
    
    return 0; 
}
