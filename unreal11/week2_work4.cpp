#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2 || n > 9) {
        cout << "Wrong Number" << endl;
        return 0;
    }

    for (int i = 1; i <= 9; i++) {
        cout << n << " * " << i << " = " << n * i << endl;
    }

    return 0;
}