#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void get_permutations(string head, string tail, set<string> &s) {
    int n = tail.length();
    if (n == 0) {
        s.insert(head);
    } else {
        for (int i = 0; i < n; i++) {
            string new_head = head + tail[i];
            string new_tail = tail.substr(0, i) + tail.substr(i + 1, n);
            get_permutations(new_head, new_tail, s);
        }
    }
}

int main() {
    string word;
    cin >> word;
    set<string> s;
    get_permutations("", word, s);
    cout << s.size() << "\n";
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end());
    for (auto x : v) {
        cout << x << "\n";
    }
}
