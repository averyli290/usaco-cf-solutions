
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
use x=01...1 to determine if even or odd?

x=01...1
differentiate between & and |
if return val is odd, |
otherwise, if there is at least 1 extra 0, then &
otherwise, (v = x and ty=&) or ty=|


if & for sure, use m0=0.1.0, m1=0.0.0

otherwise, (v = x and ty=&) or ty=|
m0=01...1, m1=1...1
if ty = | and retval odd, m0^v odd and m1^v even
if ty = | and retval even, m0^v even and m1^v odd
if ty = & and v = 01...1, m0^v even
if ty = & and v = 01...1, m0^v even

m0=10...0, m1=0...0
if ty = | and retval odd, m0^v even and m1^v odd

if ty = | and retval even, m0^v odd and m1^v even
if ty = & and v = 01...1, m0^v even


randomly generate bitstring
if there is a 0 where there was a 1, ty = &, use that pos
if there is a 1 where there was a 0, ty = |, use that pos
otherwise, if ty=&, all 1s must have 1s and if ty=| all 0s must have 0s

x  =00000101011101

v!=x
& case (some 1->0)
v  =01010101011101
a  =11111010100010
a^v=10101111111111

| case (some 0->1)
v  =00000000011101
a  =11111010100010
a^v=11111010111111

v=x
v = 00000101011101
x = 00000101011101
a = 000001010111011
b = 000001010111010
x^b=000000000000001
x^a=000000000000000

keep last bit reserved



v!=x
& case (some 1->0)
v  =000101010111010
a = 000000010111010=y
b = 000001010111010=x
v^a=000101000000000
v^b=000100000000000

| case (some 0->1)
v  =00000000011101
a = 000000010111011=y
b = 000001010111010=x
v^a=000000010000001
v^b=000001010000000

v=x
v = 00000101011101
x = 00000101011101
a = 00000001011101
b = 00000101011101
x^a=00000100000000
x^b=00000000000000

x = 1

m0 = 2
m1 = 0
11 | 01 = 10
11 | 01 = 01
10 | 01 = 11

*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    ll res, m0, m1;

    ll x = uniform_int_distribution<ll>(0, (1LL << 30) - 1)(rng);
    cout << 1 << endl; cout.flush();
    cin >> res;
    if (res == 0) { // first bit is 0 and &
        m0 = 0; m1 = 1;
        cout << m0 << " " << m1 << endl; cout.flush();
        cin >> res;
        if (res == 0) cout << 0 << endl;
        else cout << 1 << endl;
        cout.flush();
        return;
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
    
}
