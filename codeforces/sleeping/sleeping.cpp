#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> log(n, 0);
        int s = 0;
        for(int j = 0; j < n; j++) {
            cin >> log[j];
            s += log[j];
        }

        vector<int> divisors{0};
        for(int d = 1; d <= (int)ceil(sqrt(s)); d++) {
            if (s % d == 0) {
                divisors.push_back(d);
                divisors.push_back(s / d);
            }
        }

        int min_modifications = INT32_MAX;
        for (int divisor : divisors) {
            // Smush from left to right, if there is a solution, then this obtains it
            // no matter what
            vector<int> log_copy = log;

            int cur = 0;
            int mods = 0;
            int j = 0;
            while (j < n) {
                cur += log_copy[j];
                if (cur > divisor) {
                    break;
                } else if (cur < divisor) {
                    mods++;
                } else {
                    cur = 0;
                }
                j++;
            }
            if (j == n) min_modifications = min(min_modifications, mods);
        }

        cout << min_modifications << '\n';
    }
}
