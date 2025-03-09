#include <bits/stdc++.h>
using namespace std;

int n , m;
const int N = 1e5+9;
const int INF = 1e9;
int cost = 0;
vector<vector<int>> g[N];
vector<int>dist(N) , parent(N) , vis(N , 0);

void primsMST(int source){
    for(int i = 0 ; i<n ; i++){
        dist[i]=INF;
    }
    set<vector<int>>s;
    dist[source] = 0;
    s.insert({0 , source});
    // {wt , vertex}
    while(s.size()>0){
        auto x = *s.begin();
        s.erase(x);
        vis[x[1]]=1;
        int u = x[1];
        int v = parent[x[1]];
        int wt = x[0];
        cout<<u<<" "<<v<<" "<<wt<<"\n";
        cost+=wt;
        for(auto it :g[x[1]]){
            if(vis[it[0]])continue;
            if(dist[it[0]] > it[1]){
                if(s.count({dist[it[0]] , it[0]})>0)
                s.erase({dist[it[0]] , it[0]});
                // else cout<<"not found\n";
                dist[it[0]]=it[1];
                s.insert({dist[it[0]] , it[0]});
                parent[it[0]]=x[1];
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0 ; i<m ; i++){
        int u , v , w;
        cin>>u>>v>>w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    primsMST(0);
    cout<<cost<<"\n";
}