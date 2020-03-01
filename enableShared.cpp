#include <iostream>
#include <memory>

using std::cout;

class ShareMe: public std::enable_shared_from_this<ShareMe> {
public:
    std::shared_ptr<ShareMe> getShared() {
        return shared_from_this();
    }
};

int main() {
    std::shared_ptr<ShareMe> shareMe(new ShareMe);
    std::shared_ptr<ShareMe> shareMe1 = shareMe -> getShared();

    cout << (void*)shareMe.get() << '\n';
    cout << (void*)shareMe1.get() << '\n';
    cout << shareMe.use_count() << '\n';

    return 0;
}
