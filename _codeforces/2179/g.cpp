/*
Problem link: https://codeforces.com/contest/2179/problem/G
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

/*
pls work PLS i hate debugging interactives

hmm get two corners in n^2+O(1) queries
then query each against those two corners
each distance represents a diagonal line
take the intersection of those diagonal lines
2n^2 queries there


1.......
........
........
..y.....
........
2.......
d1 = w + h1;
d2 = w + h2;
n - 1 = h1 + h2;
w = ((d1 + d2) - (n - 1)) / 2;

*/

int q(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

/*
1 2
3 4

7 6 3 
4 2 9 
8 5 1 
*/

void solve() {
    int n; cin >> n;
    int n2 = n*n;

    // find corners
    int pengu1 = -1;
    int mval = -1;
    vi dists1(n2 + 1, 0), dists2(n2 + 1, 0);
    for(int i = 1; i <= n2; i++) {
        int res = q(1, i);
        dists1[i] = res;
        if (res > mval) {
            mval = res;
            pengu1 = i;
        }
    }

    // 2n^2
    // im a dumbass and didn't find pengu2 :(

    vi diag;
    for(int i = 1; i<=n2; i++) {
        int res = q(pengu1, i);
        dists2[i] = res;
        if (res == n - 1) diag.push_back(i);
    }

    // get second pengu now on adjacent corner
    mval = -1;
    int pengu2 = -1;
    for(int i = 0; i < n; i++) {
        int res = q(diag[0], diag[i]);
        if (res > mval) {
            mval = res;
            pengu2 = diag[i];
        }
    }

    // debug(pengu1);
    // debug(pengu2);

    vector<vi> ans(n, vi(n, -1));
    for(int i = 1; i<=n2; i++) {
        int res = q(pengu2, i);
        int w = ((dists2[i] + res) - (n - 1)) / 2;
        int h1 = res - w;
        // debug(w);
        // debug(h1);
        ans[h1][w] = i;
    }

    cout << "!" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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
