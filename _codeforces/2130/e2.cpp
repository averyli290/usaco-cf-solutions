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

int search(int n, int left, int right) {
    int l = left;
    int r = right;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? " << m << " ";
        for(int i = 1; i <= m; i++) {
            cout << i << " ";
        }
        cout << "\n";
        cout.flush();
        int res; cin >> res;
        if (res == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

typedef array<int, 6> binnum;

string repeat(int c, string s) {
    string res = "";
    for(int i = 0; i < c; i++) res += s;
    return res;
}

string construct(binnum bnum, string forward, string backward) {
    string res = " ";
    int tot = 0;
    for(int i = 5; i >= 0; i--) {
        res += to_string(bnum[i]) + " ";
        tot++;
        res += backward + " ";
        tot++;
        res += repeat((1 << i) - 1, forward + " " + backward + " ");
        tot += ((1 << i) - 1) * 2;
        if (i == 0) continue;
        res += backward + " ";
        tot++;
    }
    return to_string(tot) + res;
}

// )((
 
void solve() {
    int n; cin >> n;
    int f = search(n, 0, n + 1);
    int b = f + 1;
    if (f == n) { b = 1; }
    string forward = to_string(f);
    string backward = to_string(b);

    cout << "? " << construct(binnum{f,f,f,f,f,f}, forward, backward) << "\n";
    cout.flush();
    int base; cin >> base;
 
    string ans = "";
    for(int i = 1; i <= n; i += 6) {
        binnum temp;
        for(int j = 0; j < 6; j++) {
            if (i + j > n) {
                temp[j] = b;
            } else {
                temp[j] = i + j;
            }
        }
        cout << "? " << construct(temp, forward, backward) << "\n";
        cout.flush();
        int x; cin >> x;
        x = base - x;
        for(int j = 0; j < 6; j++) {
            if (i + j > n) break;
            if (x & (0b1 << j)) {
                ans += ")";
            } else {
                ans += "(";
            }
        }
    }
    cout << "! " << ans << "\n";
    cout.flush();
}

// )()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}

/*

((((((
5))))))))))))))))))))))))))))))))4))))))))))))))))3))))))))2))))1))0)
(5))))))))))))))))))))))))))))))))(4))))))))))))))))(3))))))))(2))))(1))(0)
(5)))))))))))))))))))))))))))))))))(4)))))))))))))))))(3)))))))))(2)))))(1)))(0))
actual string used: ...+(+[5]*{32+1}+{32+1}*)+(+[4]*{16+1}+{16+1}*)+(+[3]*{8+1}+{8+1}*)+(+[2]*{4+1}+{4+1}*)+(+[1]*{2+1}+{2+1}*)+(+[0]*{1+1}+{1+1}*)


f(string) - 7 produces binary code, 1='(', 0=')'
if 0 = ), +1
if 0 = (, +1+1
if 1 = ), +1
if 1 = (, +1+2
if 2 = ), +1
if 2 = (, +1+4
if 3 = ), +1
if 3 = (, +1+8
if 4 = ), +1
if 4 = (, +1+16
if 5 = ), +1
if 5 = (, +1+32
if 6 = ), +1
if 6 = (, +1+64
nvm just check editorial i couldn't get above solution to work

([2]()()() ) ([1]() ) ([0]

*/
 