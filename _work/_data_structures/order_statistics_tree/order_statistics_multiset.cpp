#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> OM_INT; // ordered_multiset_int
/*
COMPILE USING homebrew gcc: g++-15 d.cpp && ./a.out < input
CHECK IF long long NEEDED INSTEAD OF INT IN ORDERED SET TYPE

insert element x by pii{x, ctr}, ctr >= 0
search for element x by {x, -1}, {x, 0}, {x, MAXN} as needed

find_by_order(k) returns an iterator to the k-th largest element (counting from zero)
order_of_key(x) returns the number of items in a set that are strictly smaller than our item
insert(x) inserts x
erase(ptr) erases ptr ONLY (to erase element elt, OM.erase(OM.lower_bound(elt)); )


*/

// Can also use below
// using namespace __gnu_pbds;
// typedef tree<
// int,
// null_type,
// less_equal<int>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_multiset_int;

/*

https://codeforces.com/blog/entry/11080

multiset uses less_equal as comparator
IMPORTANT: to erase(x), use s.erase(s.upper_bound(x));
(see blog post)
*/



