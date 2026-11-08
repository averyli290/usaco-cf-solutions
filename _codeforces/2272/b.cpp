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
even runs okay
odd runs? need same amount on both sides
*/


void solve() {
    int n; cin >> n;
    vector<vi> a(2, vi(n));
    string s; cin >> s;
    int s1 = 0;
    int s2 = 0;
    int o1 = 0;
    int o2 = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'f') {
            cur++;
            a[0][i] = 1;
            s1++;
        } else {
            if (cur % 2 == 1) o1++;
            a[0][i] = 0;
            cur = 0;
        }
    }
    if (cur % 2 == 1) o1++;
    cin >> s;
    cur = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == 'f') {
            cur++;
            a[1][i] = 1;
            s2++;
        } else {
            if (cur % 2 == 1) o2++;
            a[1][i] = 0;
            cur = 0;
        }
    }
    if (cur % 2 == 1) o2++;

    if ((s1+s2)%2 == 0) cout << 0 << endl;
    else cout << 1 << endl;

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
