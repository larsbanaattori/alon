#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Get # of customers
    int n;
    cin >> n;

    /*
    Read in customers, their arrival & departure times, 
    and numbers.
    */
    vector< tuple<int, int, int> > customers;
    for (int i = 0; i < n; i++) {
        int arrival, departure;
        cin >> arrival;
        cin >> departure;
        customers.push_back(make_tuple(arrival, departure, i));
    }

    // Sort customers from earliest to latest arrival
    sort(customers.begin(), customers.end());

    // Figure out who gets what room
    int r = 1; // # of rooms
    priority_queue< pair<int,int> > rooms; // (-departure time, room number)
    vector<int> allocation(n); // allocation[i] = room number of customer i
    rooms.push(make_pair(0, 1));
    for (auto c : customers) {
        int arrival = get<0>(c);
        int departure = get<1>(c);
        int c_number = get<2>(c);
        auto top_room = rooms.top();
        int top_room_departure = -top_room.first;
        int top_room_number = top_room.second;
        if (top_room_departure < arrival) {
            rooms.pop();
            rooms.push(make_pair(-departure, top_room_number));
            allocation[c_number] = top_room_number;
        } else {
            r++;
            rooms.push(make_pair(-departure, r));
            allocation[c_number] = r;
        }
    }

    // Print result
    cout << r << "\n";
    for (auto number : allocation) {
        cout << number << " ";
    }
    cout << "\n";
}
