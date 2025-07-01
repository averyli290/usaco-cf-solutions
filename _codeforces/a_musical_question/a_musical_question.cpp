
#include<iostream>

using namespace std;
int c, n, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;

    bool possible[c + 1][c + 1];
    for(int i = 0; i < c + 1; i++) {
        for(int j = 0; j < c + 1; j++) {
            possible[i][j] = false;
        }
    }

    possible[0][0] = true;

    for (int i=0; i < n; i++) {
        cin >> t;
        for(int j=c; j >= 0; j--) {
            for(int k=c; k >= 0; k--) {
                if (j - t >= 0 && possible[j - t][k]) {
                    possible[j][k] = true;
                }
                if (k - t >= 0 && possible[j][k - t]) {
                    possible[j][k] = true;
                }
            }
        }
    }

    int min_diff = INT32_MAX;
    int max_value = 0;
    int a = 0;
    int b = 0;
    for (int i=0; i < c+1; i++) {
        for(int j=i; j < c + 1; j++) {
            if (possible[i][j] and i + j >= max_value) {
                if (i + j > max_value) {
                    max_value = i + j;
                    a = j;
                    b = i;
                    min_diff = a - b;
                } else if (j - i < min_diff) {
                    a = j;
                    b = i;
                    min_diff = a - b;
                }
            }
        }
    }

    cout << a << ' ' << b << '\n';


}