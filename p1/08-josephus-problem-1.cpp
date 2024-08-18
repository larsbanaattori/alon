#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> kids;
    for (int i = 0; i < n; i++) {
        kids.push_back(i + 1);
    }
    vector<int> dropped;
    while (kids.size() > 0) {
        kids.push_back(kids.at(0));
        kids.pop_front();
        dropped.push_back(kids.at(0));
        kids.pop_front();
    }
    for (auto kid : dropped) {
        cout << kid << " ";
    }
    cout << "\n";
}
