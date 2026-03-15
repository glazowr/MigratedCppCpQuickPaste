//bfs

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
vector<bool> vis(N, false);
int level[N];

void bfs(int source) {
	queue<int> q;
	q.push(source);
	vis[source] = 1;
	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		for (int child : g[cur_v]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = 1;
				level[child] = level[cur_v] + 1;
			}
		}
	}
}

//https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int inf = 1e9+7;
int vis[8][8], level[8][8];

int getX(string s) {
	return s[0] - 'a';
}

int getY(string s) {
	return s[1] - '1';
}

bool isvalid(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

vector<pair<int,int>> movements = {
	{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, 
	{2, -1}, {2, 1}, {-2, -1}, {-2, 1} 
};

int bfs(string source, string dest) {
	int sourceX = getY(source);
	int sourceY = getY(source);
	int destX = getX(dest);
	int destY = getY(dest);
	queue<pair<int,int>> q;
	q.push({sourceX, sourceY});
	vis[sourceX][sourceY] = 1;
	level[sourceX][sourceY] = 0;

	while (!q.empty()) {
		pair<int,int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();
		for (auto movement : movements) {
			int childX = movement.first + x;
			int childY = movement.second + y;
			if (!isvalid(childX, childY)) continue;
			if (!vis[childX][childY]) {
				q.push({childX, childY});
				vis[childX][childY] = 1;
				level[childX][childY] = level[x][y] + 1;
			}
		}
		if (level[destX][destY] != inf) break;
	}
	return level[destX][destY];
}

void reset() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			level[i][j] = inf;
			vis[i][j] = 0;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/DSC/Desktop/code sublime/inputf.in", "r", stdin);
	#endif
	
	int _;
	cin >> _;
	for (_; _; _--) {
		reset();
		string s1, s2;
		cin >> s1 >> s2;
		cout << bfs(s1, s2) << "\n";
	}
	return 0;
}

// 0-1 bfs

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

int n, m;
vector<pair<int,int>> g[N];
vector<int> level(N, INF);

int bfs(int source) {
	deque<int> q;
	q.push_back(source);
	level[source] = 0;

	while (!q.empty()) {
		int cur_v = q.front();
		q.pop_front();
		for (auto child : g[cur_v]) {
			int child_v = child.first;
			int wt = child.second;
			if (level[cur_v] + wt < level[child_v]) {
				level[child_v] = level[cur_v] + wt;
				if (wt == 1) q.push_back(child_v);
				else q.push_front(child_v);
			}
		}
	}
	return level[n] == INF? -1: level[n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/DSC/Desktop/code sublime/inputf.in", "r", stdin);
    #endif

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int v1, v2;
    	cin >> v1 >> v2;
    	if (v1 == v2) continue;
    	g[v1].push_back({v2, 0});
    	g[v2].push_back({v1, 1});
    }
    cout << bfs(1) << "\n";
    return 0;
}


// multisource bfs https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
const int INF = 1e9+10;

int n, m, val[N][N];
int vis[N][N], level[N][N];

bool isvalid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<pair<int,int>> movements = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0},
	{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

int bfs() {
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mx = max(mx, val[i][j]);
		}
	}
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mx == val[i][j]) {
				q.push({i, j});
				level[i][j] = 0;
				vis[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while (!q.empty()) {
		auto v = q.front();
		int v_x = v.first;
		int v_y = v.second;
		q.pop();
		for (auto movement : movements) {
			int child_x = movement.first + v_x;
			int child_y = movement.second + v_y;
			if (!isvalid(child_x, child_y)) continue;
			if (!vis[child_x][child_y]) continue;
			q.push({child_x, child_y});
			level[child_x][child_y] = level[v_x][v_y] + 1;
			vis[child_x][child_y] = 1;
			ans = max(ans, level[child_x][child_y]);
		}
	}
	return ans;
}

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			level[i][j] = INF;
			vis[i][j] = 0;
		}
	}
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
    	cin >> n >> m;
    	reset();
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < m; j++) {
    			cin >> val[i][j];
    		}
    	}
    	cout << bfs() << "\n";
    }
    return 0;
}


//dijkstra algo O(V + Elog(V))

const int N = 1e5+10;
const int INF = 1e9+7;

vector<pair<int,int>> g[N];
vector<int> vis(N, 0);
vector<int> dis(N, INF);

void dijkstra() {
	set<pair<int,int>> st;
	st.insert({0, source});
	dis[source] = 0;

	while (s.size() > 0) {
		auto node = *st.begin();
		int v = node.second;
		int v_dis = node.first;
		st.erase(st.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto child : g[v]) {
			int child_v = child.first;
			int wt = child.second; 
			if (dis[v] + wt < dis[child_v]) {
				dis[child_v] = dis[v] + wt;
				st.insert({dis[child_v], child_v});
			}
		}
	}

}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		g[x].push_back({y, wt});
		g[y].push_back({x, wt});
	}
}
//floyad 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10, inf = 1e9+7;

int dis[N][N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  #endif

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) dis[i][j] = 0;
      else dis[i][j] = inf;
    }
  }
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    dis[x][y] = w;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dis[i][k] != inf && dis[k][j] != inf) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dis[i][j] == inf) cout << "I";
      else cout << dis[i][j];
      cout << " ";  
    }
    cout << "\n";
  }
  return 0;
}


//dsu


void make (int v) {
    par[v] = v;
    size[v] = 1;
}

int find (int v) {
    if (pa[v] == v) return v;
    return par[v] = find(par[v]);
}

void Union (int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        par[b] = a;
        size[a] += size[b];
    }
}

#include <bits/stdc++.h>
using namespace std;

int parent[N], size[N];

void make(int v) {
  parent[v] = v;
  size[v] = 1;
}

void find(int v) {
  if (parent[v] = v) return v;
  return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    make(i);
  }  
  while (k--) {
    int u, v;
    cin >> u >> v;
    Union(u, v);
  }
  int connected_cnt = 0;
  for (int i = 1; i < n; i++) {
    if (parent[v] == v) connected_cnt++;
  }
  cout << connected_cnt << "\n";
  return 0;
}
