/*
Problem link: https://codeforces.com/contest/2114/problem/F
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;


/*
x/gcd(x, y)
y/gcd(x, y)
prime factorize x/gcd(x,y) for stuff to divide out
prime factorize y/gcd(x,y) for stuff to multiply by
if any prime factor greater than k, impossible
*/

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

ll gcd(ll x, ll y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

// int min_steps(vector<ll> &factors, vector<int> used, ll k, ll cur_prod = 1) {
//     bool done = true;
//     for (int u : used) {
//         if (u == 0) { done = false; }
//     }
//     if (done) {
//         if (cur_prod == 1) {
//             return 0;
//         } else {
//             return 1;
//         }
//     }
//     vector<int> res;
//     for(int i = 0; i < factors.size(); i++) {
//         if (!used[i] && factors[i] * cur_prod <= k) {
//             vector<int> new_used = used;
//             new_used[i] = 1;
//             res.push_back(min_steps(factors, new_used, k, cur_prod * factors[i]));
//         }
//     }
//     if (cur_prod != 1) {
//         res.push_back(1 + min_steps(factors, used, k, 1));
//     }
//     return *min_element(res.begin(), res.end());
// }

void solve() {
    ll x, y, k; cin >> x >> y >> k;

    ll g = gcd(x, y);
    ll down = x / g;
    ll up = y / g;

    vector<ll> factors_down = trial_division1((ll) down);
    vector<ll> factors_up = trial_division1((ll) up);
    sort(factors_down.begin(), factors_down.end());
    sort(factors_up.begin(), factors_up.end());

    vector<int> down_used(factors_down.size(), 0);
    vector<int> up_used(factors_up.size(), 0);
    if (factors_down.size() > 0 && factors_down[factors_down.size() - 1] > k) {
        cout << -1 << endl;
        return;
    }
    if (factors_up.size() > 0 && factors_up[factors_up.size() - 1] > k) {
        cout << -1 << endl;
        return;
    }

    // vector<int> used_down(factors_down.size(), 0);
    // int ans = 0;
    // ans += min_steps(factors_down, used_down, k, 1);
    // //cout << ans << endl;
    // vector<int> used_up(factors_up.size(), 0);
    // ans += min_steps(factors_up, used_up, k, 1);

    int ans = 0;
    while (1) {
        int cur = factors_down.size() - 1;
        while (cur >= 0 && down_used[cur] == 1) {
            cur--;
        }
        if (cur == -1) {
            break;
        }
        ll cur_prod = 1;
        for (int i = cur; i >= 0; i--){
            if (!down_used[i] && cur_prod * factors_down[i] <= k) {
                cur_prod *= factors_down[i];
                down_used[i] = 1;
            }
        }
        ans++;
    }
    while (1) {
        int cur = factors_up.size() - 1;
        while (cur >= 0 && up_used[cur] == 1) {
            cur--;
        }
        if (cur == -1) {
            break;
        }
        ll cur_prod = 1;
        for (int i = cur; i >= 0; i--) {
            if (!up_used[i] && cur_prod * factors_up[i] <= k) {
                cur_prod *= factors_up[i];
                up_used[i] = 1;
            }
        }
        ans++;
    }

    cout << ans << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
