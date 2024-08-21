#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Get size of problem
    int n, k;
    cin >> n;
    cin >> k;

    // Get the input array
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    long j = -1, n_numbers = 0;
    long answer = 0;
    map<long,long> number_counts;

    for (long i = 0; i < n; i++) {
        // Move j until k is violated or we run out of array
        while (true) {
            if (j == n - 1) break;
            int next = numbers[j + 1];
            if (n_numbers == k and number_counts[next] == 0) break;
            if (number_counts[next] == 0) {
                n_numbers++;
                number_counts[next] = 1;
            } else {
                number_counts[next] += 1;
            }
            j++;
        }
        // Early exit in case j == n - 1
        if (j == n - 1) {
            answer += (j - i + 2) * (j - i + 1) / 2;
            break;
        }
        // In other cases, add subarrays starting from current i to result
        answer += j - i + 1;
        // Remove the number behind current number from n_numbers and number counts
        int current = numbers[i];
        if (number_counts[current] == 1) n_numbers -= 1;
        number_counts[current] -= 1;
    }
    cout << answer << "\n";
}
