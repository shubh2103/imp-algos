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
// DSU
// make - helps in making new independent nodes
// find - return the root node of the particular node in its group
// union - combine two groups (as the name itself implies) we combine
// them by connecting the two root nodes
const int N = 1e5 + 10;
int parent[N]; //parent array stores the parent of each node
int size[N];   // stores the size of each tree
void make(int v) {
    // make function : to initialise new node
    parent[v] = v;
    size[v] = 1; // size of a single node is 1
}
int find(int v) {
    if (v == parent[v]) return v; // if it is a single node then it's parent is itself
    return parent[v] = find(parent[v]); // using recursion
    // return parent[v] = find(parent[v]); size compression by making parent of each node equal to root node
}
void Union(int a, int b) {

    // time complexity O(α(n))
    // union function time is almost constant max(O(4))
    /* we always join the smaller tree under the large tree so that the depth do not increase*/
    a = find(a);    // a contains the root node of group containing a
    b = find(b);    // b contains the root node of group containing b
    if (a == b) return; // if both node have same root then return
    if (size[a] < size[b])swap(a, b);
    parent[b] = a;
    size[a] += size[b]; // increase size of a by b
}

void best()
{
    int n,k;
    cin>>n>>k;
    fo(i,1,n+1) make(i);
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int num_connected_components = 0;
    fo(i,1,n+1)
    {
        if(find(i)==i) num_connected_components++;
    }
    cout<<num_connected_components<<endl;
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