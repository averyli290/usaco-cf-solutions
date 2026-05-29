/*
Problem link:
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

can always make a prefix negative

1 -3 2 -1 10

-1 3 -2 1 -10
1 -3 -2 1 -10


2 -10 -11 3 -10 15 7 18 16 17 -9
6 3 1 5 4 7

-2 10 11 -3 10 -15 7 18 16 17 -9
2 -10 -11 -3 10 -15 7 18 16 17 -9
-2 -10 -11 -3 10 -15 7 18 16 17 -9
2 10 11 3 -10 -15 7 18 16 17 -9
-2 -10 -11 -3 -10 -15 7 18 16 17 -9
2 10 11 3 10 15 -7 18 16 17 -9

2 -10 -11 3 -10 15 7 18 16 17 -9
9 5 4 3 1 10 

2 10 11 3 10 15 7 18 16 -17 -9
*/

vi solve2(int n, vll a) {
    vi ans;
    int ct = 0;
    for(int i = n - 1; i >= 0; i--) {
        if (ct % 2 == 1) a[i] = -a[i];
        if (a[i] > 0) {
            ans.push_back(i + 1);
            ct++;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vll a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll pref = 0LL;
    int maxidx = -1;
    ll maxval = 0;
    for(int i = 0; i < n; i++) {
        if (i == 0) maxval = a[i];
        else maxval = maxval + a[i];
        // debug(maxval);
        if (a[i] > 0) {
            if (pref - a[i] > maxval) {
                maxval = pref - a[i];
                maxidx = i;
            }
        }
        pref += abs(a[i]);
    }

    vi ans;
    if (maxidx > -1 && maxidx < n) {
        ans = solve2(maxidx, a);
        ans.push_back(maxidx + 1);
    }

    cout << sz(ans) << endl;
    for(int i : ans) {
        cout << i << " ";
    }
    cout << endl;
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
