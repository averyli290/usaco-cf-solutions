/*
Link: https://cp-algorithms.com/data_structures/stack_queue_modification.html
*/

#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

using namespace std;

// dequeue using two stacks
stack<pll> s1;      // enqueue to s1
stack<pll> s2;      // dequeue from s2

void enqueue_elt(ll x) {
    int minimum = s1.empty() ? x : min(x, s1.top().second);
    s1.push({x, minimum});
}

pll dequeue_elt() {
    if (s2.empty()) {
        while (!s1.empty()) {
            pll v = s1.top();
            s1.pop();
            int minimum = s2.empty() ? v.first : min(v.first, s2.top().second);
            s2.push({v.first, minimum});
        }
    }
    pii ret = s2.top();
    s2.pop();
    return ret;
}

int min_elt() {
    if (s1.empty() || s2.empty())  {
        return s1.empty() ? s2.top().second : s1.top().second;
    }
    return min(s1.top().second, s2.top().second);
}