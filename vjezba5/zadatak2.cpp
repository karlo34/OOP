// Vjezba 5: klasa Clip ne radi ispravno.
//zadatak 2
// Ispravite je tako da program ispise: Concrete (Shame): 180 s

#include <iostream>
#include <string>
using namespace std;

class Clip {
    int start;
    int end;
    int length;
    string name;
    const int max_length = 600;
public:
    Clip(const string& name, int s, int e)
        : start(s), end(e), length(end - start)
    {
        this->name = name;
    };
    void print() const {
        cout << name << ": " << length << " s\n";
    }
};

int main()
{
    Clip c("Concrete (Shame)", 10, 190);
    c.print();
    return 0;
}
