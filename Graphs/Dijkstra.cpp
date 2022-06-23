// Important algorithm in groph
// we try to minimise the distance whenever we get the chance

#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 10000000000000000
#define input freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define endl "\n"
#define INT_M 1000000007
#define SET(n) cout << fixed << setprecision(n)
#define fo(i, j, n) for (ll i = j; i < n; ++i)
#define dbg(x) cout << #x << ": " << x << endl;

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

const int inf = 1e9 + 10;
int dfs(int src, vector<vector<pair<int, int>>>&g, vector<int>&visited, vector<int>&level, int n)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, src});
	level[src] = 0;
	int ans = 0;
	while (!q.empty())
	{
		int v = q.top().second;
		q.pop();
		if(visited[v])continue;
		for (auto child : g[v])
		{
			int child_v = child.first;
			int w = child.second;
			if (level[v] + w < level[child_v])
			{
				level[child_v] = level[v] + w;
				q.push({level[child_v], child_v});
			}
		}
		visited[v] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, level[i]);
	}
	return (ans == inf) ? -1 : ans;
}
int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
	vector<vector<pair<int, int>>> g(n + 10);
	vector<int> visited(n + 10, 0);
	vector<int> level(n + 10, inf);
	int m = times.size();
	for (int i = 0; i < m; i++)
	{
		g[times[i][0]].push_back({times[i][1], times[i][2]});
	}
	return dfs(k, g, visited, level, n);
}
void best()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<vector<int>> times(n - 1, vector<int>(3));
	for (int i = 0; i < n - 1; i++)
	{
		cin >> times[i][0] >> times[i][1] >> times[i][2];
	}
	cout << networkDelayTime(times, n, k) << endl;
}
int main()
{
	fast;
	ll T = 1;
	// cin >> T;
	while (T--)
	{
		best();
	}
}