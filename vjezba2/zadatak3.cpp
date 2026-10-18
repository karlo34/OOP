#include <iostream>

template <typename T>
bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
bool descending(T a, T b) {
    return a > b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(arr[j], arr[i])) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int a[] = {5, 2, 8, 1, 4};
    double b[] = {3.5, 1.2, 4.8, 2.1};
    char c[] = {'z', 'a', 'm', 'b'};

    my_sort(a, 5, ascending<int>);
    my_sort(b, 4, ascending<double>);
    my_sort(c, 4, ascending<char>);

    std::cout << "Int uzlazno: ";
    for (int i = 0; i < 5; i++)
        std::cout << a[i] << " ";

    std::cout << "\nDouble uzlazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << b[i] << " ";

    std::cout << "\nChar uzlazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << c[i] << " ";

    my_sort(a, 5, descending<int>);
    my_sort(b, 4, descending<double>);
    my_sort(c, 4, descending<char>);

    std::cout << "\n\nInt silazno: ";
    for (int i = 0; i < 5; i++)
        std::cout << a[i] << " ";

    std::cout << "\nDouble silazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << b[i] << " ";

    std::cout << "\nChar silazno: ";
    for (int i = 0; i < 4; i++)
        std::cout << c[i] << " ";

    return 0;
}
