/*
Problem link:
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
    int n, k; cin >> n >> k;
    vi a(n);
    map<int, int> m;
    set<int> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
        b.insert(a[i]);
    };
    int ans1 = 0;
    for(int i = 0; i < k; i++) {
        if(i < k) {
            if (m[i] == 0) ans1++;
        }
    }
    int ans2 = m[k];
    //cout << ans1 << " " << ans2 << endl;
    int temp = min(ans1, ans2);
    ans1 -= temp;
    //ans2 -= temp;
    cout << ans1 + ans2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}