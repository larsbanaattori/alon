#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    long sum = 0;
    for (auto coin : coins) {
        if (coin <= sum + 1) {
            sum += coin;
        } else {
            break;
        }
    }
    cout << sum + 1 << "\n";
}
