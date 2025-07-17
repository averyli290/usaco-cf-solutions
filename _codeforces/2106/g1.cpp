/*
Problem link: https://codeforces.com/contest/2106/problem/G1
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
    for (int i=1;i<n;i++) {
        int x, y;
        cin >> x >> y;
    }
    cout << "? 1 1 1" << endl; cout.flush();
    int x; cin >> x;
    vi ans(n+1);
    if (abs(x) == 1) {
        cout << "? 1 1 1" << endl; cout.flush();
        int v;
        cin >> v;
        ans[1] = v;
        for (int i=2;i<=n;i++) {
            cout << "? 1 1 " << i << endl; cout.flush();
            int x; cin >> x;
            ans[i] = x - v;
        }
        cout << "! ";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << endl;
        cout.flush();
    } else {
        cout << "? 1 1 1" << endl; cout.flush();
        int v; cin >> v;
        // make sum of 1 and root 0, then the result of
        // query for any value other than 1 will be its value, including root

        // figure out value of 1
        // if v = 0, 1,root = -1, 1 or swapped
        int oneval;
        if (v == 2) {
            cout << "? 2 1" << endl; cout.flush();
            oneval = -1;
        }
        else if (v == -2) {
            cout << "? 2 1" << endl; cout.flush();
            oneval = 1;
        }
        else {
            // figure out if oneval is -1 or 1
            cout << "? 2 1" << endl; cout.flush();
            cout << "? 1 1 1" << endl; cout.flush();
            cin >> v;
            if (v == 2) {
                cout << "? 2 1" << endl; cout.flush();
                oneval = -1;
            } else if (v == -2) {
                cout << "? 2 1" << endl; cout.flush();
                oneval = 1;
            }
        }
        for(int i=2;i<=n;i++) {
            cout << "? 1 1 " << i << endl; cout.flush();
            int x; cin >> x;
            ans[i] = x;
        }
        ans[1] = oneval;
        cout << "! ";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << endl;
        cout.flush();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
