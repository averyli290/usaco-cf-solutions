/*
Avery Li
4/24/2025
Problem link: https://codeforces.com/contest/2106/problem/E
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

/*
idea:
we cannot move the element to search, so if the element
is outside of our range impossible immediately.

take the bitstring of the element's index relative to the left side
of the range (where the left side is 0)
Then, for each bit in the bitstring check that within the range [l, r],

if the bit is a 0, there are 2^(bit index) numbers less than the element to search for
if the bit is a 1, there are 2^(bit index) numbers greater than the element to search for

not sure if correct, still just idea

*/

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
