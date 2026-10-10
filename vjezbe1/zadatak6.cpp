#include <iostream>
using namespace std;

int nzd(int a, int b) {
    while (b != 0) {
        int ostatak = a % b;
        a = b;
        b = ostatak;
    }
    return a;
}

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {
        int n = nzd(numerator, denominator);

        numerator = numerator / n;
        denominator = denominator / n;
    }

    double value() {
        return (double)numerator / denominator;
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

Fraction sum(const Fraction& a, const Fraction& b) {
    Fraction c;

    c.numerator = a.numerator * b.denominator
                + b.numerator * a.denominator;

    c.denominator = a.denominator * b.denominator;

    c.reduce();

    return c;
}

int main() {
    Fraction a = {1, 2};
    Fraction b = {1, 4};

    cout << "Prvi razlomak: ";
    a.print();

    cout << "Decimalna vrijednost: " << a.value() << endl;

    cout << "Drugi razlomak: ";
    b.print();

    Fraction c = sum(a, b);

    cout << "Zbroj: ";
    c.print();

    return 0;
}
