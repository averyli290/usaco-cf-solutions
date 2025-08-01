/*
Problem link: https://codeforces.com/contest/2125/problem/A
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
const long long INF = 1e18;


void solve() {
    string s; cin >> s;
    vi arr(26, 0);
    for(char c : s) {
        arr[c - 'A'] += 1;
    }
    string ans;
    ans += string(arr['T' - 'A'], 'T');
    ans += string(arr['F' - 'A'], 'F');
    ans += string(arr['N' - 'A'], 'N');
    for(int i = 0; i < 26; i++) {
        if (i != 'T' - 'A' && i != 'F' - 'A' && i != 'N' - 'A') {
            ans += string(arr[i], i + 'A');
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}