#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define ff first
#define int ll
#define vi vector<int>
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
// All pair shortest Path : find shortest part betweeen each pair in the graph
// unlike djsktra which gives shortest distance form a src to each node.
const int N = 510;
int dist[N][N]; // distance array in which dis[i][j] gives shortest distance b/w pair i & j
void best()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    // MAIN CONCEPT
    // HANDLES WEIGHT OF NEGATIVE VERTEX (UNLIKE DJKSTRA)
    // CANNOT HANDLE NEGATIVE WEIGHT CYCLE
    // JUST LIKE BELL FORD CYLCE
    // TIME COMPLEXITY O(N^3)
    // WHAT WE DO IS INTRODUCE A PATH WHICH ENABLES KTH NODE . SO IF THE DISTANCE 
    // WOULD BE THE MINIMUM OF THE CURRENT DISTANCE AND THE DISTANCE AFTER INTRODUCING KTH NODE
    // THIS CAN BE DONES USING DYNAMIC PROGRAMMING
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << "I ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
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