/*
Problem link: https://codeforces.com/contest/2109/problem/C1
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

/*
1. digit
2. digit
3. digit
x in range [1,9]
4. mul 9 [9, 18, ..., 81]
5. digit
x = 9
5. add -8
x = 1
7. add n - 1
*/

int command1(string s, int num) {
    cout << s << " " << num << endl; cout.flush();
    int resp; cin >> resp; return resp;
}

int command2(string s) {
    cout << s << endl; cout.flush();
    int resp; cin >> resp; return resp;

}

void solve() {
    int n; cin >> n;

    int resp;
    command2("digit");
    command2("digit");
    command2("digit");
    command1("mul", 9);
    command2("digit");
    command1("add", -8);
    command1("add", n - 1);
    command2("!");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
