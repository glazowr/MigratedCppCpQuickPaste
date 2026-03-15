#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

indexed_set s;
s.insert(2);  
s.insert(3);
s.insert(7);
s.insert(9);
//find by index
auto x = s.find_by_order(3);
cout << *x << "\n";
//find index of something
cout << s.order_of_key(9) << "\n";
//If the element does not appear in the set, we get the position that the element would have in the set:
cout << s.order_of_key(5);
