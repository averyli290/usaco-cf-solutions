/*
Problem link: https://codeforces.com/contest/2124/problem/D
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef vector<int> vi;


/*
b[i + 1] = x (mod b[i])

get min required factors to satisfy for each pair which 
doesn't divide properly
*/

void solve() {
    int n; cin >> n;
    vi b(n);
    for(int i =0;i <n;i++) {
        cin >> b[i];
    }

    int ans = 1;
    for(int i = 0; i < n - 1; i++) {
        if (b[i + 1] % b[i] != 0) {
            int g = b[i] / gcd(b[i], b[i + 1]);     // has to include remaining factors in mult
            ans = lcm(ans, g);
        }
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
