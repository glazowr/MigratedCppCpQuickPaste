// state of dp are the parameters that changes during dp

//bottom up approach (iterative approach)

int dp[100010];

there are two type of bottom up dp
1) Pull dp: answers are pulled from previous answers that are already calculated
2) Push dp: here we are concerning that our current postion has what contribution to the other indices
            f(i+1) += f(i); f(i+2) += f(i);
State (what info we are storing/carring), 
transisiton (way to find current answers from previous answers f(x) = f(x-1) + f(x-2)), 
base cases

void solve() {
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}

//top down approach (recursive)

int dp[100010];

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    //memoise
    return dp[n] = fib(n-1) + fib(n-2);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fib(n);
}



frog 1
https://atcoder.jp/contests/dp/tasks/dp_a
top down 
https://atcoder.jp/contests/dp/submissions/28425981
bottom up
https://atcoder.jp/contests/dp/submissions/28431002
https://atcoder.jp/contests/dp/submissions/29220505

frog 2
https://atcoder.jp/contests/dp/tasks/dp_b
top down
https://atcoder.jp/contests/dp/submissions/28426139
Bottom up
https://atcoder.jp/contests/dp/submissions/28431413
https://atcoder.jp/contests/dp/submissions/29220622

C- Vacation
https://atcoder.jp/contests/dp/tasks/dp_c
top down
https://atcoder.jp/contests/dp/submissions/29623396
Bottom up
https://atcoder.jp/contests/dp/submissions/29623826

=======================================================================================================================================================================
//coin change 1
https://leetcode.com/problems/coin-change/
//top down approach
https://leetcode.com/submissions/detail/639674893/

case of permutations count 
//Dice combinations (here order matters , so we just use the normal recursion)
https://cses.fi/problemset/task/1633
top down 
https://cses.fi/paste/5d3e0bbc951062d1369a1a/
bottom up
https://cses.fi/paste/e9eb7f073ddebb0d36db7d/

case of combinations count
//coin change 2 (here order doesn't matter, so we just need to go by index and state of dp becomes 2)
https://leetcode.com/problems/coin-change-2/
top down
https://leetcode.com/submissions/detail/639769695/
bottom up
https://leetcode.com/submissions/detail/648206011/

==========================================================================================================================================================
Maximum subarray sum

bottom up

Kadane's algorithm 
    
int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
    sum = max(array[k],sum+array[k]);
    best = max(best,sum);
}
cout << best << "\n";


#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[n];
    b[0] = a[0];
    int ans = -1*1e9;
    for (int i = 1; i < n; i++) {
        b[i] = max(a[i], a[i]+b[i-1]);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, b[i]);
    }
    cout << ans << "\n";
    return 0;
}

top down

#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
int dp[1000010];
 
int f(vector<int> &a, int i) {
    if (i == 0) return dp[0] = a[0];
    if (dp[i] != -1) return dp[i];
    int mx = a[i];
    mx = max(mx, a[i]+f(a, i-1));
    return dp[i] = mx;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    f(a, n-1);
    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}

=========================================================================================================================================================================
//knapsack 1
https://atcoder.jp/contests/dp/tasks/dp_d
top down approach
https://atcoder.jp/contests/dp/submissions/29245880
bottom up approach
https://atcoder.jp/contests/dp/submissions/29643951

//rod cutting unbounded knapsack
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

problems based on subsetsum
https://leetcode.com/problems/partition-equal-subset-sum/
top down approach
https://leetcode.com/submissions/detail/640431214/
bottom up approach
https://leetcode.com/submissions/detail/648681941/

==========================================================================================================================

Longest common subsequence 
https://leetcode.com/problems/longest-common-subsequence/
top down approach
https://leetcode.com/submissions/detail/679612921/
bottom up
https://leetcode.com/submissions/detail/679731353/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a, b;
  cin >> a >> b;
  a = '1' + a;
  b = '1' + b;
  int n = a.size() - 1, m = b.size() - 1;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  int idx = dp[n][m];
  vector<char> lcs(idx + 1);
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (a[i] == b[j]) {
      lcs[idx] = a[i];
      idx--;
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    }
    else {
      j--;
    }
  }
  for (int i = 1; i <= dp[n][m]; i++) {
    cout << lcs[i];
  }
  cout << "\n";
  return 0;
}
====================================================================================================================================================

EDIT DISTANCE

#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  string a, b;
  cin >> a >> b;
  a = '1' + a;
  b = '1' + b;
  int n = a.size() - 1, m = b.size() - 1;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0) {
        dp[i][j] = j;
      }
      else if (j == 0) {
        dp[i][j] = i;
      }
      else if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
      }
    }
  }
  cout << dp[n][m] << "\n";
  return 0;
}

===================================================================================================================================

longest increasing subsequence 

#include <bits/stdc++.h>
using namespace std;
int n, dp[100];
vector<int> a(100);
int lis(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (a[i] > a[j]) ans = max(ans, lis(j) + 1);
    }
    return dp[i] = ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int flg = 0;
  for (int i = 0; i < n; i++) {
    flg = max(flg, lis(i));
  }
  cout << flg;
  return 0;
}
========================================================================================================================================
       
unique paths 1

https://leetcode.com/problems/unique-paths/

vector<vector<int>> dp(n, vector<int>(m, 1));
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
return dp[n - 1][m - 1];

unique paths 2
         
https://atcoder.jp/contests/dp/submissions/31995227

Minimum Path sum 
int n = grid.size();
int m = grid[0].size();
vector<vector<int>> dp(n, vector<int>(m));
for (int i = 0; i < n; i++) {
  for (int j = 0; j < m; j++) {
    if (i == 0 && j == 0) {
      dp[i][j] = grid[i][j];
    }
    else if (i == 0) {
      dp[i][j] = dp[i][j - 1] + grid[i][j];
    }
    else if (j == 0) {
      dp[i][j] = dp[i - 1][j] + grid[i][j];
    }
    else {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }
}
return dp[n - 1][m - 1];




// caching across the queries and printing (target sum subset) . .

#include <bits/stdc++.h>

using namespace std;

int rec(int level, int left) {
	// pruning 
	if (left < 0) {
		return 0;
	}
	// basecase
	if (level == n + 1) {
		if (left == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	// cache check
	if (dp[level][left] != -1) {
		return dp[level][left];
	}
	// compute
	int ans = 0;
	if (rec(level + 1, left) == 1) {
		ans = 1;
	}
	else if (rec(level + 1, left - x[level])) {
		ans = 1;
	}
	// save and return
	return dp[level][left] = ans;
}

void printset(int level, int left) {
	if (level == n + 1) {
		return;
	}
	if (rec(level + 1, left) == 1) {
		printset(level + 1, left);
	}
	else if (rec(level + 1, left - x[level])) {
		cout << x[level] << " ";
		printset(level + 1, left - x[level]); 
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	int q;
	cin >> q;
	while (q--) {
		cin >> t;
		if (rec(1, t)) {
			printset(1, t);
		}
		else {
			cout << "no solution";
		}
		cout << "\n";
	}
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

// Ending form [LIS O(N * N)]

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10010];
int dp[10010];

int rec(int level, int left) {
	// best LIS ending at that level 
	// pruning 
	if (level < 0) {
		return 0;
	}
	// basecase
	// cache check
	if (dp[level] != -1) {
		return dp[level];
	}
	// compute
	int ans = 1;
	for (int prev_taken = 0; prev_taken < level; prev_taken++) {
		if (arr[prev_taken] < arr[level]) {
			ans = max(ans, 1 + rec(prev_taken));
		}
	}
	// save and return
	return dp[level] = ans;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	int best = 0;
	for (int i = 0; i < n; i++) {
		best = max(best, rec(i));
	}
	cout << best << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

// Multisequence DP --> LCS 

// this can be extended to three rec(i, j, k + 1) rec(i + 1, j , k) rec(i, j + 1, k)

#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;
int dp[1010][1010];

int rec(int i, int j) {
  // return lcs of a[i...n - 1] and b[j...m - 1]
  // pruning 

  // basecase
  if (i >= n || j >= m) {
    return 0;
  }
  // cache check 
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  // compute
  int ans = 0;
  ans = max(ans, rec(i + 1, j));
  ans = max(ans, rec(i, j + 1));
  if (a[i] == b[i]) {
    ans = max(ans, 1 + rec(i + 1, j + 1));
  }
  // save and return
  return dp[i][j] = ans;
}

void solve() {
  cin >> n >> m;
  cin >> a >> b;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}

// L - R DP

#include <bits/stdc++.h>

using namespace std;

int n;
int x[10010];
int dp[1001][1001];

int rec(int l, int r) {
  // pruning 

  // basecase
  if (r - l == 1) {
    return 0;
  }
  // cache check 
  if (dp[l][r] != -1) {
    return dp[l[r]];
  }
  // compute
  int ans = 1e9;
  for (int p = l + 1, p < r; p++) {
    ans = min(ans, x[r] - x[l] + rec(l, p) + rec(p, r));
  }
  // save and 
  return dp[l][r] = ans;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  x[0] = 0;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, n) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}


// LIS in nlog(n)

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> a(n), inserted_data(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dp;
  for (int i = 0; i < n; i++) {
    if (dp.empty() || dp.back() < a[i]) {
      dp.push_back(a[i]);
      inserted_data[i] = dp.size();
    }
    else {
      auto it = lower_bound(dp.begin(), dp.end(), a[i]);
      *it = a[i];
      inserted_data[i] = it - dp.size() + 1;
    }
  }
  vector<int> lis;
  for (int i = n - 1; i >= 0; i--) {
    if (inserted_data[i] == cur_len) {
      lis.push_back(a[i]);
      cur_len--;
    }
  }
  reverse(lis.begin(), lis.end());
  cout << dp.size() << "\n";
  return 0;
}


// Subsequence 0100 (can be solved using simple maths)
// solution does not depend on the string 

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100010][5];

string T = "0100";

int rec(int level, int match) {
  // pruning 
  if (match == 4) {
    return 0;
  }
  // base case
  if (level == n) {
    return 1;
  }
  // cache check
  if (dp[level][match] != -1) {
    return dp[level][match];
  }
  // compute 
  int ans = rec(level + 1, match + 1) + rec(level + 1, match);

  // save and return 
  return dp[level][match] = ans;
}

void solve() {
  cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
v
