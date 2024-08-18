#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int previous = 1;
    long moves = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x < previous) {
            moves += previous - x;
        } else {
            previous = x;
        }
    }
    cout << moves;
}
