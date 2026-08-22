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
*/

void solve() {
    string s; cin >> s;
    int n = sz(s);
    bool b = false;
    string s1 = "";
    for(int i = 0; i < n; i++) {
        if (b) {
            s1 += s[i];
        } else if (s[i] == '0') {
            b = true;
        } else {
            s1 += s[i];
        }
    }
    b = false;
    string s2 = "";
    for(int i = 0; i < sz(s1); i++) {
        if (b) s2 += s1[i];
        else if (s1[i] == '1') {
            b = true;
        } else {
            s2 += s1[i];
        }
    }
    cout << s2 << endl;
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
