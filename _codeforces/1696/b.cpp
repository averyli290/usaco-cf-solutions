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

// i should be sleeping before my flight huh

void solve() {
    int n; cin >> n;
    vi a(n);
    bool coolge = true;
    for(int i = 0; i< n; i++) {
        cin >> a[i];
        if (a[i] != 0) coolge =false;
    }
    if (coolge) {
        cout << 0 << endl;
        return;
    }
    int s = 0;
    coolge = true;
    while(s < n && a[s] == 0) s++;
    while(s < n) {
        if (a[s] == 0) {
            while (s < n) {
                if (a[s] != 0) coolge = false;
                s++;
            }
        }
        s++;
    }
    if (coolge) cout << 1 << endl;
    else cout << 2 << endl;
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
