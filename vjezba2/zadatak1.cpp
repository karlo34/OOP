
#include <iostream>
#include <string>
using namespace std;

#define MAX(a, b) a > b ? a : b
#define MAX2(a, b) ((a) > (b) ? (a) : (b))

inline int my_max(int a, int b) {
    return a > b ? a : b;
}

template <typename T>
T my_max_template(T a, T b) {
    return a > b ? a : b;
}

int main() {
    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;

    cout << "Originalni makro:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    int d = MAX2(3, 5);
    int e = 2 * MAX2(3, 5);
    int f = MAX2(3, 5) + 1;

    cout << "\nPopravljeni makro:" << endl;
    cout << "d = " << d << endl;
    cout << "e = " << e << endl;
    cout << "f = " << f << endl;

    int i = 3;
    int rezultat1 = MAX(++i, 2);

    cout << "\nOriginalni MAX:" << endl;
    cout << "rezultat = " << rezultat1 << endl;
    cout << "i = " << i << endl;

    int j = 3;
    int rezultat2 = my_max(++j, 2);

    cout << "\nInline my_max:" << endl;
    cout << "rezultat = " << rezultat2 << endl;
    cout << "j = " << j << endl;

    cout << "\nTemplate:" << endl;

    cout << my_max_template(3, 7) << endl;
    cout << my_max_template(2.5, 4.7) << endl;
    cout << my_max_template('A', 'Z') << endl;
    cout << my_max_template(string("jabuka"), string("kruska")) << endl;

    return 0;
}

