#include <iostream>
#include <memory>

int main() {
    std::auto_ptr<int> ap1(new int(2011));
    std::auto_ptr<int> ap2 = ap1;

    std::unique_ptr<int> up1(new int(2011));
    // std::unique_ptr<int> up2 = up1;
    std::unique_ptr<int> up3 = std::move(up1);

    return 0;
}
