#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define PI = arccos(-1)
typedef long long ll;
typedef long double ld;
const int INF=1e9;
const ll LINF=1e18;
const int mod = 1e9 + 7;

int bs(int x, vector<int>v){
    int l=0,r=v.size()-1,m,ans=0;
    while(l<=r){
        m=(l+r)/2;
        if(x>=v[m]) l=m+1;
        else{
            ans=m;
            r=m-1;
        }  
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE 
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int n;
cin>>n;
int x;
cin>>x;
vector<int>v{x};
ll ans=0;
for(int i=1;i<n;++i){
    cin>>x;
    if(x<v[v.size()-1]){
        int b=bs(x,v);
        v.insert(v.begin()+b,x);
        ans+=i-b;
    }
    else v.push_back(x);
}
cout<<ans;

return 0;
}
