/*
Problem link: https://codeforces.com/contest/2094/problem/G
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
keep and maintain sums running in both directions, update fast by using two deques
and swapping between which one to print

2a+3b+1c = (a+2b+3c)+(a+b+c)-len*last

b+2a + (b+a) + c = 1c+2b+3a

*/


void solve() {
    int q; cin >> q;
    ll flatsum = 0;
    ll ans_1 = 0;
    ll ans_2 = 0;
    ll len = 0;

    deque<ll> d1;
    deque<ll> d2;

    while(q--) {
        int query; cin >> query;
        if (query == 3) {
            ll k; cin >> k;
            d1.push_back(k);
            d2.push_front(k);
            flatsum += k;
            // update append
            len++;
            ans_1 += len * k;
            // update prepend 
            ans_2 += flatsum;
        } else if (query == 2) {
            swap(ans_1, ans_2);
            swap(d1, d2);
        } else if (query == 1) {
            ans_1 += flatsum;
            ans_1 -= len * d1.back();
            //cout << "ans2 before; " << ans_2 << endl;
            ans_2 -= flatsum;
            ans_2 += len * d2.front();
            //cout << "len: " << len << endl;
            //cout << "ans2 front" << d2.front() << endl;
            d1.push_front(d1.back());
            d1.pop_back();
            d2.push_back(d2.front());
            d2.pop_front();
            //cout << "ans2 after; " << ans_2 << endl;
        }
        cout << ans_1 << endl;
        // cout << ans_1 << ": " << query << endl;
        // for(ll v : d1) {
        //     cout << v << " ";
        // }
        // cout << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}