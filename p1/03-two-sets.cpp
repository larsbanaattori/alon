#include <iostream>

using namespace std;

void print(int x, int stop, int jump) {
    if (x > stop) {
        cout << "\n";
    } else {
        cout << x << " ";
        print(x + jump, stop, jump == 1 ? 3 : 1);
    }
}

int main() {
    int n;
    cin >> n;
    if (((n + 1) * n / 2) % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        if (n % 2 == 0) {
            cout << n / 2 << "\n";
            print(1, n, 3);
            cout << n / 2 << "\n";
            print(2, n, 1);
        } else {
            cout << (n - 1) / 2 + 1 << "\n";
            cout << "1 2 ";
            print(4, n, 3);
            cout << (n - 1) / 2 << "\n";
            cout << "3 ";
            print(5, n, 1);
        }
    }
}
