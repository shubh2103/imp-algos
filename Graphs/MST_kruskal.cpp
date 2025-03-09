#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
using namespace std;
#define pb push_back
#define ff first
#define int ll
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
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// MINIMUM SPANNING TREE
const int N = 1e5 + 10;
// Kruskal's Algorithm
// obj : to find a tree(graph without loop) having all nodes such the sum of all its weight is minimum.
int parent[N];
int sz[N];
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}
void best()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges.push_back({w, {v1, v2}});
    }
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    sort(all(edges));

    int tot_cost = 0;
    for (auto &edge : edges) {
        int wt = edge.first;
        int v1 = edge.second.first;
        int v2 = edge.second.second;
        if (find(v1) == find(v2)) continue;
        Union(v1, v2);
        cout << v1 << " " << v2 << endl;
        tot_cost += wt;
    }
    dbg(tot_cost);
}
signed main()
{
    fast;
    ll T = 1;
    // cin>>T;
    while (T--)
    {
        best();
    }
}