/*
Problem Link: https://codeforces.com/problemset/problem/1857/F

z^2+bz+c=0

a_i + a_j = x = -b
a_i * a_j = y = c

z^2+(-a_i-a_j)z+(a_i*a_j) = 0

(-b\pm sqrt(b^2-4ac))/2a
=
x\pm sqrt(x^2-4y)/2

??? cant implement correctly, runtime error on test 4...
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;

using namespace std;

void solve() {
    int n; cin >> n;
    unordered_map<int, int> freq;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        freq[temp]++;
    }

    for (auto& [k, v] : freq) {
        a.push_back(k);
    }

    sort(a.begin(), a.end());

    int q, x, y; cin >> q;
    int s = a.size();
    while (q--) {
        int ans = 0;
        cin >> x >> y;
        int b = -x; int c = y;
        if (b * b >= 4 * c) {
            long double r1 = (-b + sqrtl(b * b - 4 * c)) / 2;
            long double r2 = (-b - sqrtl(b * b - 4 * c)) / 2;

            if (r1 == floor(r1)) {
                int key = (int) r1;
                if (x - key == key) {
                    ans += freq[key] * (freq[key] - 1) / 2;
                } else {
                    ans += freq[key] * freq[x - key];
                }
                // if (x - r1 == r1) {
                //     ans += freq[r1] * (freq[r1] - 1) / 2;
                // } else {
                //     ans += freq[r1] * freq[x - r1];
                // }
            } else if (r2 == floor(r2)) {
                // if (x - r2 == r2) {
                //     ans += freq[r2] * (freq[r2] - 1) / 2;
                // } else {
                //     ans += freq[r2] * freq[x - r2];
                // }
                int key = (int) r2;
                if (x - key == key) {
                    ans += freq[key] * (freq[key] - 1) / 2;
                } else {
                    ans += freq[key] * freq[x - key];
                }
            }
        }

        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
