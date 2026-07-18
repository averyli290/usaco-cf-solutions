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


void solve() {
    int n; cin >> n;
    vi a(n);
    vi p1(n + 1, 0), p2(n + 1, 0), p3(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p1[i + 1] = p1[i];
        p2[i + 1] = p2[i];
        p3[i + 1] = p3[i];
        if (a[i] == 1) p1[i + 1]++;
        if (a[i] == 2) p2[i + 1]++;
        if (a[i] == 3) p3[i + 1]++;
    }

    // for(int i = 0; i<=n; i++) cout << p1[i] << " ";
    // cout << endl;
    // for(int i = 0; i<=n; i++) cout << p2[i] << " ";
    // cout << endl;
    // for(int i = 0; i<=n; i++) cout << p3[i] << " ";
    // cout << endl;

    int idx = -1;
    for(int i = 1; i <= n - 1; i++) {
        if (p1[i] >= p2[i] + p3[i]) {
            if (i == 1 && p3[i + 1] == 1) i++;
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "NO" << endl;
        return;
    }
    // debug(idx);

    int idx2 = -1;
    for(int i = idx + 1; i <= n - 1; i++) {
        // debug(i);
        // debug(p1[i] + p2[i] - p1[idx] - p2[idx]);
        // debug(p3[i] - p3[idx]);

        if (p1[i] + p2[i] - p1[idx] - p2[idx] >= p3[i] - p3[idx]) {
            idx2 = i;
            break;
        }
    }
    if (idx2 == -1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
