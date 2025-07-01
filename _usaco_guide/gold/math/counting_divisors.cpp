#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int MAX_N = 1e6;
int max_div[MAX_N + 1]; // max_div[i] contains the largest prime divisor of i

void solve() {
    int n; cin >> n;

    vector<int> powers;
    while (n > 1) {
        int div = max_div[n];
        int c = 0;
        while (n % div == 0) {
            n /= div;
            c++;
        }
        powers.push_back(c);
    }
    
    int ans = 1;

    for(auto i : powers) {
        ans *= i + 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // compute max divisors once
    max_div[1] = 1;
    for(int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) {
                max_div[j] = i;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
