#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;

struct h {
    size_t operator()(const pii& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int sta() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if (a > c || b > d) return -1;
    
    unordered_map<pii, int, h> dp;
    queue<pii> q;
    
    dp[{a, b}] = 0;
    q.push({a, b});
    
    while (!q.empty()) {
        auto [cur_a, cur_b] = q.front();
        q.pop();
        
        if (cur_a + cur_b <= c) {
            pii next = {cur_a + cur_b, cur_b};
            if (dp.find(next) == dp.end() || dp[next] > dp[{cur_a, cur_b}] + 1) {
                dp[next] = dp[{cur_a, cur_b}] + 1;
                q.push(next);
            }
        }
        
        if (cur_a + cur_b <= d) {
            pii next = {cur_a, cur_a + cur_b};
            if (dp.find(next) == dp.end() || dp[next] > dp[{cur_a, cur_b}] + 1) {
                dp[next] = dp[{cur_a, cur_b}] + 1;
                q.push(next);
            }
        }
    }
    
    if (dp.find({c, d}) == dp.end()) return -1;
    return dp[{c, d}];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << sta() << "\n";
    }
    return 0;
}
