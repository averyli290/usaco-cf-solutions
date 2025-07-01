/*
Problem link: https://codeforces.com/contest/2112/problem/E
*/

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;

/*
add in order of binary tree for greatest growth?

9 colorings for
g-o
|
o

g-o+o
|
o
know root is green, so if adding new vertex to leaf, if parent is yellow, new vertex must be yellow

each simple path from a given node to root must be either only blue and green or only yellow and green
if the color of each node connected directly to root is yellow/blue, it determines which two colors the children can be

if the sizes of each subtree of root is s_i for S subtrees, the number of colorings for a tree obeying these rules is
prod_{i=1}^n (2^{s_i})

when adding leaf that is NOT attached to root, can add 2 colors, either green or the color above it, unless every
node on path to root is green, then can choose between any of 3 colors. if the previous tree was n nodes, then that 
path can be anywhere from 1 to n nodes long. for each of those lengths i\in [1, n], there are n - i other nodes, and those
can be attached in ANY WAY that is valid for 

DP:
there are 2 ways of adding a leaf to a node where the path contains a yellow/blue node, either color it green or the other
color used on the ancestral path
dp[n + 1] = 2 * dp[n]

If the entire ancestral path is green, it can be considered one big green node as the root. this is true for all ancestral paths
of length 1 to n where size of tree being built on is n. then, this is the same as adding a node to tree of size 1, 2, 3, ..., n
because the way in which the other nodes must be attached after collapsing the ancestral path into one big green root node is must
be valid.
this is 
dp[n + 1] = 3 * sum_{i=0}^{n-1} dp[i],
dp[0] = 1 because there is 1 way to color 0 node tree


let
dp_g[n][k] = # of ways to color n node tree with a green root to leaf path of length k
dp_g[n][k+1] = dp_g[n][k]           // add green to bottom of green path
dp_g[n+1][k] = dp_g[n][k]           // add vertex to bottom of not green path

let dp_ng[n] = # of ways to color n node tree with NO green paths to leaves

let dp[n][k] = # of ways to color n node tree with k nodes contained in green paths to leaves
then:
dp[n + 1][k + 1] = dp[n][k]     // if adding leaf, and want to extend the number of nodes on green path, only one way to color that node, it is green
dp[n + 1][k] = 3 * dp_ng[n - (k - 1)]       // group all k green ancestral nodes into one large green root node
                                            // so there are n - (k - 1) nodes left, they must lie on non-green paths
                                            // otherwise they would have been included in k nodes from earlier

dp_ng[n + 1] = dp_ng[n] * 2 - (sum_{i=1}^n dp[n][i])        // subtract off when attaching green to green path to leaf of sizes 1 to n


use heap to keep track of what to update next in DP (smallest value first)
pii{num_colorings, num_vertices}

----
let dp[n][k] = # of ways to color n node tree with k nodes contained in green paths to leaves
dp[n + 1][k + 1] = dp[n][k]     // adding leaf and want to extend the number of nodes on green paths, only one way to color that node, it is green,
                                    // but can attach leaf to any node

                                    // can attach to any of n - (k - 1) nodes
dp[n + 1][k] = dp[n-(k-1)][0]*2*(n-(k-1)) // adding leaf and dont want to extend number of nodes on green paths, must add either
dp[n + 1][k] = dp[n-(k-1)][1]*2*(n-(k-1)) // green or yellow/blue to a non green path OR add yellow/blue to a green path.
                                // for non green paths, there are 2 possibilities (green or yellow/blue).
                                // we can collapse the k green path nodes to one large green root node and add any color to it
                                // if we add green (we don't want to in this case), we extend it to k + 1,
                                // if we add yellow/blue, we are still good, so there are two possiblities
                                // there also, but on dp[n - (k - 1)][0],
                                // Either way, after we collapse the green path nodes to a single large green root node,
                                // if we attach the new leaf node to a green path node in original, it will attach to new root node,
                                // and there are only 2 possibilities (yellow/blue) to increase without adding more green path nodes
                                // If we attach new leaf node to a a non green path node in original, there are 2 possibilties,
                                // green and yellow/blue. Then, we simplify dp[n+1][k] by collapsing green path nodes

Note: dont count root in green root to leaf paths

sum dp[n][k] over all k\in [0, n] to get number of colorings for tree of size n

do this process but store vectors of # of colorings in dp?
for each coloring, perform collapse and add process
dp[n]

dp[1][0] = 2 // root has to be green, doens't exist

Note: now including root in green root to leaf paths
dp[1][1] = 1
dp[2][1] = 2
dp[2][2] = 1
dp[3][1] = 4
dp[3][2] = 2 (from dp[2][1]), 2 (from dp[2][2])
dp[3][3] = 1



dp[1] = 1
dp[3] = 2

for i in range(3, n + 1, 2):
    we can FORCE an increase of 2 colorings by adding one node
    to the end of 

*/

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}
