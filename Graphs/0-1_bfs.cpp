// used the fact that at a time vertexes of only two levels are present (if exist)
// 0-1 bfs used this fact only to find the shortest path where weight of vertexes is either 0 or 1

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

const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
vector<int> level(N, 1e9);
int n, m;
int bfs()
{
	deque<int> q;
	q.push_back(1);
	level[1] = 0;
	while (!q.empty())
	{
		int cur_v = q.front();
		q.pop_front();
		for (auto &child : g[cur_v])
		{
			int child_v = child.first;
			int w = child.second;
			if (level[cur_v] + w < level[child_v])
			{
				level[child_v] = level[cur_v] + w;
				if (w == 1) q.push_back(child_v);
				else q.push_front(child_v);
			}
		}
	}
	return level[n] == 1e9 ? -1 : level[n];
}
void best()
{
	cin >> n >> m;
	fo(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		if (x == y) continue;
		g[x].push_back({y, 0});
		g[y].push_back({x, 1});
	}
	cout << bfs() << endl;
}
int main()
{
	fast;
	ll T = 1;
	// cin>>T;
	while (T--)
	{
		best();
	}
}