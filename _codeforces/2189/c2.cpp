

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
const long long INF = 1e18;


/*
xor with n=2^x for y<n is greater than 2^x, so ans[n]=n=2^x,
but ans[n-1] = n xor (n-1) > n, so cannot have config for 2^x

for others place 1 at the end

odd still works
even:
ans[n]=1
ans[n-1] = (n-1) xor 1 = n - 2
ans[n-2] = (n-2) xor 1 = n - 1
ans[n-3] = (n-3) xor 1 = n - 4
...
ans[2] = 2 xor 1 = 1
ans[1] = 1 xor 

get lsb of n
attempt to place n at 1, but need to place at index i s.t. n xor i < n
this is possible when i = 2^(lsb idx of n)
e.g. 1100 xor 0100 = 1000

*/
 
 
void solve() {
    int n ;cin >> n;
    vi ans(n + 1);
    int ctr = 0;
    int lsb = 31;
    for(int i = 0; i < 31; i++) {
        if ((n >> i) & 0b1 == 0b1){
            ctr++;
            lsb = min(lsb, i);
        }
    }
    if (ctr == 1) {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 0) {
        for(int i = 1; i <= n; i++) {
            if (i % 2 == 0) ans[i] = i + 1;
            else ans[i] = i - 1;
        }
        int temp = 1;
        while (lsb > 0) {
            temp *= 2;
            lsb--;
        }
        ans[1] = n;
        ans[n] = 1;
        swap(ans[1],ans[temp]);
    } else {
        for(int i = 1; i <= n; i++) {
            if (i % 2 == 0) ans[i] = i + 1;
            else ans[i] = i - 1;
        }
        ans[n] = n;
        ans[n - 1] = 1;
        ans[1] = n - 1;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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