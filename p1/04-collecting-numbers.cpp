#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, rounds = 1;
    cin >> n;
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> x;
        pos[x] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i-1]) rounds++;
    }
    cout << rounds << "\n";
}
