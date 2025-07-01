/*
Avery Li
5/1/2025
Problem link: https://codeforces.com/problemset/problem/2014/D
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> pii;

using namespace std;

/**
 * maintain two:
 *  how many have started by a certain time
 *  how many have finshed by a cetain time
 */

void solve() {
    int n, d, k; cin >> n >> d >> k;
    vector<int> start(n, 0);
    vector<int> finish(n, 0);
    pii jobs(k);
    for(int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        start[l - 1] += 1;
        finish[r - 1] += 1;
        jobs[i] = pii({l, r});
    }
    sort(jobs.begin(),jobs.end(), [](pii a, pii b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }});

    int min_ans_val = INT_MAX;
    int min_ans_day = 0;
    int max_ans_val = 0;
    int max_ans_day = 0;
    int cur = 0;
    for(int i = 0; i < d; i++) {
        cur += start[i];
        if (cur < min_ans_val) {
            min_ans_val = cur;
            min_ans_day = i;
        }
        if (cur > max_ans_val) {
            max_ans_val = cur;
            max_ans_day = i;
        }
        cur -= finish[i];
    }

    for (int i = 0; i + d < n; i++) {
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
