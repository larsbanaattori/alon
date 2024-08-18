#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector< pair<int,int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second; // when does it start?
        cin >> v[i].first; // when does it end?
    }
    sort(v.begin(), v.end()); // sort by end time
    int movies = 0, last_end = 0;
    for (auto p : v) {
        int end = p.first, start = p.second;
        if (start >= last_end) {
            movies++;
            last_end = end;
        }
    }
    cout << movies << "\n";
}
