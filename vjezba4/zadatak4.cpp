#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const string& password) {

    PasswordInfo info;

    info.length = password.length();

    info.digits = count_if(password.begin(), password.end(),
        [](unsigned char znak) {
            return isdigit(znak);
        });

    info.uppercase = count_if(password.begin(), password.end(),
        [](unsigned char znak) {
            return isupper(znak);
        });

    info.special = count_if(password.begin(), password.end(),
        [](unsigned char znak) {
            return ispunct(znak);
        });

    return info;
}

bool is_strong(const PasswordInfo& info) {

    return info.length >= 10 &&
           info.digits >= 1 &&
           info.uppercase >= 1 &&
           info.special >= 1;
}

int main() {

    string password;

    cout << "Unesite lozinku: ";
    getline(cin, password);

    PasswordInfo info = analyze(password);

    cout << "duljina " << info.length
         << ", znamenke " << info.digits
         << ", velika " << info.uppercase
         << ", posebni " << info.special;

    if (is_strong(info)) {
        cout << " -> jaka" << endl;
    }
    else {
        cout << " -> slaba" << endl;
    }

    return 0;
}
