/*
Problem link: https://codeforces.com/contest/1991/problem/F
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
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;


/*
1,2,3,5,8,13,21,34,
sorted array, check three consec
sum of greater two > smallest
want smallest to be as large as possible to make sum with mid as large as possible

either 6 consecutive sticks OR 2 sets of disjoint 3 consecutive sticks
if not 6 consecutive, optimal/greedy solution is to get 3 consecutive sticks bc those consecutive numbers are closest together,
so just check if they are disjoint.

easier to think of getting two sets of 3 consecutive sticks and then check 6 consecutive sticks after
because two adjacent sets of 3 consecutive sticks doesn't cover all cases, need all permutations of 6 consecutive sticks by counterexample
ex: 2 2 4 4 4 4
2 2 4 doesn't work, 4 4 4 does work, so first check 2 sets doesn't work
2 4 4, 2 4 4 works though

*/

void solve() {

    int n, q; cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int qc = 0; qc < q; qc++) {
        int l, r; cin >> l >> r;
        if (r - l >= 50) {  // use fib as worst case this seems good enough?
            cout << "YES" << endl;
        } else {
            // check manually
            // how lol
            vi temp(a.begin() + l - 1, a.begin() + r);
            sort(all(temp));
            // check consecutive and non consecutive bc sorted
            // consecutive
            bool good = false;
            for(int i = 0; i < sz(temp) - 5 && !good; i++) {
                for(int a = 0; a < 6 && !good; a++) {
                for(int b = a + 1; b < 6 && !good; b++) {
                for(int c = b + 1; c < 6 && !good; c++) {
                    if (temp[a + i] + temp[b + i] > temp[i + c]) {
                        int other = 0;
                        int ctr = 0;
                        for(int d = 0; d < 6; d++) {
                            if (d != a && d != b && d != c) {
                                if (ctr < 2) {
                                    other += temp[d + i];
                                    ctr++;
                                }
                                else if (other > temp[d + i]) {
                                    good = true;
                                }
                            }
                        }
                    }
                }
                }
                }
            }
            if (good) {
                cout << "YES" << endl;
                continue;
            }

            // non consecutive
            vi good_vec;        // stores the starting index of non degen triangle
            for(int i = 0; i < sz(temp) - 2; i++) {
                if (temp[i] + temp[i + 1] > temp[i + 2]) {
                    good_vec.push_back(i);
                }
            }
            if (sz(good_vec) >= 2 && good_vec[sz(good_vec) - 1] - 3 >= good_vec[0]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    // int fib1 = 1;
    // int fib2 = 1;
    // int ctr = 0;
    // while (fib1 < 1E9) {
    //     fib1 += fib2;
    //     swap(fib1, fib2);
    //     ctr++;
    // }
    // cout << fib1 << endl;
    // cout << ctr << endl;
    // 44th fib number

}
