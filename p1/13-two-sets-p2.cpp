#include <iostream>
#include <vector>

using namespace std;

int f(int i, int s, vector<vector<int>> &perms) {
    int max_s = (i+1)*i/2;
    if (s > max_s) {
        return 0;
    } else if (s == max_s) {
        return 1;
    } else {
        return perms[i][s];
    }
}

int main() {
    // Problem size
    int n;
    cin >> n;

    // Initialize array to which answer is calculated
    vector<vector<int>> perms(n, vector<int> (n*(n+1)/2, 0));
    perms[0][0] = 1;
    int divisor = 1000000007;

    // Calculate answer "bottom up"
    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= (i+1)*i/2; s++) {
            perms[i][s] = (f(i-1, abs(s+i), perms) + f(i-1, abs(s-i), perms)) % divisor;
        }
    }

    // Output
    cout << perms[n-1][n] << "\n";
}
