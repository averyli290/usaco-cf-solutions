/*
a+b=x
b+c=y
a+c=z
b-c=x-z
b+c=y
2a+2b=2x

if any are not integers, return false
2b=x-z+y
2a=x+z-y
2c=y-x+z

2a+2b+2c=x+y+z

anything connected to set values have a set lo and hi, can propogate those

for all other connected components (constraints) set one of them to be activated/not activated.
then propogate lo/hi for those rods in the connected component, calc how many intersect with their ranges

cycle uniquely determines all values


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

pair<bool, vector<int>> dfs(int cur, int par, vector<bool>& vis, vector<pair<ll, ll>>& cons, vector<int>& component) {
    for(auto& [neig, _] : cons) {
        if (neig != par && vis[par]) {
            
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vll l(n), r(n);
    // vector<array<ll, 3>> cons(m);
    vector<pair<ll, ll>> cons(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    for(int i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
        cons[x].push_back({y, z});
    }

    vector<pair<ll, ll>> lohi(n, {-1LL, -1LL});

    vector<bool> vis(n, 0);
    for(int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, cons);
        }
    }


    // check possible
    for(int x = 0; x < n; x++) {
        for(auto& [y, z] : cons[x]) {
            if(x == y) {        // self loop
                if(z % 2 != 0 || (lohi[x] != -1 && lohi[x] != z / 2)) {
                    cout << -1 << endl;
                    return;
                }
                lohi[x] = z / 2;
            }
        }
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


