#include <iostream>
#include <array>
using namespace std;

constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours) {
    double sum = 0;

    for (double h : hours) {
        sum += h;
    }

    return sum;
}

int best_day(const array<double, DAYS>& hours) {
    int best = 0;

    for (int i = 1; i < DAYS; ++i) {
        if (hours[i] > hours[best]) {
            best = i;
        }
    }

    return best + 1;
}

int main() {
    array<double, DAYS> tjedan1;
    array<double, DAYS> tjedan2;

    cout << "Unesite sate ucenja za 7 dana:\n";

    for (int i = 0; i < DAYS; ++i) {
        cin >> tjedan1[i];
    }

    cout << "Ukupno sati prvog tjedna: "
         << total(tjedan1) << endl;

    cout << "Dan s najvise sati ucenja: "
         << best_day(tjedan1) << endl;

    tjedan2.fill(1.5);

    cout << "\nUkupno sati drugog tjedna: "
         << total(tjedan2) << endl;

    cout << "Tjedni su jednaki: "
         << (tjedan1 == tjedan2 ? "da" : "ne") << endl;

    cout << "Prvi tjedan je manji od drugog: "
         << (tjedan1 < tjedan2 ? "da" : "ne") << endl;

    swap(tjedan1, tjedan2);

    cout << "\nNakon swap:\n";
    cout << "Ukupno sati prvog tjedna: "
         << total(tjedan1) << endl;

    cout << "Ukupno sati drugog tjedna: "
         << total(tjedan2) << endl;

    return 0;
}
