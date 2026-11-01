#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

vector<string> split_words(const string& recenica) {

    vector<string> rijeci;
    string rijec;

    stringstream ss(recenica);

    while (ss >> rijec) {
        rijeci.push_back(rijec);
    }

    return rijeci;
}

int main() {

    vector<string> rjecnik{
        "programski", "jezik", "c++", "je", "brz",
        "i", "mocan", "ali", "nije", "jednostavan",
        "za", "pocetnike"
    };

    sort(rjecnik.begin(), rjecnik.end());

    string recenica;

    cout << "Recenica: ";
    getline(cin, recenica);

    vector<string> rijeci = split_words(recenica);

    vector<string> nepoznate;

    for (string rijec : rijeci) {

        rijec.erase(
            remove_if(rijec.begin(), rijec.end(),
                [](char znak) {
                    return znak == ',' || znak == '.';
                }),
            rijec.end()
        );

        transform(rijec.begin(), rijec.end(), rijec.begin(),
            [](unsigned char znak) {
                return tolower(znak);
            });

        if (!binary_search(rjecnik.begin(), rjecnik.end(), rijec)) {
            nepoznate.push_back(rijec);
        }
    }

    cout << "nepoznatih rijeci: " << nepoznate.size();

    for (const string& rijec : nepoznate) {
        cout << " " << rijec;
    }

    cout << endl;

    return 0;
}
