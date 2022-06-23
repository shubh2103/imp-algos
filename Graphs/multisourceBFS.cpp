// you apply BFS simuntaneouly on many sources 
// not much asked in interview purposes

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

const int N = 1e3 + 10;
const int inf = 1e9 + 10;
int a[N][N];
int visited[N][N];
int level[N][N];
int n, m, mx;
vector<pair<int, int>> movements = {
	{1, 0}, { -1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}
};
bool is_valid(int i, int j)
{
	return (i >= 0 and j >= 0 and i < n and j < m);
}
int dfs()
{
	queue<pair<int, int>> q;
	fo(i, 0, n)
	{
		fo(j, 0, m)
		{
			if (a[i][j] == mx)
			{
				q.push({i, j});
				visited[i][j] = 1;
				level[i][j] = 0;
			}
		}
	}
	int ans = 0;
	while (!q.empty())
	{
		auto v = q.front();
		q.pop();
		int x = v.first;
		int y = v.second;
		for (auto movement : movements)
		{
			int x_ = x + movement.first;
			int y_ = y + movement.second;
			if (!is_valid(x_, y_)) continue;
			if (visited[x_][y_]) continue;
			q.push({x_, y_});
			visited[x_][y_] = 1;
			level[x_][y_] = level[x][y] + 1;
			ans = max(ans, level[x_][y_]);
		}
	}
	return ans;

}
void reset()
{
	fo(i, 0, n)
	{
		fo(j, 0, m)
		{
			visited[i][j] = 0;
			level[i][j] = inf;
		}
	}
}
void best()
{
	reset();
	cin >> n >> m;
	mx = 0;
	fo(i, 0, n)
	{
		fo(j, 0, m)
		{
			cin >> a[i][j];
			mx = max(mx, a[i][j]);
		}
	}
	cout << dfs() << endl;
}
int main()
{
	fast;
	ll T = 1;
	cin >> T;
	while (T--)
	{
		best();
	}
}