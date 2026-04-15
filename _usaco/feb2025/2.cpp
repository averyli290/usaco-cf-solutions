#include <bits/stdc++.h>

using namespace std;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define debug(x) cout << #x << " is " << x << endl;
#define debug_array(arr , n)  for(int i=1 ; i<=n ; i++) cout<<#arr<<"["<<i<<"] is "<< arr[i]<<endl;
#define debug_vector(arr , n) for(int i=0 ; i<n ; i++) cout<<#arr<<"["<<i<<"] is "<<arr[i]<<endl;
const long long INF = 1e18;


void sta() {
    int N;
    cin >> N;
    
    vi num_children(N+1,0);
    vi parent(N+1, 0);
    vi length(N+1, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
        num_children[parent[i]] += 1;
        length[i] = length[parent[i]] + 1;
    }

    int M = 0;
    for(int i = 0; i <= N; i++) if (num_children[i] == 0) M++;
    
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        
        if (num == 0) {
            cout << 0 << endl;
        } else {
            // has to not be prefix, so starts with num_children[num] == 0
            assert(num_children[num] == 0);
            while (num_children[parent[num]] == 1) {
                num = parent[num];
                num_children[num]--;
                assert(num_children[num] == 0);
            }
            num_children[parent[num]]--;    // remove current child from parent
            cout << length[num] << endl; // have to read up to this point because more than 1 child from parent
        }
    }
}

int main() {
    sta();
    return 0;
}
