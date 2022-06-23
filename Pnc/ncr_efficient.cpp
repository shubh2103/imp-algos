#include <bits/stdc++.h>
using namespace std;
// **what we do is to have (n)*(n-1)*(n-2)*....(n-r+1)/(1*2*3*....*r-1*r);
long long nCr(int n,int r)
{
    long long p = 1,k=1;
    r = min(r,n-r);
    if(r!=0)
    {
        while(r)
        {
            p*=n;
            k*=r;
            long long m = __gcd(p,k);
            p/=m;
            k/=m;

            n--;
            r--;
        }
    }
    else{
        p = 1;
    }
    return p;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r);
}