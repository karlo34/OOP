#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void input_vector(vector<int>& v) {
    int x;
    cout << "Unesite brojeve (0 za kraj): ";

    while (cin >> x && x != 0) {
        v.push_back(x);
    }
}

int main() {
    vector<int> v;

    int k = 0;
    input_vector(v);

    while (k <= 0) {
        cout << "k: ";
        cin >> k;
    }

    int negativni = count_if(v.begin(), v.end(),
        [](int broj) {
            return broj < 0;
        });

    cout << "negativnih: " << negativni << endl;

    auto prvi = find_if(v.begin(), v.end(),
        [k](int broj) {
            return broj % k == 0;
        });

    if (prvi != v.end()) {
        int pozicija = distance(v.begin(), prvi);

        cout << "prvi visekratnik od " << k << ": "
             << *prvi << " (pozicija " << pozicija << ")" << endl;
    }
    else {
        cout << "Nema visekratnika broja " << k << endl;
    }

    if (!v.empty()) {
        auto min = min_element(v.begin(), v.end());
        auto max = max_element(v.begin(), v.end());

        cout << "min " << *min
             << " (pozicija " << distance(v.begin(), min) << "), ";

        cout << "max " << *max
             << " (pozicija " << distance(v.begin(), max) << ")" << endl;
    }

    v.erase(
        remove_if(v.begin(), v.end(),
            [k](int broj) {
                return broj % k == 0;
            }),
        v.end()
    );

    cout << "bez visekratnika: ";

    for (int broj : v) {
        cout << broj << " ";
    }

    cout << endl;

    return 0;
}

