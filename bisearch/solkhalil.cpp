#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll l,n,S,sol=0;
    cin>>n>>S;
    ll I[n];
    for (auto& i:I)
        cin>>i;
    
    ll sum=0,left=0,right=0,k=0;
    
    while(right<n){
        if(sum<S){
            sum+=I[right];
            k++;
        }else{
            sum+=I[right]-I[left];
            if(sum>=S){
                left++;
            }
            else{
                k++;
                sum+=I[left];
            }
        }
        right++;
        
    }
    if(sum<S)   cout<<"impossible"<<endl;
    else cout<<k<<endl;
}

int main()
{
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve();
	}
	return 0;
}