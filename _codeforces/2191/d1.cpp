/*
Problem link: https://codeforces.com/contest/2191/problems/D1
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
#define debug(x) cout << #x << " is " << x << endl;
const long long INF = 1e18;

/*

(())((()))

can't remove last instance of ( and gain, still need one after in order to get from ()( => ((
*/

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int idx = n - 1;
    while (idx >= 0 && s[idx] == ')') idx--;
    int good = false;
    // debug(idx);
    for (int i = 0; i < idx - 1; i++) {
        if (s[i] == ')' && s[i + 1] == '(') {
            good = true;
            break;
        }
    } 
    if(good) {
        cout << n - 2 << endl;
    } else {
        cout << - 1<< endl;
    }
    // int n; cin >> n;
    // string s; cin >> s;
    // vi a(n);
    // vi b(n + 1, 0);
    // vi next(n + 1, n);
    // int curnext = n;
    // for (int i = n - 1; i >= 0; i--) {
    //     b[i] = b[i + 1];
    //     next[i] = curnext;
    //     if (s[i] == '(') {
    //         b[i]++;
    //         curnext = i;
    //     }
    // }
    // int ans = -1;
    // for (int i = 0; i < n; i++) {
    //     if (s[i] == ')' && next[i] < n) {
    //         int diff = next[i] - i;
    //         // debug(i);
    //         // debug(diff);
    //         // debug(next[i]);
    //         if(b[next[i] + 1] >= diff) ans = max(ans, n - 2 * (diff));
    //     }
    // }
    // cout << ans << endl;
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
