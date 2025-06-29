#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    long long n; cin >> n;
    long long total = n * (n + 1) / 2 * 6 + 1;
    cout << total << '\n';
}