#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Broj dana: ";
    cin >> n;

    if (n <= 0) {
        cout << "Broj dana mora biti pozitivan." << endl;
        return 0;
    }

    vector<double> temperature(n);

    for (int i = 0; i < n; ++i) {
        cin >> temperature[i];
    }

    vector<double> promjene;
    promjene.reserve(n - 1);

    for (auto it = temperature.begin() + 1;
         it != temperature.end(); ++it) {
        promjene.push_back(*it - *(it - 1));
    }

    cout << "Promjene: ";
    for (double x : promjene) {
        cout << x << " ";
    }
    cout << endl;

    temperature.resize(7, temperature.back());

    cout << "Izvjestaj: ";
    for (double x : temperature) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> a(5);
    vector<int> b{5};

    cout << "\nBroj elemenata vektora a: " << a.size() << endl;
    cout << "Broj elemenata vektora b: " << b.size() << endl;

    return 0;
}
