// Source: Me

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
void update(vector<int>& st, int ind, int val, int at, int atl, int atr) {       // st[at] describes [atl, atr] inclusive
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(st, ind, val, 2 * at, atl, mid);
    else update(st, ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = st[2*at] + st[2*at+1];     // CHECK
}


// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
int query(vector<int>& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    int left = query(st, s, e, 2 * at, atl, mid);
    int right = query(st, s, e, 2 * at + 1, mid + 1, atr);
    return left + right;                // CHECK
}


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> st(n << 2, 0ll);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        update(st, i, a[i], 1, 0, n-1);
    }
    for(int i = 0; i < n; i++) {
        cout << query(st, 0, i, 1, 0, n-1) << endl;
    }
}

int main() {
    solve();
}