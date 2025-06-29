#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");


    int n, b; fin >> n >> b;

    vector<pair<int, int>> pos;
    unordered_set<int> x_vals{};
    unordered_set<int> y_vals{};

    int x, y;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        pos.push_back(pair<int, int>{x, y});
        x_vals.insert(x - 1);
        y_vals.insert(y - 1);
    }

    int ans = INT32_MAX;
    for (int x : x_vals) {
        for (int y : y_vals) {
            int q1 = 0;
            int q2 = 0;
            int q3 = 0;
            int q4 = 0;
            for (auto p : pos) {
                if (p.first < x) {
                    if (p.second < y) {
                        q1++;
                    } else {
                        q2++;
                    }
                } else if (p.second < y) {
                    q3++;
                } else {
                    q4++;
                }
            }
            ans = min(ans, max(q1, max(q2, max(q3, q4))));
        }

    }

    fout << ans;

    /*
    int n, b; fin >> n >> b;
    vector<vector<int>> grid(b, vector<int>(b, 0));
    vector<int> num_in_row(b, 0);
    vector<int> num_in_col(b, 0);
    unordered_set<int> x_vals{};
    unordered_set<int> y_vals{};

    int x, y;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        grid[x][y]++;
        num_in_row[y]++;
        num_in_col[x]++;
        x_vals.insert(x);
        y_vals.insert(y);
    }

    vector<int> x_vals_sorted;
    vector<int> y_vals_sorted;

    for (int a : x_vals) {
        x_vals_sorted.push_back(a);
    }
    for (int a : y_vals) {
        y_vals_sorted.push_back(a);
    }

    sort(x_vals_sorted.begin(), x_vals_sorted.end());
    sort(y_vals_sorted.begin(), y_vals_sorted.end());

    vector<vector< vector<int> >> dp(x_vals.size() + 1, vector< vector<int> >(y_vals.size() + 1, vector<int>{0,0,0,0}));

    // 1 | 0
    // --+--
    // 2 | 3

    // dp[i][j] gives the number of cows in each quadrant using the indices as above
    // with lines at x = x_vals[i] - 1 and y = y_vals[j] - 1.

    dp[0][0] = vector<int>{n,0,0,0};

    fout << 2;    
    */ 

}
