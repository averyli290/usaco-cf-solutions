/*
Problem link: https://codeforces.com/contest/2032/problem/D
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

    function<int(int, int)> q = [](int a, int b) {
        cout << "? " << a << " " << b << endl; cout.flush();
        int res; cin >> res; return res;
    };

    vi ans(n);

    vi one;
    vi other;
    for(int i = 2; i < n; i++) {
        if (q(1, i) == 0) one.push_back(i);
        else other.push_back(i);
    }

    one.push_back(1);
    sort(all(one));
    ans[1] = 0;
    for(int i = 1; i < sz(one); i++) {
        ans[one[i]] = one[i - 1];
    }

    sort(all(other));
    reverse(all(other));
    /*
    take cur to be largest, query with next largest
    res == 0 => right above
    res = 1 => new branch, terminate current one
    */
    if (sz(other) > 0) {
        int cur = other[0];

        for(int i = 1; i < sz(other); i++) {
            int res = q(cur, other[i]);
            if (res == 0) {
                ans[cur] = other[i];
            } else {
                ans[cur] = 0;
            }
            cur = other[i];
        }
        ans[cur] = 0;
    }
    cout << "! ";
    for(int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
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
