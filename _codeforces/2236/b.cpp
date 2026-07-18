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


void solve() {
    int n ,k; cin >> n >> k;
    string s; cin >> s;

    int i = 0;
    while(i + k < n) {
        if (s[i] == '1') {
            s[i] = '0';

            if (s[i + k] == '0') s[i + k] = '1';
            else s[i + k] = '0';
        }
        i++;
    }
    for(char c : s) {
        if (c == '1') {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
