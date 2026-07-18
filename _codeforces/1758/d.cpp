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

1->n-1
n(n+1)(2n+1)/6

x^2 + n(n-1)(2n-1)/6 = 

n(n+1)/2 + n(n + 1)/2
n(n + 1)
1 + 3 + 5 + 7 + 9 + ... = 


1^2, 2^2, 3^2, ..., 4^2

5^2-3^2=(5+3)(5-3)=8*2=4^2

x^2 is sum, (x - 1) * 2 is diff

x^2 - 2x - 2 is sometimes odd
when x^2 is even, can calc

when x^2 is odd, add (x + 2)^2-(x^2) to get (x+2)^2
now sum is (x+2)^2 and diff is (2x - 1 + 2)*2 - 1

(2x^2) is sum, 6 (x - 1) is diff

(1+3+5+7+9)+((13-5)(13+5))

n - 1

*/

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        // ((21+7)-1)-sqrt((1+3+5+7+9+11+13)+((21-7)(21+7)))

        // (1 + 3 + 5) + (-3)

        int cur = 0;
        vector<int> ans;
        int ctr = 1;
        for(int i = 0; i < n - 1; i++) {
            ans.push_back(ctr);
            cur += ctr;
            ctr += 2;
        }
        ctr -= 2;
        debug(ctr);
        ctr += n;
        debug(ctr);
        debug(cur);
        debug((ctr - (n - 1)) * (ctr + (n - 1)))
        ans.push_back((ctr - (n - 1)) * (ctr + (n - 1)));
        cur += (ctr - (n - 1)) * (ctr + (n - 1));
        // cur = ctr * ctr;
        debug(sqrt(cur));
        ans.push_back(sqrt(cur) - (ctr + (n - 1) - 1));
        debug(cur);

        int check = 0;
        for(int i : ans) {
            debug(i);
            check += i * i;
        }
        debug(check);
        assert(((ctr - n) * (ctr + n) - 1) * ((ctr - n) * (ctr + n) - 1) == check);
    } else {
        cout << -1 << endl;
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
