/*
Problem link: https://codeforces.com/contest/1735/problem/C
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


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, char> mp;
    set<char> rem;
    for(int i =0;i<26;i++) rem.insert('a'+i);
    string ans;
    for(int i = 0; i < n; i++) {
        char cur = s[i];
        if (mp.find(cur) == mp.end()) {
            for (char cand : rem) {
                bool good = true;
                if(cand == cur) good = false;
                char val = cand;
                int ctr = 1;
                while (mp.find(val) != mp.end()) {
                    if (mp[val] == cur && ctr < 25) {
                        good = false;
                    }
                    ctr++;
                    val = mp[val];
                }
                if (good) {
                    mp[cur] = cand;
                    rem.erase(cand);
                    break;
                }
            }
        }
        ans += mp[cur];
    }
    cout << ans << endl;
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
