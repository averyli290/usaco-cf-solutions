#include <iostream>
#include<vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n; cin >> t;
    for(int i=0; i < t; i++) {
        cin >> n;
        vector<int> b_f(n, 0);
        vector<vector<int>> b_f_r(n, vector<int>{});
        int f;
        for(int j=0; j < n; j++) {
            cin >> f;
            f -= 1;
            b_f[j] = f;
            b_f_r[f].push_back(j);
        }
        for(int j=0; j < n; j++) {
            if (b_f_r[])
        }
    }
}
