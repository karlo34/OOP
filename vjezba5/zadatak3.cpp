// zadatak3

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Song{
public:
    string title;
    string artist;
    int seconds;
    Song(string t, string a, int s) {
        title = t;
        artist = a;
        seconds = s;
    }
};


class  Album{
    string title;
    int year;
    vector<Song> songs;
    public:
    Album(string t, int y, Song first){
        title = t;
        year = y;
        songs.push_back(first);
    }
    bool add(Song s){
        for(const Song& song : songs){
            if(song.title == s.title){
                return 0;
            }
        }
        songs.push_back(s);
        return 1;
    }
    int duration() const{
        int total = 0;

        for(const Song& s : songs){
            total +=s.seconds;
        }
                return total;
    }
    void print() const {
        cout << title << " (" << year << "), "
             << songs.size() << " pjesme, ";

        int total = duration();

        int minutes = total / 60;
        int seconds = total % 60;

        cout << minutes << ":";

        if (seconds < 10) {
            cout << "0";
        }

        cout << seconds << endl;

        for (int i = 0; i < songs.size(); i++) {
            cout << "  " << i + 1 << ". "
             << songs[i].title << endl;
        }
    }
};


int main() {
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n';   // vec postoji
    a.print();

    return 0;
}
