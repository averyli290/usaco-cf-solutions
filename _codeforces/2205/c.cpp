
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


void solve() {
    int n; cin >> n;
    vi l(n);
    vector<vi> a(n);
    int mval = 0;
    for(int i= 0; i < n; i++) {
        cin >> l[i];
        vi temp(l[i]);
        set<int> inserted;
        for(int j = 0; j < l[i]; j++) {
            cin >> temp[j];
        }
        for(int j = l[i] - 1; j >= 0; j--) {
            if (inserted.find(temp[j]) == inserted.end()) {
                a[i].push_back(temp[j]);
                inserted.insert(temp[j]);
            }
        }
        // reverse(all(a[i]));
        mval = max(mval, sz(a[i]));
    }
    // for(vi b : a) {
    //     for (int v : b) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for(int i = 0; i < n; i++) {
        // reverse(all(a[i]));
        a[i].resize(mval, -1);
    }

    sort(all(a));

    // for(vi b : a) {
    //     for (int v : b) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    vi ans;

    vi ansidx(1e6 + 1, -1);

    int ctr = 0;
    while (sz(a) > 0) {
        int idx = 0;
        while (idx < sz(a[0])) {
            if (a[0][idx] == -1) break;
            if (ansidx[a[0][idx]] == -1) {
                ansidx[a[0][idx]] = ctr;
                ctr++;
            }
            idx++;
        }
        vector<vi> b;
        for(int i = 1; i < sz(a); i++) {
            vi temp;
            for(int j = 0; j < sz(a[i]); j++) {
                if (a[i][j] == -1) break;
                if (ansidx[a[i][j]] == -1) temp.push_back(a[i][j]);
            }
            mval = max(mval, sz(temp));
            b.push_back(temp);
        }
        for(int i = 0; i < sz(b); i++) {
            b[i].resize(mval, -1);
        }
        sort(all(b));
        a = b;
    }
    vector<pii> temp;
    for(int i = 0;i < sz(ansidx); i++) {
        if (ansidx[i] > -1) temp.push_back({ansidx[i], i});
    }
    sort(all(temp));
    for(auto [idx, val] : temp) cout << val << " ";
    cout << endl;

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