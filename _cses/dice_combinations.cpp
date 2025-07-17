/*
Problem link: https://cses.fi/problemset/task/1633
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
const long long MOD = 1E9+7;


void solve() {
    int n; cin >> n;

    vector<ll> a(n + 1);
    for(int i = 1; i<= 6; i++) {
        a[i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 6;j++) {
            if (i - j >= 1) {
                a[i] = (a[i] + a[i - j]) % MOD;
            }
        }
    }
    cout << a[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
}
