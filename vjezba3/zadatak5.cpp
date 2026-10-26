#include <iostream>
#include <string>
using namespace std;

string with_separators(string digits) {
    size_t start = 0;

    if (!digits.empty() && digits[0] == '-') {
        start = 1;
    }

    for (size_t i = digits.size(); i > start + 3; i -= 3) {
        digits.insert(i - 3, ".");
    }

    return digits;
}

string without_separators(string text) {
    size_t pos;

    while ((pos = text.find('.')) != string::npos) {
        text.erase(pos, 1);
    }

    return text;
}

int main() {
    string broj;

    cout << "Unesite cijeli broj: ";
    cin >> broj;

    cout << "S razdjelnicima: "
         << with_separators(broj) << endl;

    string tekst;

    cout << "Unesite broj s tockama: ";
    cin >> tekst;

    cout << "Bez razdjelnika: "
         << without_separators(tekst) << endl;

    return 0;
}

