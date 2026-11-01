#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Song {
    string title;
    string artist;
    int year;
    int plays;
};

void print_song(const Song& s) {
    cout << s.title << " - " << s.artist << " (" << s.year << "), " << s.plays << " slusanja" << endl;
}

int main() {
    vector<Song> pjesme = {
    {"Hit me baby one more time", "Britney Spears", 1998, 100},
    {"Remember the time", "Michael Jackson", 1992, 200},
    {"Moves like Jagger", "Maroon 5", 2011, 34},
    {"Gangnam style", "PSY", 2012, 68}
    };

    sort(pjesme.begin(), pjesme.end(),
    [](const Song& a, const Song& b) {
        if (a.year != b.year)
            return a.year < b.year;
        return a.title < b.title;
        }
    );

    for (const auto& s : pjesme) {
        print_song(s);
    }

    string autor;
    cout << "\nUpisi autora: ";
    getline(cin >> ws, autor);

    int broj = 0;
    int najstarija = -1;

    for (int i = 0; i < pjesme.size(); i++) {
        if (pjesme[i].artist == autor) {
            broj++;
            if (najstarija == -1 ||
            pjesme[i].year < pjesme[najstarija].year) {
            najstarija = i;
            }
        }
    }

    if (broj > 0) {
        cout << "\nBroj pjesama: " << broj << endl;
        cout << "Najstarija pjesma: ";
        print_song(pjesme[najstarija]);
    } else {
        cout << "\nTaj autor nema pjesama na popisu." << endl;
    }

    int najslusanija = 0;

    for (int i = 1; i < pjesme.size(); i++) {
        if (pjesme[i].plays > pjesme[najslusanija].plays) {
            najslusanija = i;
        }
    }

    cout << "\nNajslusanija pjesma: ";
    print_song(pjesme[najslusanija]);

    return 0;
}
