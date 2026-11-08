#include <iostream>
#include <set>

int main() { 
    int N = 0; 
    std::cin >> N; 
    std::set<int> distinctNums;

    for (int i = 0; i < N; i++) {
        int currentNum = 0;
        std::cin >> currentNum;
        distinctNums.insert(currentNum);
    }

    std::cout << distinctNums.size();


    return 0;

}
