/*
Problem link: https://codeforces.com/contest/2247/problem/D1
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
https://www.youtube.com/watch?v=9qN9EF-6IcI

push elements to left and then back right, only need power of 2 for k

check no crossing of max of prev blocks over min of next block
*/

struct aaa
{
    int x;
    int y;
    int z;
};


// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
void update(vector<aaa>& st, int ind, aaa val, int at, int atl, int atr) {       // st[at] describes [atl, atr] inclusive
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(st, ind, val, 2 * at, atl, mid);
    else update(st, ind, val, 2 * at + 1, mid + 1, atr);
    aaa left = st[2*at];
    aaa right = st[2*at+1];
    aaa temp = {min(left.x, right.x), max(left.y, right.y), max(left.z, right.z)};
    if (left.y > right.x) temp.z = (atr + 1 - atl) / 2; // power of 2 needed is half of size of total cur range
    st[at] = temp;
}


// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
aaa query(vector<aaa>& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return aaa{INT_MAX, 0, 0};
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    aaa left = query(st, s, e, 2 * at, atl, mid);
    aaa right = query(st, s, e, 2 * at + 1, mid + 1, atr);
    return {min(left.x, right.x), max(left.y, right.y), max(left.z, right.z)};
}

void solve() {
    int n, q; cin >> n >> q;
    int newn = 1;
    while(newn < n) newn <<= 1;
    vi a(newn, INT_MAX);
    for(int i = 0 ;i < n; i++) {
        cin >> a[i];
    }

    vector<aaa> st(newn << 2);

    for(int i = 0; i < newn; i++) {
        update(st, i, aaa{a[i], a[i], 0}, 1, 0, newn - 1);
    }

    cout << query(st, 0, newn - 1, 1, 0, newn - 1).z << endl;

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
