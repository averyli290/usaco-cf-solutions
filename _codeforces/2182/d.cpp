// /*
// Problem link: https://codeforces.com/contest/2182/problem/D
// */

// #include <bits/stdc++.h>

// using namespace std;
// #define sz(x) int((x).size())
// #define all(x) begin(x), end(x)
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// #define debug(x) cout << #x << " is " << x << endl;
// #define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
// #define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
// const long long INF = 1e18;
// const long long MOD = 998244353;


// /*
// always try to pick from own box first then from shared

// worst case:
// smallest to biggest

// when is it not possible?
// there are still 
// for a subset

// take the max, consider which place it is in permutation

// 1, 2, ,.., idx, idx+1, .., n
// needed = idx * max + (n - idx)*(max - 1)

// can place any of the rest in any of the other places

// what about if there are multiple maxes? divide by max factorial at the end

// if needed - boxtotal <= a[0], then we can cover empty spaces with the 0th box

// if multiple maxes, all of them have to fit before a the index which is deemed good


// 6 1 4 2 1
// boxtotal=8

// 6 4 x x x
// needed=4+3*3=13
// fill=5
// 3*2*1 = 6

// 6 x 4 x x
// needed=4*2+3*2=14
// fill=6

// 3*2*1 = 6


// 6 4 4 2 1
// boxtotal=11

// 6 4 4 x x
// needed=4*2+3*2=14
// fill=3
// 2*1=2

// 6 x x 4 x
// needed=4*3+3*1=15
// fill=4
// 2*2*1=4

// 6 x x x 4
// needed=4*4=16
// fill=5
// 3 * 2 * 1 = 6

// */


// void solve() {
//     ll n; cin >> n;
//     vll a(n+1);
//     for(int i = 0; i < n + 1; i++) {
//         cin >> a[i];
//     }
    
//     ll boxtotal = accumulate(a.begin() + 1, a.end(), 0LL);
//     ll m = *max_element(a.begin() + 1, a.end());
//     ll maxelt_ct = 0;
//     for(int i = 1; i < n+1; i++) if (a[i] == m) maxelt_ct++;
//     // debug(boxtotal);

//     ll ans = 0LL;
//     for(ll i = 0; i < n; i++) {
//         ll needed = (i + 1) * m + (n - (i + 1)) * (m - 1);
//         // debug(needed);
//         // debug(needed - boxtotal);
//         // debug(ans);
//         if(needed - boxtotal <= a[0] && needed - boxtotal >= 0 && i + 1 >= maxelt_ct) { // ensure all maxelts can fit in front
//             ll curans = 1LL;
//             curans *= maxelt_ct;    // can start with any of the max elts

//             for(ll j = 0; j < maxelt_ct - 1; j++) { // place maxelts, with already one fixed at idx i + 1
//                 curans = (curans * ((i + 1) - 1 - j)) % MOD;
//             }
//             // debug(curans);

//             for(ll j = 0; j < n - maxelt_ct; j++) { // place rest
//                 curans = (curans * ((n - maxelt_ct) - j)) % MOD;
//             }
//             ans = (ans + curans) % MOD;
//         }
//     }
//     cout << ans << endl;

// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
    
// }


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
const long long MOD = 998244353;


/*
always try to pick from own box first then from shared

worst case:
smallest to biggest

when is it not possible?
there are still 
for a subset

take the max, consider which place it is in permutation

1, 2, ,.., idx, idx+1, .., n
needed = idx * max + (n - idx)*(max - 1)

can place any of the rest in any of the other places

what about if there are multiple maxes? divide by max factorial at the end

if needed - boxtotal <= a[0], then we can cover empty spaces with the 0th box

if multiple maxes, all of them have to fit before a the index which is deemed good

*/

ll inv(ll a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

void solve() {
    ll n; cin >> n;
    vll a(n+1);
    for(int i = 0; i < n + 1; i++) {
        cin >> a[i];
    }
    
    ll boxtotal = accumulate(a.begin() + 1, a.end(), 0LL);
    ll m = *max_element(a.begin() + 1, a.end());
    ll maxelt_ct = 0;
    for(int i = 1; i <= n; i++) if (a[i] == m) maxelt_ct++;

    ll ans = 0LL;
    for(ll i = 0; i < n; i++) {
        ll needed = (i + 1) * m + (n - (i + 1)) * (m - 1);
        if(needed - boxtotal <= a[0]) {
            ll curans = maxelt_ct;
            if(i + 1 < maxelt_ct) continue;        // all maxelts have to fit in front

            for(ll j = 0; j < maxelt_ct - 1; j++) { // place maxelts
                curans = (curans * ((i + 1) - 1 - j)) % MOD;
            }

            for(ll j = 0; j < n - maxelt_ct; j++) { // place maxelts
                curans = (curans * ((n - maxelt_ct) - j)) % MOD;
            }
            ans = (ans + curans) % MOD;
        }
    }
    cout << ans << endl;

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
