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
bool dfs(int vertex, int parent, vector<int> adj[], vector<bool> visited)
{
    bool cycleExist = 0;
    visited[vertex] = 1;
    for (int child : adj[vertex])
    {
        if (visited[child] and child != parent) return true;
        if (visited[child]) continue;
        cycleExist |= dfs(child, vertex, adj, visited);
    }
    return cycleExist;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);
    fo(i, 0, V)
    {
        if (visited[i]) continue;
        if (dfs(i, -1, adj, visited))
        {
            return true;
        }
    }
    return false;
}
void best()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    fo(i, 0, m)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v2].pb(v1);
        adj[v1].pb(v2);
    }
    cout << isCycle(n, adj) << endl;
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