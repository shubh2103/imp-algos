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
const int N = 1e9 + 10;
int visited[8][8];
int level[8][8];
void reset()
{
    for (int i = 0; i < 8; i++)
    {   for (int j = 0; j < 8; j++)
        {
            visited[i][j] = 0;
            level[i][j] = N;
        }
    }
}
bool valid(int x, int y)
{
    return (x >= 0 and y >= 0 and x < 8 and y < 8);
}
vector<pair<int, int>> movements = {
    {2, 1}, {2, -1},
    { -2, 1}, { -2, -1},
    {1, 2}, { -1, 2},
    {1, -2}, { -1, -2}
};
int bfs(string src, string dest)
{
    int x1 = src[0] - 'a';
    int y1 = src[1] - '1';
    int x2 = dest[0] - 'a';
    int y2 = dest[1] - '1';

    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = 1;
    level[x1][y1] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        int x = v.first;
        int y = v.second;
        q.pop();
        for (auto movement : movements)
        {
            int childX = movement.first + x;
            int childY = movement.second + y;
            if (!valid(childX, childY)) continue;

            if (!visited[childX][childY])
            {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                visited[childX][childY] = 1;
            }
        }
        if (level[x2][y2] != N) break;
    }
    return level[x2][y2];
}
void best()
{
    reset();
    string start, end;
    cin >> start >> end;
    cout << bfs(start, end) << endl;
}
int main()
{
    fast;
    ll T;
    cin >> T;
    while (T--)
    {
        best();
    }
}