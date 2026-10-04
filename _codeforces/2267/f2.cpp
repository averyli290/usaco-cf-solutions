/*
Problem link:
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
*/

const int K = 2;

struct TrieNode {
    int next[K];
    bool has = false;
    int ct = 0;
    
    TrieNode() {
        fill(begin(next), end(next), -1);
    }
};

void insert(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) {
            trie[curnode].next[c] = sz(trie);
            trie.emplace_back();
        }
        curnode = trie[curnode].next[c];
        trie[curnode].ct++;
    }
    trie[curnode].has = true;
}

void erase(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) return;
        curnode = trie[curnode].next[c];
        trie[curnode].ct--;
    }
    trie[curnode].has = false;
}

int traverse(vector<TrieNode>& trie, int& s) {
    int curnode = 0;
    int res = 0;
    for(int i = 31; i >= 0; i--) {
        int c = (s >> i) & 1;
        if (trie[curnode].next[c] == -1) {  // ended here
            for(int j = i - 1; j >= 0; j--) res += (s >> j) & 1;
            return res;
        }

        curnode = trie[curnode].next[c];
        if (trie[curnode].ct <= 1) res += (1 << i);
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    vi ans(100);

    for(int i = 0; i < 3; i++) {
        vector<TrieNode> T(1);
        for(int j = 0; j < n; j++) {
            insert(T, a[j]);
        }
        ans[i] = a.back() - a.front();
        vi newa;
        for(int j = 0; j < n; j++) {
            newa.push_back(a[j]);
            int temp = traverse(T, a[j]);
            debug(a[j]);
            debug(temp);
            if (temp > -1) newa.push_back(temp);
            erase(T, a[j]);
            // cout << a[j] << " " << newa[j] << endl;
        }
        sort(all(newa));
        a.clear();
        for(int j = 0; j < n; j++) {
            a.push_back(newa[j]);
        }
        // cout << ans[i] << endl;
        for(int j : a) cout << j << " ";
        cout << endl;
        cout << endl;
    }



    while(q--) {
        int x; cin >> x;
        cout << ans[min(x, 99)] << endl;
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

    // vector<TrieNode> T(1);
    // int x = 5;
    // insert(T, x);
    // cout << traverse(T, x) << endl;
    
}
