#include <iostream>
#include <vector>

using namespace std;

long value_eval(int a, int b, long p, vector<long> &points, vector<vector<long>> &cache, vector<vector<bool>> &visited) {
    // If the node hasn't been visited
    if (!visited[a][b]) {
        if (a == b) {
            cache[a][b] = p; // Game ends -> the player gets remaining points
        } else { // Players maximize their own points = they minimize the max points the opponent can get
            cache[a][b] = (
                p -
                min(
                    value_eval(a + 1, b, p - points[a], points, cache, visited),
                    value_eval(a, b - 1, p - points[b], points, cache, visited)
                )
            );
        }
        visited[a][b] = true;
    }
    return cache[a][b];
}

int main() {
    // Get input
    int n;
    cin >> n;
    vector<long> points(n);
    long total_points = 0;
    for (int i = 0; i < n; i++) {
        cin >> points[i];
        total_points += points[i];
    }
    // Get output
    vector<vector<long>> cache(n, vector<long> (n, -1));
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    cout << value_eval(0, n - 1, total_points, points, cache, visited) << "\n";
}
