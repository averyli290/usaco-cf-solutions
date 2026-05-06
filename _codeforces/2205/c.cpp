/*
Problem link: https://codeforces.com/contest/2205/problem/C
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


void solve() {
    int n; cin >> n;
    vi l(n);
    vector<vi> a(n);
    int mval = 0;
    for(int i= 0; i < n; i++) {
        cin >> l[i];
        a[i].resize(l[i], 0);
        for(int j = 0; j < l[i]; j++) {
            cin >> a[i][j];
        }
        mval = max(mval, l[i]);
    }
    for(vi b : a) {
        for (int v : b) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        reverse(all(a[i]));
        a[i].resize(mval, -1);
    }

    sort(all(a));
    reverse(all(a));
    for(int i = 0; i < n; i++) {
        reverse(all(a[i]));
    }

    for(vi b : a) {
        for (int v : b) {
            cout << v << " ";
        }
        cout << endl;
    }

    vi ans;

    for(int i = 0; i < n; i++) {
        for(int u : a[i]) {
            int prev = u;
            if (prev > -1) {
                if (sz(ans) == 0) {
                    ans.push_back(prev);
                } else {
                    bool swapped = false;
                    int temp;
                    for(int j = 0; j < sz(ans); j++) {
                        if (ans[j] == u) {
                            ans[j] = prev;
                            swapped = true;
                            break;
                        }
                        temp = ans[j];
                        ans[j] = prev;
                        prev = temp;
                    }
                    if (!swapped) ans.push_back(prev);

                }
            }
        }
    }

    for(int v : ans) {
        cout << v << " ";
    }
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
