#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::chrono::system_clock;
// namespace sysClock = std::chrono::system_clock;

int main() {
    cout << "Hello world: " << endl;
    auto timeNow = std::chrono::system_clock::now();
    auto nowSecond = std::chrono::system_clock::now();
    return 0;
}
