#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define vi vector<ll>
#define vii vector<vi>

// Reminders
// 1. Read the problem statement carefully
// 2. Find the simplest model that works
// 3. Think through all implementation details first
// 4. Read over code before once before submitting
// 5. Hard means learning
// 6. Have fun ^_^

const ll maxN = 1e6 + 2;
vector<set<ll>> A(maxN);
vector<set<ll>> B(maxN);

string trim(string s) {
  string a;
  for (auto ch : s) {
    if (!isspace(ch)) a += ch;
  }
  return a;
}

void tree(const string& s, int parent, int l, int r, vector<set<ll>>& adj) {
  bool numeric = true;
  for (int i = l; i < r; i++) {
    auto ch = s[i];
    if (ch == '(' || ch == ')') numeric = false;
  }
  if (numeric) {
    int id = stoi(s.substr(l, r - l));
    adj[id].insert(-1);
    if (parent != -1) {
      adj[parent].insert(id);
    }
    return;
  }
  int lastOpen = -1;
  int balance = 0;
  int root = -1;
  for (int i = l; i < r; i++) {
    if (s[i] == '(') {
      root = stoi(s.substr(l, i - l));
      break;
    }
  }
  if (root == -1) {
    root = stoi(s.substr(l, r - l));
    adj[root].insert(-1);
    if (parent != -1) {
      adj[parent].insert(root);
    }
    return;
  }
  adj[root].insert(-1);
  for (int i = l; i < r; i++) {
    char ch = s[i];
    if (ch == '(') {
      if (lastOpen == -1) {
        lastOpen = i;
      }
      balance++;
    } else if (ch == ')') {
      balance--;
      if (balance == 0) {
        tree(s, root, lastOpen + 1, i, adj);
        lastOpen = -1;
      }
    }
  }
}

void solve() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  a = trim(a);
  b = trim(b);
  ll sa = size(a), sb = size(b);
  tree(a, -1, 0, sa, A);
  tree(b, -1, 0, sb, B);
  // cout << "A\n";
  // for (int i = 1; i <= 20; i++) {
  //   cout << i << ": \n";
  //   for (auto e : A[i]) {
  //     cout << e << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "B\n";
  // for (int i = 1; i <= 20; i++) {
  //   cout << i << ": \n";
  //   for (auto e : B[i]) {
  //     cout << e << " ";
  //   }
  //   cout << endl;
  // }
  cout << ((A == B) ? "Yes\n" : "No\n");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}