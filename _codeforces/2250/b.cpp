/*
Problem link: https://codeforces.com/contest/2250/problem/B
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

/*

min val = 0
max val = n - 1 - 1 = n - 2



asdflkajdslkfdasf

*/


void solve() {
    int n, k; cin >> n >> k;
    if (k > n - 2) cout << -1 << endl;
    else {
        int ct0 = 0;
        int ct1 = 0;
        for(int i = 0; i < k / 2 + 1; i++) {
            cout << '0';
            ct0++;
        }
        for(int i = 0; i < k - (k / 2) + 1; i++) {
            cout << '1';
            ct1++;
        }
        int ctr = 0;
        for(int i = 0; i < n - (k + 2); i++) {
            if (i % 2 == 0) cout << '0';
            else cout << '1';
        }
        cout << endl;
    }
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
