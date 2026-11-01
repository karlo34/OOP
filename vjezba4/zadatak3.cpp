#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool starts_with(const string& s, const string& prefix) {
    return prefix.size() <= s.size() &&
           equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const string& s, const string& suffix) {
    return suffix.size() <= s.size() &&
           equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {

    vector<string> datoteke{
        "vjezba04.cpp",
        "slajdovi.pdf",
        "main.cpp",
        "README.md",
        "vjezba04.h",
        "notes.txt",
        "vjezba03.cpp"
    };

    int broj = count_if(datoteke.begin(), datoteke.end(),
        [](const string& ime) {
            return ends_with(ime, ".cpp");
        });

    cout << ".cpp datoteka: " << broj << endl;

    datoteke.erase(
        remove_if(datoteke.begin(), datoteke.end(),
            [](const string& ime) {
                return starts_with(ime, "vjezba");
            }),
        datoteke.end()
    );

    for (const string& ime : datoteke) {
        cout << ime << " ";
    }

    cout << endl;

    return 0;
}

