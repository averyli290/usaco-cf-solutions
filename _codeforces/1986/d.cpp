/*
Problem link: https://codeforces.com/contest/1986/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi a(n);
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    int totans = INT_MAX;
    for(int i = 0; i < n - 1; i++) {
        vi b;
        for(int j = 0; j < n; j++) {
            if (j == i) {
                b.push_back(10*a[j] + a[j + 1]);
                j++;
            } else {
                b.push_back(a[j]);
            }
        }

        int ans = 0;
        for(int v : b) {
            if (v == 0) {
                cout << 0 << endl;
                return;
            }
            if (v == 1) {
                if (ans == 0) {
                    ans = 1;
                }
            } else {
                if (ans == 1) ans *= v;
                else ans += v;
            }
        }
        totans = min(ans, totans);
    }
    cout << totans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
