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

    cout << "LAB 6 | Variant 5 | Task 1\n";
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
        cout << setw(3) << i + 1 << " : " << setw(8) << arr[i] << "\n";
    }

    double sum = 0.0;
    cout << "\nValues at odd positions (1, 3, 5, ...): ";
    for (int i = 0; i < n; i += 2) {
        const double* ptr = arr + i; 
        cout << *ptr << (i + 2 < n ? ", " : "");
        sum += *ptr;
    }
    cout << "\nSum = " << sum << '\n';
    return 0;
}

