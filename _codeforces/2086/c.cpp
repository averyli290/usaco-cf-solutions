/*
Problem link:
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
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;


vector<int> parent;
vector<int> setsize;

void make_set(int v) {
    parent[v] = v;
    setsize[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (setsize[a] < setsize[b])
            swap(a, b);
        parent[b] = a;
        setsize[a] += setsize[b];
    }
}

void solve() {
    int n; cin >> n;
    parent.assign(n + 1, 0);
    setsize.assign(n + 1, 0);
    vi depth(n + 1, 0);
    vi next(n + 1, 0);
    vi d(n, 0);

    vi src;
    for(int i = 1; i <= n; i++) make_set(i);
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        //cin >> next[i + 1];
        if (temp == i + 1) src.push_back(i + 1);
        else {
            next[temp] = i + 1; // add edge backwards
            union_sets(i + 1, next[i + 1]);
        }
    }
    for(int i = 0; i < n; i++) cin >> d[i];

    // calc depths backwards, starting with when permutation maps to itself
    // any unvisited has depth equal to the size of its dsu

    vector<bool> vis(n + 1, false);
    for(int s : src) {
        int cur = s;
        int curdepth = 1;
        while (cur != 0) {
            depth[cur] = curdepth;
            curdepth++;
            cur = next[cur];
            vis[cur] = true;
        }
    }
    vi sizes(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        sizes[find_set(i)]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) depth[i] = sizes[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << depth[i] << " ";
    }
    cout << endl;
    map<int, int> m; // set representative -> max depth mapping
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cur = d[i];
        debug(cur);
        int curset = find_set(cur);
        debug(curset);
        int curval = m[curset];
        debug(depth[cur]);
        ans += depth[cur] - curval;
        m[curset] = max(m[curset], depth[cur]);
        cout << ans << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++) cout << sizes[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
