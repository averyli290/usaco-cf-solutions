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

bool test(string s, int x) {
    string t = "";
    bool used_one = false;
    for(int i = 0; i < s.length(); i++) {
        if (((x >> i) & 0b1) == 0b0) {
            t += s[i];
        } else {
            if(s[i] == '1') used_one = true;
            else if (used_one) {
                return false;
            }
        }
    }
    string temp = t;
    reverse(all(temp));
    // debug(t);
    // debug(temp);
    return temp == t;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < (1 << s.length()); i++) {
        if (test(s, i)) {
            vi ans;
            for(int j = 0; j < s.length(); j++) {
                if (((i >> j) & 0b1) == 0b1) ans.push_back(j + 1);
            }
            cout << sz(ans) << endl;
            for (int v : ans) cout << v << " ";
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
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
