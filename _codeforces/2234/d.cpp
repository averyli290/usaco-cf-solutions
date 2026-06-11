/*
Problem link: https://codeforces.com/contest/2234/problem/D
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

1, 9
1: 1,0
9: 0,1
{1,0,1}

1, 5, 9
1: 1,0
5: 1,1
9: 0,1

{1,1,1}

1, 3, 5, 7, 9
1: 1,0
3: 2,1
5: 1,1
7: 1,2
9: 0,1

1: 1,0
3: 0,1
5: 1,1
7: 1,0
9: 0,1
{2,1,2}

1, 2, 3, 4, 5, 6, 7, 8, 9
1: 1,0
2: 1,1
3: 0,1
4: 1,0
5: 1,1
6: 0,1
7: 1,0
8: 1,1
9: 0,1
{3,3,3}

each 1,1 will add 1 to the others
1: 1,0
1: 0,1
2: 1,1
1: 1,0
3: 0,1
2: 1,1
4: 1,0
2: 0,1
5: 1,1
2: 1,0
6: 0,1
2: 1,1
7: 1,0
2: 0,1
8: 1,1
2: 1,0
9: 0,1
{6,5,6}

{11,11,11}


*/

void solve() {
    int n, k; cin >> n >> k;
    string s1, s2; cin >> s1 >> s2;
    vll freq(3,0ll);
    freq[0]=1ll;
    freq[2]=1ll;
    for(int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            freq[0] += freq[1];
            freq[2] += freq[1];
            freq[1] = freq[0];
        } else {
            ll temp = freq[1];
            freq[1] += freq[0] - 1;
            freq[0] += temp;
            freq[2] += temp;
        }
    }
    // debug(freq[0]);
    // debug(freq[1]);
    // debug(freq[2]);

    function<ll(string)> calc = [&] (string x) {
        array<ll, 2> a = {0ll, 0ll};
        for(char c : x) a[c - '0']++;
        return a[0] * a[1];
    };

    string B = "";
    for(int i = 0; i < n; i++) {
        int x = s1[i] - '0';
        int y = s2[i] - '0';
        if (x ^ y == 0) B += '0';
        else B += '1';
    }
    cout << freq[0] * calc(s1)+freq[1] * calc(B)+freq[2] * calc(s2) << endl;
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
