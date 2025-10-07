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
check prime density for bounds? seems good

precompute primes
*/

vector<bool> is_prime;
set<int> primes;


void dfs(int cur, vi& color, vector<vi>& adj, vector<bool>& vis, int n) {
    vis[cur] = true;
    set<int> colors;
    for(int neig : adj[cur]) {
        colors.insert(color[neig]);
    }
    for(int i = 1; i <= n; i++) {
        if (colors.find(i) == colors.end()) {
            color[cur] = i;
            break;
        }
    }
    for(int neig : adj[cur]) {
        if (!vis[neig]) {
            dfs(neig, color, adj, vis, n);
        }
    }
}
 
 
void solve() {
    int n; cin >> n;
    //vi color(n + 1, -1);
 
    if (n == 2) {
        cout << 2 << endl;
        cout << "1 2" << endl;
        return;
    }
    vector<vi> adj(n + 1, vi{});
    for(int i = n; i > 0; i--) {
        for(int p : primes) {
            int other = i ^ p;
            if (other > 0 && other <= n) {
                adj[i].push_back(other);
            }
        }
    }
 
    // find largest clique
    // int m = 1;
    // for(int i = 1; i <= n; i++) {
    //     m = max(m, sz(adj[i]));
    // }
 
    vi color(n + 1, -1);
    vector<bool> vis(n + 1, false);
    dfs(1, color, adj, vis, n);
 
    cout << *max_element(all(color)) << endl;
    for(int i = 1; i < n + 1; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n = 4E5 + 1;
    is_prime.assign(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
 
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.insert(i);
        }
    }
 
 
    // for(int i : primes) {
    //     cout << i << endl;
    // }
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}