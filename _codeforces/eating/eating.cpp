/*
Avery Li
2/24/2025
Problem link: https://codeforces.com/contest/2064/problem/D
*/

#include <iostream>
#include <vector>

using namespace std;

#define li long long

/*

w = weights

x w[i]
0  0   0
0  1   1 <-- this can never happen when eating
1  0   1
1  1   0

when eating, MSB of x has be to at least as great as MSB of w[i]
when MSB(x) = MSB(x), the MSB of x has to be recalculated
 - find the rightmost value
*/

int n, q;
vector<li> weights;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        cin >> n >> q;
        weights.assign(n, 0);
        for(int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        
        li x;

        vector<int> decrease_bit(32, -1);
        for (int i = n - 1; i >= 0; i++) {
            for (int b = 0; b < 32; b++) {
                if ((weights[i] & (0b1 << b)) && decrease_bit[b] == -1) {
                    decrease_bit[b] = i;
                }
            }    
        }

        
        while (q--) {
            cin >> x;

            int cur_bit = 31;
            while (cur_bit >= 0 && (x & (0b1 << cur_bit)) == 0) {
                cur_bit -= 1;
            }

            if (cur_bit < 0) {
                cout << 0;
            } else {
                int total = 0;
                total += decrease_bit[cur_bit] - decrease_bit[cur_bit - 1];
                int start = decrease_bit[cur_bit];
                int end = cur_bit - 1;

                x = x ^ weights[decrease_bit[cur_bit]];

            }


        }
        cout << endl;

    }
    
}
