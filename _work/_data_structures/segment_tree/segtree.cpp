// Source: Me

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// int L;
// vector<int> st;
const int L=1E5;
int st[4 * L];

void build(vector<int>& arr, int at=1, int atl=0, int atr=L-1) {
    if (atl == atr) {
        st[at] = arr[atl];
        return;
    }
    int mid = (atl + atr) / 2;
    build(arr, 2 * at, atl, mid);
    build(arr, 2 * at + 1, mid + 1, atr);
    st[at] = st[2*at] + st[2*at+1];
}

void update(int ind, int val, int at=1, int atl=0, int atr=L-1) {
    if (atl == atr) {
        st[at] = arr[atl];
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(ind, val, 2 * at, atl, mid);
    else update(ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = st[2*at] + st[2*at+1];
}

int query(int s, int e, int at=1, int atl=0, int atr=L-1) {
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return segtree[at];     // at range contained in [s, e] range
    int mid = (atl + atr) / 2;
    int left = query(s, e, 2 * at, atl, mid);
    int right = query(s, e, 2 * at + 1, mid + 1, atr);
    return left + right;
}

void solve() {
    int n; cin >> n;
    // L = n;
    // st.assign(4*L, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    build(a);
}