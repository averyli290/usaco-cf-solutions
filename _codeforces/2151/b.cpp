/*
Problem link: https://codeforces.com/contest/2151/problem/B
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<int> a;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    int cur = 1;// keeps track of where ended (not necessarily black or white)
    for(char& c : s) {
        if (c == 'A') {
            cur++;
            a.insert(cur);
        } else {
            cur++; // need to find NEXT white (have to skip current)
            while(a.count(cur) > 0) cur++;
            a.insert(cur);  // color black
            while(a.count(cur) > 0) cur++;      // if run prefix again, it extends to here
        }
    }
    cout << sz(a) << endl;
    for(int v : a) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}