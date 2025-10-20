/*
Problem link: https://codeforces.com/contest/2154/problem/C1
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

min cost to get to each prime below 2 * 10^5

*/

vi primes;

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i++) {
        cin >> b[i];
    }
    sort(all(a));

    map<int, int> mincost;
    for(int p : primes) mincost[p] = 2E5;
    for(int i = 0; i < n; i++) {
        for (int p : primes) {
            mincost[p] = min(mincost[p], a[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=2E5;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++) { if (is_prime[i]) primes.push_back(i); }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    int k = sz(primes);
    int m = 0;
    for(int i = 0; i < k - 1; i++) {
        m = max(m, primes[i + 1] - primes[i]);
    }
    cout << k << endl;
    cout << m << endl;
    cout << primes[k - 1] << endl;
    cout << primes[k - 2] << endl;
    cout << primes[k - 3] << endl;
    
}
