/*
Problem link: https://codeforces.com/contest/2093/problem/G
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
https://www.youtube.com/watch?v=Dy5Ewm0zJ_0

idek how much longer htis is gonna be
holy crackers breakfast is ready
*/

const int K = 2;
struct TrieNode {
    int next[K];
    int maxidx; // STORE IT HERE or smth
    
    TrieNode() {
        fill(begin(next), end(next), -1);
        maxidx = -1;
    }
};

void insert(vector<TrieNode>& trie, int x, int idx) {
    int curnode = 0;
    for(int i = 30; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (trie[curnode].next[c] == -1) {
            trie[curnode].next[c] = sz(trie);
            trie.emplace_back();
        }
        curnode = trie[curnode].next[c];
        trie[curnode].maxidx = max(trie[curnode].maxidx, idx);
    }
}

int check(vector<TrieNode>& trie, int x, int k) {// dont copy it lol
    int cur = 0;
    int ans = -1;
    for(int i = 30; i >= 0; i--) {
        if (cur == -1) break;       // no more to go
        int c = (x >> i) & 1;
        int kbit = (k >> i) & 1;
        if (kbit == 0) {
            if (trie[cur].next[!c] != -1) {     // can choose any from this subtree
                ans = max(ans, trie[trie[cur].next[!c]].maxidx);
            }
            cur = trie[cur].next[c];            // check here also
        } else {
            if (trie[cur].next[!c] == -1) {     // ur fucked now return the best u got
                return ans;
            }
            cur = trie[cur].next[!c];           // good here
        }
    }
    if (cur != -1) ans = max(ans, trie[cur].maxidx);        // last update, its still possible to obtain here
    return ans;
}



void solve() {
    int n, k; cin >> n >> k;

    vector<TrieNode> trie(1);
    int ans = n + 1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(trie, x, i);                 // insert also updates the max idx which passes thru a prefix of trie
        int idx = check(trie, x, k);        // idx is max idx which produces xor >= k
        // debug(idx);
        if (idx >= 0) ans = min(ans, i - idx + 1);
    }

    if (ans > n) cout << -1 << endl;
    else cout << ans << endl;
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
