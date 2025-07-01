#include<iostream>
#include<map>
#include<vector>

using namespace std;

int n;
char c;

int rec(int n, map<int, int>&d) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    int total = 0;
    for ( auto [k, v] : d) {
        if (v > 0) {
            d[v] -= 1;
            total += rec(n - k, d);
            d[v] += 1;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    auto value_conv = [](int a) { if (a <= 10) { return a; } return 10; };

    map<char, int> rank_conv;
    rank_conv['A'] = 1; rank_conv['2'] = 2; rank_conv['3'] = 3; rank_conv['4'] = 4; rank_conv['5'] = 5; rank_conv['6'] = 6;
    rank_conv['7'] = 7; rank_conv['8'] = 8; rank_conv['9'] = 9; rank_conv['T'] = 10; rank_conv['J'] = 11; rank_conv['Q'] = 12;
    rank_conv['K'] = 13;

    map<int, int> rank_dict;
    map<int, int> value_dict;
    for(int i = 1; i <= 13; i++) {
        rank_dict[i] = 0;
    }
    for(int i = 1; i <= 10; i++) {
        value_dict[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        cin >> c;
        rank_dict[rank_conv[c]] += 1;
        value_dict[value_conv(rank_conv[c])] += 1;
    }

    int ans = 0;


    // pairs
    for(auto [k, v] : rank_dict) {
        if (v >= 2) {
            ans += v * (v - 1);
        }
    }
    cout << ans << '\n';

    // run
    vector<pair<int, int>> runs;
    int run_left = 0;
    int run_right = 0;
    int left = 0;
    
    for(int i = 1; i <= 13; i++) {
        if (rank_dict[i] == 0) {
            left = i;
        } else if (i - left > run_right - run_left) {
            run_right = i;
            run_left = left;
        }
    }

    int cur = run_right - run_left - 2;
    for (int i = run_left + 1; i <= run_right; i++) {
        cur *= rank_dict[i];
    }
    ans += cur;
    cout << ans << '\n';

    // 15's
    ans += rec(15, value_dict) * 2;
    cout << ans << '\n';

}