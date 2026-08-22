/*
Problem link: https://codeforces.com/contest/1326/problem/E
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

until max query includes prev answer, it doesn't change the answer

update to remove max as you go (set to 0 when remove)
offset by amount removed in front already

2 3 6 1 5 4
5 2 1 4 6 3

6 5 5 5 4 1

5:
5

5 2:


2 3 6 1 5 4
2 3 1 5 4
1 5 4

1 2 4 5

at least k bombs 

*/

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
    st[at] = max(st[2*at], st[2*at+1]);
}


// at is 1-indexed (use at=1)
// [atl, atr] is inclusive and 0 indexed (max range is [atl, atr]=[0, sz(st)-1])
int query(vector<int>& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    int left = query(st, s, e, 2 * at, atl, mid);
    int right = query(st, s, e, 2 * at + 1, mid + 1, atr);
    return max(left, right);
}


void solve() {
    int n; cin >> n;
    vi p(n), q(n);
    vi mp(n + 1, -1);   // val to idx map
    vector<int> st(n << 2, 0);
    vector<int> st2(n << 2, 0);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        mp[p[i]] = i;
        update(st, i, p[i], 1, 0, n-1);
    }

    for(int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }

    vi ans(n);
    ans[0] = query(st, 0, n-1, 1, 0, n-1);
    priority_queue<int> pq;
    for(int i = 0; i < n-1; i++) {
        pq.push(-q[i]);
        debug(q[i]);
        int val = query(st, 0, q[i] + offset, 1, 0 , n - 1);
        if (val == ans[i]) {
            while(!pq.empty()) {
                int idx = -pq.top();
                debug(idx);
                pq.pop();
                int remove = query(st, 0, idx, 1, 0, n - 1);
                debug(remove);
                update(st, mp[remove], 0, 1, 0, n-1);
            }
        }
        for(int j = 0; j < n; j++) cout << query(st, j, j, 1, 0, n-1) << " ";
        cout << endl;
        ans[i + 1] = query(st, 0, n-1, 1, 0, n-1);
    }
    for(int v : ans) cout << v << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
}
