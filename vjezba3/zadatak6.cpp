#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_words(const string& text) {
    vector<string> words;
    size_t start = 0;

    while (start < text.size()) {
        start = text.find_first_not_of(' ', start);

        if (start == string::npos) {
            break;
        }

        size_t end = text.find(' ', start);

        if (end == string::npos) {
            words.push_back(text.substr(start));
            break;
        }

        words.push_back(text.substr(start, end - start));
        start = end + 1;
    }

    return words;
}

int main() {
    string recenica;

    cout << "Unesite recenicu: ";
    getline(cin, recenica);

    vector<string> rijeci = split_words(recenica);

    if (rijeci.empty()) {
        cout << "Nema rijeci." << endl;
        return 0;
    }

    string najdulja = rijeci[0];
    string prva = rijeci[0];

    for (const string& rijec : rijeci) {
        if (rijec.size() > najdulja.size()) {
            najdulja = rijec;
        }

        if (rijec < prva) {
            prva = rijec;
        }
    }

    cout << "Broj rijeci: " << rijeci.size() << endl;
    cout << "Najdulja: " << najdulja << endl;

    string obrnuto;

    for (auto it = rijeci.rbegin(); it != rijeci.rend(); ++it) {
        if (!obrnuto.empty()) {
            obrnuto += "-";
        }

        obrnuto += *it;
    }

    cout << obrnuto << endl;
    cout << "Prva po abecedi: " << prva << endl;

    return 0;
}

