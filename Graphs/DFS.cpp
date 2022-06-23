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
vector<int> g[N];
bool vis[N];
void dfs(int vertex)
{   //action on vertex after entering the vertex
    cout << vertex << endl;
    vis[vertex] = 1;
    for (int child : g[vertex])
    {
        cout << "parent " << vertex << " child " << child << endl;
        if (vis[child]) continue;
        // take action on child before entering the child node

        dfs(child);

        // take action on child after exiting child node
    }
    // take action on vertex before existing the vertex
}
void best()
{
    int n, m;
    cin >> n >> m;
    fo(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
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