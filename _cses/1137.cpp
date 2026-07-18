/*
Problem link:
*/

/*
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

int L;           // set in solve if using
vector<ll> st;  // assign in solve if using
vector<int> tin, tout;
int timer;
vector<vi> adj;
vll val;

void update(int ind, int val, int at=1, int atl=0, int atr=L-1) {
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(ind, val, 2 * at, atl, mid);
    else update(ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = st[2*at] + st[2*at+1];
}

ll query(int s, int e, int at=1, int atl=0, int atr=L-1) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    ll left = query(s, e, 2 * at, atl, mid);
    ll right = query(s, e, 2 * at + 1, mid + 1, atr);
    return left + right;
}

void dfs(int cur, int par) {
    tin[cur] = timer;
    timer++;
    update(tin[cur], val[cur]);
    for(int neig : adj[cur]) {
        if (neig != par) {
            dfs(neig, cur);
        }
    }
    tout[cur] = timer;
    timer++;
}

void solve() {
    int n, q; cin >> n >> q;
    L = 2*n;        // DFS traversal takes 2n time
    st.assign(4*L, 0ll);
    adj.assign(n, vi{});
    val.assign(n, 0ll);
    tin.assign(n, 0);
    tout.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    timer = 0;
    dfs(0, -1);

    while (q--) {
        continue;
        int type; cin >> type;
        if (type == 1) {
            int s; cin >> s;
            s--;
            ll x; cin >> x;
            update(tin[s], x);
        } else {
            int s; cin >> s;
            s--;
            cout << query(tin[s], tout[s]) << endl;
        }
    }
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

vector<int> tin, tout;
int timer;
vector<vi> adj;
vll val;

void update(vll& st, int ind, int val, int at, int atl, int atr) {       // st[at] describes [atl, atr] inclusive
    if (atl == atr) {
        st[at] = val;
        return;
    }
    int mid = (atl + atr) / 2;
    if (ind <= mid) update(st, ind, val, 2 * at, atl, mid);
    else update(st, ind, val, 2 * at + 1, mid + 1, atr);
    st[at] = st[2*at] + st[2*at+1];
}

ll query(vll& st, int s, int e, int at, int atl, int atr) {         // query [s, e] (0-indexed)
    if (atr < s || e < atl) return 0;
    if (s <= atl && atr <= e) return st[at];
    int mid = (atl + atr) / 2;
    ll left = query(st, s, e, 2 * at, atl, mid);
    ll right = query(st, s, e, 2 * at + 1, mid + 1, atr);
    return left + right;
}


void solve() {
    int n, q; cin >> n >> q;
    vll st((2 * n) << 2, 0ll);  // dfs traversal takes 2n time
    adj.assign(n, vi{});
    val.assign(n, 0ll);
    tin.assign(n, 0);
    tout.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    timer = 0;
    function<void(int,int)> dfs = [&] (int cur, int par) {
        tin[cur] = timer;
        timer++;
        update(st, tin[cur], val[cur], 1, 0, 2*n-1);
        for(int neig : adj[cur]) {
            if (neig != par) {
                dfs(neig, cur);
            }
        }
        tout[cur] = timer;
        timer++;
    };

    dfs(0, -1);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s; cin >> s;
            s--;
            ll x; cin >> x;
            update(st, tin[s], x, 1, 0, 2*n-1);
        } else {
            int s; cin >> s;
            s--;
            cout << query(st, tin[s], tout[s], 1, 0, 2*n-1) << endl;
        }
    }
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
