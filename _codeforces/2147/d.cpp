/*
Problem link: https://codeforces.com/contest/2147/problem/D
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

/*
all even number stacks will be split evenly no matter what
greedily take the odd ones for each player, make stacks have even height
*/

void solve() {
    int n; cin >> n;
    map<ll, ll> a;
    set<ll> b;
    set<ll> odds;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[x]++;
        b.insert(x);
        if (x % 2 == 1) {
            odds.insert(x);
        }
    }
    vector<pair<ll, ll>> odds_freq;
    for(ll o : odds) {
        odds_freq.push_back({a[o], o});
    }
    sort(all(odds_freq));
    reverse(all(odds_freq));
    ll ansa = 0;
    ll ansb = 0;

    // take odd freqs greedily, update to number below
    for(int i = 0; i < sz(odds_freq); i++) {
        if (i % 2 == 0) {
            ansa += odds_freq[i].first;
            a[odds_freq[i].second - 1] += odds_freq[i].first;
        } else {
            ansb += odds_freq[i].first;
            a[odds_freq[i].second - 1] += odds_freq[i].first;
        }
    }
    // evens split equal
    for(auto& [k, v] : a) {
        if (k % 2 == 0) {
            ansa += v * k / 2;
            ansb += v * k / 2;
        }
    }
    cout << max(ansa, ansb) << " " << min(ansa, ansb) << endl;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
