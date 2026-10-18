#include <iostream>

int twice(int x) {
    return x * 2;
}

void my_transform(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    my_transform(arr, n, twice);

    std::cout << "Udvostruceni brojevi: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    my_transform(arr, n, [](int x) {
        if (x % 2 == 0) {
            return x / 2;
        }
        else {
            return x * 2;
        }
    });

    std::cout << "\nNakon lambde: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    int suma = 0;
    int produkt = 1;

    [&]() {
        for (int i = 0; i < n; i++) {
            suma += arr[i];
            produkt *= arr[i];
        }
    }();

    std::cout << "\nSuma: " << suma;
    std::cout << "\nProdukt: " << produkt;

    int prag;
    int s = 0;

    std::cout << "\nUnesi prag: ";
    std::cin >> prag;

    [prag, &s, &arr, n]() {
        for (int i = 0; i < n; i++) {
            if (arr[i] > prag) {
                s += arr[i];
            }
        }
    }();

    std::cout << "Suma brojeva vecih od praga: " << s << std::endl;

    return 0;
}

