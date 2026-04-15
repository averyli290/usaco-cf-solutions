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

/*
n(n-1) / 2 -> (n)(n+1)/2
/(n - 1) * (n + 1)

*/

int dsusize[25001];
int parent[25001];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    dsusize[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (dsusize[a] < dsusize[b])
            swap(a, b);
        parent[b] = a;
        dsusize[a] += dsusize[b];
    }
}

void solve() {
    int n; cin >> n;
    vi p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<pii> a(n - 1);
    for(int i = 0; i < n-1; i++) {
        a[i] = {abs(p[i] - p[i + 1]), i}
    }
    sort(all(a));
    reverse(all(a));

    int k = n - 1;
    for(int i = 0; i < n - 1; i++) {
        auto [diff, rep] = a[i];

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
