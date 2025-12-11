/*
Problem link: https://codeforces.com/contest/2056/problem/C
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

110011


1 2345.... 11

3 * (n - 4)
3n - 12
2n - 12

123411
2 * 3

1234511
2 * 4 + 1



4n-8-n = 3n - 8
*/

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n - 2; i++) {
        cout << i << " ";
    }
    cout << "1 1" << endl;
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
