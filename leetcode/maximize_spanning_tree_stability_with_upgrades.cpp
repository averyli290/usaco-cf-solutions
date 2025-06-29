/*
Problem link:  https://leetcode.com/contest/weekly-contest-456/problems/maximize-spanning-tree-stability-with-upgrades/description/
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:

    int parent[(int) 1E5+1];
    int rank[(int) 1E5+1];
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    int maxStability(int n, vector<vector<int>>& edges_input, int k) {

        struct Edge {
            int u, v, weight, must;
            bool operator<(Edge const& other) {
                return weight > other.weight;
            }
        };

        vector<Edge> edges(edges_input.size());
        for (auto &e : edges_input) {
            edges.emplace_back(e[0], e[1], e[2], e[3]);
        }
        
        vector<Edge> result;
        for (int i = 0; i < n; i++) {
            make_set(i);
        }

        multiset<int> req_weights;
        multiset<int> weights;
        for (Edge e : edges) {
            if (e.must) {
                result.push_back(e);
                req_weights.insert(e.weight);
                int old_id = find_set(e.u), new_id = find_set(e.v);
                if (old_id == new_id) { return -1; } // cycle
                union_sets(e.u, e.v);
            }
        }

        sort(edges.begin(), edges.end());
        
        for (Edge e : edges) {
            if (!e.must && find_set(e.u) != find_set(e.v)) {
                result.push_back(e);
                weights.insert(-e.weight);
        
                int old_id = find_set(e.u), new_id = find_set(e.v);
                if (old_id == new_id) { return -1; } // cycle
                union_sets(e.u, e.v);
            }
        }

        for (int i = 0; i < n; i++) {
            if (find_set(i) != find_set(0)) return -1;
        }

        multiset<int> new_weights;
        if (weights.size() > 0) {
            for (int i = 0; i < k; i++) {
                if (weights.size() == 0) {
                    break;
                }
                int min_val = *weights.rbegin();
                    auto it = weights.find(min_val);
                if (it != weights.end()) {
                    weights.erase(it);
                }
                new_weights.insert(min_val * 2);
            }
        }
        for (auto w : weights) {
            new_weights.insert(w);
        }

        int ans = new_weights.size() > 0 ?  -(*new_weights.rbegin()) : INT_MAX;
        ans = min(ans, req_weights.size() > 0 ? *req_weights.begin() : INT_MAX);
        
        return ans
    }
};