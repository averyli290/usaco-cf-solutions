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
001011010

2: 000011010 -> 01010
3: 001111010 -> 01010
6: 001011110
7: 001011000

1010101010101
*/

void solve() {
    string s; cin >> s;
    char l = s[0];
    int ans = 1;
    for(int i = 1 ;i <sz(s) - 1;i++) {
        if (s[i - 1] == s[i + 1]) {
            if (s[i] != s[i - 1]) {
                debug(i);
                ans++;
            }
            else if (!run){
                debug(i);
                ans++;
            }
        }
        if (s[i] == s[i - 1]) run = true;
        else run = false;
    }
    cout << ans << endl;
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
