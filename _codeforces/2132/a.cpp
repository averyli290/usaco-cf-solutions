/*
Problem link: https://codeforces.com/contest/2132/problem/A
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
    int n; cin >> n;
    string s; cin >> s;
    int x; cin >> x;
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < x; i++) {
        if (s2[i] == 'V') s = s1[i] + s;
        else s = s + s1[i];
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}