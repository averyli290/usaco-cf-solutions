/*
Problem link: https://codeforces.com/contest/1991/problem/D
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
3 -> 10 -> 
odd -> even -> odd

k4
odd -> even -> odd -> even

k5 possible?
odd -> even -> even -> odd -> odd

1       2       3      4       5       1
odd -> even -> odd -> even -> odd -> (odd)
requires 1 and 5 to be twin primes, by symmetry and because k5,
1, 3, and 5 are all twin primes, but not possible.

therefore, only need to check up to k4

handle small cases separately

difference of 4 is not prime, assign (i % 4) + 1


*/

// vi color;
// vector<bool> sieve;
// vi primes;

void solve() {
    int n; cin >> n;
    if (n == 1){
        cout << 1 << endl << 1 << endl;
        return;
    }
    if (n == 2){
        cout << 2 << endl << "1 2" << endl;
        return;
    }
    if (n == 3){
        cout << 2 << endl << "1 2 2" << endl;
        return;
    }
    if (n == 4){
        cout << 3 << endl << "1 2 2 3" << endl;
        return;
    }
    if (n == 5){
        cout << 3 << endl << "1 2 2 3 3" << endl;
        return;
    }
    cout << 4 << endl;
    for(int i = 1; i <= n; i++) {
        cout << (i % 4) + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int maxn = 2e5;
    // color.assign(maxn + 1, 0);
    // sieve.assign(maxn + 1, true);
    // sieve[0] = false;
    // sieve[1] = false;
    // for(int i=2; i <=maxn;i++) {
    //     if (sieve[i]) {
    //         primes.push_back(i);
    //         for(int j = i + i; j <= maxn; j += i) {
    //             sieve[j] = false;
    //         }
    //     }
    // }

    // vector<bool> vis(maxn + 1, false);
    // queue<int> q;
    // q.push(1);
    // for(int i = 1; i <= 4; i++) {
    //     queue<int> next;
    //     while(!q.empty()) {
    //         int cur = q.front();
    //         vis[cur] = true;
    //         q.pop();
    //         color[cur] = i;
    //         for(int p : primes) {
    //             if (!vis[p ^ cur]) {
    //                 vis[p ^ cur] = true;
    //                 next.push(p ^ cur);
    //             }
    //         }
    //     }
    //     q = next;
    //     debug(sz(q));
    // }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
}
