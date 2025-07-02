/*
Problem link: https://codeforces.com/contest/2123/problem/F
*/

#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const long long INF = 1e18;

/*
swapping any two numbers in a good permutation where gcd != 1 is still good (nope actually)
3 5
6 10 

can pair off numbers
what is best way to pair off

any two even numbers can be swapped

any prime number p where p * 2 > n is fixed


get list of prime numbers which p * 2 <= n

get the cycle associated with it, rotate it

*/

const int MAX_N = 1e5 + 1;
vi primes;
vector<bool> arr;

void gen_primes() {
    arr.assign(MAX_N, false);
    primes = vi{};
    for (int i = 2; i < MAX_N; i++) {
        if (arr[i] == 0) {
            primes.push_back(i);
            for(int j = i + i; j < MAX_N; j += i) {
                arr[j] = 1;
            }
        }
    }
}

void solve() {
    int n; cin >> n;

    if(n == 2) {
        cout << "1 2" << endl;
        return;
    } if(n == 3) {
        cout << "1 2 3" << endl;
        return;
    }

    int m = n / 2;
    while (arr[m]) {
        m--;
    }

    //cout << n << " " << m << endl;
    int maxidx = find(all(primes), m) - primes.begin();
    //cout << "maxidx " << maxidx << endl;

    vi ans(n + 1, 0);
    for (int i = 0; i < n + 1; i++) ans[i] = i;
    vector<bool> used(n + 2, false);

    while (maxidx >= 0) {
        vi currot;
        int p = primes[maxidx];
        for(int cur = p; cur <= n; cur += p) {
            if (!used[cur]) {
                currot.push_back(cur);
                used[cur] = 1;
            }
        }
        for (int i = 0; i < sz(currot); i++) {
            ans[currot[i]] = currot[(i + 1) % sz(currot)];
        }
        maxidx--;
    }

    for (int i = 1; i < n + 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    gen_primes();
    //cout << "primes done" << endl;

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}