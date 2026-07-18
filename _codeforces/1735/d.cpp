/*
Problem link: https://codeforces.com/contest/1735/problem/D
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

typedef array<int, 20> card;


/*

A,B,C
A,D,E


B,C,A

center A and iter over others

*/

void solve() {
    int n, k; cin >> n >> k;

    vector<card> a(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) cin >> a[i][j];
        for(int j = k; j < 20; j++) a[i][j] = 0;
        // for(int x : a[i]) {
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    set<card> c(all(a));

    // ew helpers

    function<card(card, card)> sum = [&] (card a, card b) {
        card temp;
        for(int i = 0; i < 20; i++) temp[i] = (a[i] + b[i]) % 3;
        return temp;
    };

    function<card(card)> inv = [&] (card a) {
        card temp;
        for(int i = 0; i < 20; i++) temp[i] = (3-a[i]) % 3;
        return temp;
    };

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int curans = 0;
        for(int j = 0; j < n; j++) {
            if (i == j) continue;
            card other = inv(sum(a[i], a[j]));
            if (c.find(other) != c.end()) {
                curans++;
            }
        }
        // some coool combo stuff ig
        curans /= 2;
        // debug(curans);
        if (curans >= 2) ans += curans * (curans - 1) / 2;
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
