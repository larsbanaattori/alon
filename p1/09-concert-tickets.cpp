#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // Read size of problem
    int n, m;
    cin >> n; // # of tickets
    cin >> m; // # of customers

    // Read ticket prices and insert to set
    multiset<int> prices;
    int price;
    for (int i = 1; i <= n; i++) {
        cin >> price;
        prices.insert(price);
    }

    // Read customer's asks and figure out which ticket they get
    int bid;
    for (int i = 1; i <= m; i++) {
        cin >> bid;
        if (prices.size() == 0) {
            cout << "-1" << "\n";
        } else {
            auto it = prices.lower_bound(bid);
            if (*it == bid) {
                cout << *it << "\n";
                prices.erase(it);
            } else if (it == prices.begin()) {
                cout << "-1" << "\n";
            } else {
                it--;
                cout << *it << "\n";
                prices.erase(it);
            }
        }
    }
}
