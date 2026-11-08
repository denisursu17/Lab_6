#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int CAPACITY = 100;
    double arr[CAPACITY];
    int n, mode;
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "LAB 6 | Variant 5 | Task 2\n";
    cout << "Array length (1..100): ";
    cin >> n;
    if (!cin || n < 1 || n > CAPACITY) {
        cout << "Incorrect array length.\n";
        return 1;
    }
    cout << "Input mode (1 - manual, 2 - random): ";
    cin >> mode;
    if (!cin || (mode != 1 && mode != 2)) {
        cout << "Incorrect input mode.\n";
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (mode == 1) {
            cout << "a[" << i + 1 << "] = ";
            cin >> arr[i];
            if (!cin) { cout << "Invalid number.\n"; return 1; }
        } else {
            arr[i] = (rand() % 401 - 200) / 10.0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nArray (position : value):\n";
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << i + 1 << " : " << setw(8) << arr[i] << '\n';
    }

    const double* first = arr;
    double minimum = *first;
    double maximum = *first;
    for (int i = 1; i < n; ++i) {
        const double* ptr = arr + i;
        if (*ptr < minimum) minimum = *ptr;
        if (*ptr > maximum) maximum = *ptr;
    }

    cout << "\nMinimum = " << minimum << '\n';
    cout << "Maximum = " << maximum << '\n';
    cout << "Product = " << minimum * maximum << '\n';
    return 0;
}
