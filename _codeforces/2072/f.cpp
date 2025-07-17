/*
Problem link: https://codeforces.com/contest/2072/problem/F
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
const long long INF = 1e18;
const long long MOD = 1e9 + 9;

/*
only need to compute half of it, then it is the same again
get corresponding pattern by taking current - 2^(floor(log_2(current))), adding 0's until
it is at least length(current) / 2, reverse and concatenate
*/

string f(int a) {
    int i = 0;
    while (i < 32 && (a >> i) % 2 == 0) {
        i++;
    }
    i++;
    while (i < 32 && (a >> i) % 2 == 0) {
        i++;
    }
    if (i == 32) return string(a, '1');
    int cur = 1;
    while (cur<<1 < a) cur <<= 1;
    int corr = (cur >> 1) + (a-cur);
    int diff = a - cur;
    string front = f(diff) + string(a / 2 - diff, '0');
    string back = front;
    reverse(all(back));
    if (a % 2 == 1) front += "0";
    return front + back;

}

void solve() {
    ll n, k; cin >> n >> k;
    for (char c : f(n)) cout << (c == '0' ? 0 : k )<< " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
