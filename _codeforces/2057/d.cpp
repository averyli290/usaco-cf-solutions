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

/*
https://www.youtube.com/watch?v=9qN9EF-6IcI

for some segment, the min and the max will be the endpoints

a[r] - a[l] - (r - l)
=(a[r] - r) - (a[l] - l)
max the first, min the second


when updating, split into two cases (store in two trees)
where max is in the left segment and min in the right segment and
where max is in the right segment and min in the left segment

*/

struct aaa {
    ll x; // a[i] - i minval
    ll y; // a[i] - i maxval
    ll z;
};

// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
void update1(vector<aaa>& st, int ind, aaa val, int at, int atl, int atr) {       // st[at] describes [atl, atr] inclusive
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update1(st, ind, val, 2 * at, atl, mid);
    else update1(st, ind, val, 2 * at + 1, mid + 1, atr);
    aaa left = st[at * 2];
    aaa right = st[at * 2 + 1];
    st[at] = {min(left.x, right.x), max(left.y, right.y), max(right.y - left.x, max(left.z, right.z))};     // if max assumed to be in right seg
}

// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
ll query1(vector<aaa>& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0ll;
    if (s <= atl && atr <= e) return st[at].z;
    int mid = (atl + atr) / 2;
    ll left = query1(st, s, e, 2 * at, atl, mid);
    ll right = query1(st, s, e, 2 * at + 1, mid + 1, atr);
    return max(left, right);
}

// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
void update2(vector<aaa>& st, int ind, aaa val, int at, int atl, int atr) {       // st[at] describes [atl, atr] inclusive
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update2(st, ind, val, 2 * at, atl, mid);
    else update2(st, ind, val, 2 * at + 1, mid + 1, atr);
    aaa left = st[at * 2];
    aaa right = st[at * 2 + 1];
    st[at] = {min(left.x, right.x), max(left.y, right.y), max(left.y - right.x, max(left.z, right.z))};     // if max assumed to be in left seg
}

// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
ll query2(vector<aaa>& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0ll;
    if (s <= atl && atr <= e) return st[at].z;
    int mid = (atl + atr) / 2;
    ll left = query2(st, s, e, 2 * at, atl, mid);
    ll right = query2(st, s, e, 2 * at + 1, mid + 1, atr);
    return max(left, right);
}



void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    vector<aaa> st1(n << 2, {LLONG_MAX,LLONG_MIN,LLONG_MIN});
    vector<aaa> st2(n << 2, {LLONG_MAX,LLONG_MIN,LLONG_MIN});
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        update1(st1, i, {a[i] - i, a[i] - i, 0ll}, 1, 0, n-1);
        update2(st2, i, {a[i] + i, a[i] + i, 0ll}, 1, 0, n-1);      // a[i] + i to reverse because max is assumed to be in left seg (r-l) becomes (l-r)
    }
    ll ans = 0ll;
    cout << max(query1(st1, 0,n-1,1,0,n-1), query2(st2, 0,n-1,1,0,n-1)) << endl;
    while(q--) {
        ll p, x; cin >> p >> x;
        p--;
        update1(st1, p, {x - p,x-p,0ll}, 1, 0, n - 1);
        update2(st2, p, {x+p,x+p,0ll}, 1, 0, n - 1);
        cout << max(query1(st1, 0, n - 1, 1, 0, n - 1), query2(st2, 0, n - 1, 1, 0, n - 1)) << endl;
    }
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
