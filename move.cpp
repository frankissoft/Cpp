#include <iostream>
#include <utility>
#include <vector>

using std::cout;

int main() {
    std::vector<int> myBigVec(1000000, 2011);
    std::vector<int> myVec;

    myVec = myBigVec;

    for (int i = 0; i < 100; i++) {
        std::cout << myVec[i] << ", ";
    }
    std::cout << '\n';

    myVec = std::move(myBigVec);

    for (int i = 0; i < 100; i++) {
        std::cout << myVec[i] << ", ";
    }
    std::cout << '\n';

    return 0;
}
