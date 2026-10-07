#include <iostream>

namespace geo {

    double PI = 3.14;

    double area(double r) {
        return r * r * PI;
    }

    double area(double a, double b) {
        return a * b;
    }

    int area(int a) {
        return a * a;
    }
}

void print_line(char c = '-', int length = 30) {
    for (int i = 0; i < length; i++) {
        std::cout << c;
    }
    std::cout << '\n';
}

int main() {
    std::cout << "area(5): " << geo::area(5) << '\n';
    print_line();
    std::cout << "area(5.0): " << geo::area(5.0) << '\n';
    print_line();
    std::cout << "area(2, 3): " << geo::area(2, 3) << '\n';
    print_line();
    std::cout << "area('A'): " << geo::area('A') << '\n';
    return 0;
}