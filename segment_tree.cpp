#include <bits/stdc++.h>
using namespace std;
int MAXN = 10000;
int n, t[4*MAXN];

/*
 In the main program this function will be called with the parameters of the root vertex: v = 1 , tl = 0 , and tr = n-1.
*/
// here taking v = 1 so we are doing v*2 and v*2 +1 at other platform it might be diff.
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

/*
Finally the update query. The function will also receive information about the current vertex/segment, and additionally also the parameter of the update query (i.e. the position of the element and its new value).
*/

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}


int32_t main()
{
    cin>>n;
    int a[n];
    for(int i = 0 ; i<n ; i++){
        cin>>a[i];
    }   
    build(a , 1 , 0 , n-1);
    cout<<sum(1 , 0 , n-1 , 1 , 2);
    return 0;
}