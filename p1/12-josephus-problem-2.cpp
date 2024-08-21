#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
    int n, k;
    cin >> n >> k;

    // Put kids in indexed set
    indexed_set kids;
    for (int i = 1; i <= n; i++) {
        kids.insert(i);
    }

    // Do the thing
    int i = 0;
    while (kids.size() > 0) {
        int n_left = kids.size();
        i = (i + k) % n_left;
        auto p = kids.find_by_order(i);
        cout << *p << " ";
        kids.erase(p);
    }
    cout << "\n";
}
