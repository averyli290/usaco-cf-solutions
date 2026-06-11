/*
Problem link: https://codeforces.com/contest/2132/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;

    int t = n;
    int ct = 0;
    vi v;
    while(t > 0) {
        ct++;
        v.push_back(t % 10);
        t /= 10;
    }

    vi ans;
    for(int i = 1; i <= ct; i++) {
        if ((ct / i) % 2== 0) {
            int v = 1;
            int value = 0;
            int j = 0;
            bool good = true;
            while(j < ct / i) {
                for(int k = 0; k < i; k++) {
                    if(v[j + k] != v[j + k + i]) {
                        good = false;
                        break;
                    }
                }
                if (!good) break;
                j += 2 * i;
                for(int k = 0; k < i; k++) value *= 10;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}