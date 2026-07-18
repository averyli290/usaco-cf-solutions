
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
    int n, k;cin>>n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(all(a));
    // int cur = k;
    int last = k + 1;
    vi idx(k + 1, -1);
    for(int i = 0; i < n; i++) {
        if (idx[a[i]] == -1 || a[i] < last) {
            last = a[i];
            idx[a[i]] = i;
        }
    }
    vector<pii> ans;
    for(int i = 1; i <= k; i++) {
        ans.push_back({-idx[i], i});
    }
    sort(all(ans));
    for(auto[x, y]: ans) {
        cout << y << " ";
    }
    cout << endl;
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
