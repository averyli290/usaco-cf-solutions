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
    int n; cin >> n;
    string x; cin >> x;
    map<int, vector<string>> mp;
    vector<string> s = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    for(int i = 0; i < sz(s); i++) {
        if (sz(s[i]) == n) {
            bool good = true;
            for(int j = 0; j < n; j++) {
                if (x[j] != '.' && x[j] != s[i][j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                cout << s[i] << endl;
                return;
            }
        }
    }
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
