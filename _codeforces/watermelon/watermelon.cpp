#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n % 2 == 0 && n != 2) { cout << "YES"; }
    else { cout << "NO"; }
}
