#include <iostream>
#include <vector>
using namespace std;

void input_vector(vector<int>& v) {
    int x;
    cout << "Unosite brojeve (0 za kraj): ";

    while (cin >> x && x != 0) {
        v.push_back(x);
    }
}

void print_vector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;

    input_vector(v);

    cout << "Vektor: ";
    print_vector(v);

    cout << "Obrnuti redoslijed: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\nVektor bez reserve:\n";
    vector<int> a;

    for (int i = 1; i <= 20; ++i) {
        a.push_back(i);
        cout << "size = " << a.size()
             << ", capacity = " << a.capacity() << endl;
    }

    cout << "\nVektor s reserve(100):\n";
    vector<int> b;
    b.reserve(100);

    for (int i = 1; i <= 20; ++i) {
        b.push_back(i);
        cout << "size = " << b.size()
             << ", capacity = " << b.capacity() << endl;
    }

    b.shrink_to_fit();

    cout << "Kapacitet nakon shrink_to_fit(): "
         << b.capacity() << endl;

    return 0;
}
