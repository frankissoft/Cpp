#include <iostream>
#include <vector>
#include <chrono>
#include <utility>
#include <iomanip>


using namespace std;

int main() {
    // std::cout << std::fixed << std::setprecision(10) << std::endl;
    std::cout << std::fixed << std::setprecision(10) << std::endl;

    vector<int> myBigVec(10000000, 2011);
    std::vector<int> myEmptyVec1;
    std::vector<int> myEmptyVec2;

    auto begin = std::chrono::high_resolution_clock::now();
    myEmptyVec1 = myBigVec;
    auto end = std::chrono::high_resolution_clock::now() - begin;

    auto timeInSeconds = std::chrono::duration<double>(end).count();
    cout << "Copy time: " << timeInSeconds << '\n';

    begin = std::chrono::high_resolution_clock::now();
    myEmptyVec2 = move(myBigVec);
    end = std::chrono::high_resolution_clock::now() - begin;

    timeInSeconds = std::chrono::duration<double>(end).count();
    cout << "Move time: " << timeInSeconds << '\n';

    return 0;
}
