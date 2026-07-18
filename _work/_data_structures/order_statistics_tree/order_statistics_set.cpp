#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,
            rb_tree_tag, tree_order_statistics_node_update> OS_INT; // ordered_set_int

/*
COMPILE USING homebrew gcc: g++-15 d.cpp && ./a.out < input
CHECK IF long long NEEDED INSTEAD OF INT IN ORDERED SET TYPE

https://codeforces.com/blog/entry/11080
find_by_order(k) returns an iterator to the k-th largest element (counting from zero)
order_of_key(x) returns the number of items in a set that are strictly smaller than our item
insert(x) inserts x
erase(ptr) erases ptr (use OS.erase(OS.lower_bound(elt)); )
*/

