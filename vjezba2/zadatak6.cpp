#include <iostream>
#include <string>

struct Student {
    std::string ime;
    std::string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void ispis(Student& s) {
    std::cout << s.ime << " " << s.jmbag << " "
              << s.godina << ". godina, "
              << s.ects << " ECTS, prosjek: "
              << s.prosjek << std::endl;
}

void povecaj_godinu(Student& s) {
    s.godina++;
}

void filter_students(Student s[], int n,
                     void (*action)(Student&),
                     bool (*cond)(const Student&)) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

int main() {
    Student studenti[5] = {
        {"Ana", "001", 1, 30, 4.2},
        {"Ivan", "002", 1, 0, 3.0},
        {"Marko", "003", 2, 50, 3.8},
        {"Maja", "004", 3, 45, 3.2},
        {"Petra", "005", 2, 40, 4.5}
    };

    std::cout << "Studenti prve godine koji su polozili barem jedan ispit:\n";

    filter_students(studenti, 5, ispis,
        [](const Student& s) {
            return s.godina == 1 && s.ects > 0;
        });

    std::cout << "\nStudenti s prosjekom vecim od 3.5:\n";

    filter_students(studenti, 5, ispis,
        [](const Student& s) {
            return s.prosjek > 3.5;
        });

    filter_students(studenti, 5, povecaj_godinu,
        [](const Student& s) {
            return s.ects >= 45;
        });

    std::cout << "\nStudenti nakon povecanja godine:\n";

    for (int i = 0; i < 5; i++) {
        ispis(studenti[i]);
    }

    return 0;
}
