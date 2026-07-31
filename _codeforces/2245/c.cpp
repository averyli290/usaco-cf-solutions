/*
Problem link: https://codeforces.com/contest/2245/problem/C
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

/*
exclude powers of 2 minus 1

0,1,3

*/

void solve() {
    int n, k; cin >> n >> k;
    if (k == 0 && n <= 2) {
        cout << "NO" << endl;
        return;
    }
    k ^= n;
    if (k >= n * 2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<int> a;
    a.push_back(-1);
    for(int i = 0; i < 32; i++) {
        if ((k >> i) & 1) a.push_back((1 << i) - 1);
    }
    a.push_back(n - 1);
    vi ans;
    for(int i = 1; i < sz(a); i++) {
        int cur = a[i];
        int prev = a[i - 1];
        for(int j = cur; j > prev; j--) {
            ans.push_back(j);
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
