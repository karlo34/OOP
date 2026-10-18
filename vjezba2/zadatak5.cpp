#include <iostream>

inline double add(double a, double b) {
    return a + b;
}

inline double subtract(double a, double b) {
    return a - b;
}

inline double multiply(double a, double b) {
    return a * b;
}

inline double divide(double a, double b) {
    return a / b;
}

int main() {
    double (*funkcije[4])(double, double) = {
        add, subtract, multiply, divide
    };

    double a, b;
    int operacija;

    std::cout << "Unesi dva broja: ";
    std::cin >> a >> b;

    std::cout << "Odaberi operaciju (0-zbrajanje, 1-oduzimanje, 2-mnozenje, 3-dijeljenje): ";
    std::cin >> operacija;

    if (operacija < 0 || operacija > 3) {
        std::cout << "Pogresna operacija!" << std::endl;
    }
    else if (operacija == 3 && b == 0) {
        std::cout << "Dijeljenje s nulom nije dozvoljeno!" << std::endl;
    }
    else {
        std::cout << "Rezultat: "
                  << funkcije[operacija](a, b) << std::endl;
    }

    return 0;
}

