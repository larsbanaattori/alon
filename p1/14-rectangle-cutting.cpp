#include <iostream>
#include <vector>

using namespace std;

int f(int a, int b, vector<vector<int>> &results) {
    if (results[a][b] < 0) {
        if (a == b) {
            results[a][b] = 0;
        } else if (min(a, b) == 1) {
            results[a][b] = max(a, b) - 1;
        } else {
            int best = max(a, b) * max(a, b);
            for (int a_cut = 1; a_cut < a; a_cut++) {
                best = min(best, f(a_cut, b, results) + f(a - a_cut, b, results));
            }
            for (int b_cut = 1; b_cut < b; b_cut++) {
                best = min(best, f(a, b_cut, results) + f(a, b - b_cut, results));
            }
            results[a][b] = best + 1;
        }
        results[b][a] = results[a][b]; // Symmetry
    }
    return results[a][b];
}

int main() {
    // Problem size
    int a, b;
    cin >> a >> b;
    int c = max(a, b) + 1;

    // Initialize table to which results are cached
    vector<vector<int>> results(c, vector<int> (c, -1));

    // Calculate
    cout << f(a, b, results) << "\n";
}
