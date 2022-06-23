// completer the level i-1 completely before visiting the ith level

 //bfs is implemented using queue data structure as we first insert elments on a particular level and then their children so that the level is maintained 

 #include <bits/stdc++.h>
 typedef long long ll;
 #define vi vector<ll>
 using namespace std;
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
 const int N = 1e5+10;
 vector<int> g[N]; 
 int visited[N];
 int level[N];
 void BFS(int src)
 {
     queue<int> q;
     q.push(src);
     visited[src]=1;
     while (!q.empty())
     {
        int curr = q.front();
        q.pop();
        dbg(curr);
        for(int child:g[curr])
        {
            if(!visited[child]) q.push(child);
            visited[child]=1;
            level[child] = level[curr] +1;
        }
     }     
 }
 void best()
 {
      int n;
      cin>>n;
      fo(i,0,n-1)
      {
          int v1,v2;
          cin>>v1>>v2;
          g[v1].push_back(v2);
          g[v2].push_back(v1);
      }
      BFS(1);

 }
 int main()
 {
     fast;
     ll T;
    //  cin>>T;
     T = 1;
     while (T--)
     {  
         best();
     }
     
 }
