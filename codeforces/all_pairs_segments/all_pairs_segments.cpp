#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, q; cin >> t;
    long long cur_q;

    for(int i=0; i<t; i++) {
        cin >> n >> q;
        vector<int> arr(n, 0);
        vector<long long> ns(n, 0);
        unordered_map<long long, long long> m;
        for(int j=0; j<n; j++) {
            cin >> arr[j];
        }
        for(long long j=0; j<n-1; j++) {
            long long num_segments = (j + 1) * ((long long) n - (j + 1));
            m[num_segments] += arr[j + 1] - arr[j] - 1;
        }
        for(long long j=0; j<n; j++) {
            long long num_segments = (j + 1) * ((long long) n - j) - 1;
            m[num_segments] += 1;
        }
        for(int j=0; j<q; j++) {
            cin >> cur_q;
            cout << m[cur_q] << ' ';
        }
        cout << '\n';
    }

}
