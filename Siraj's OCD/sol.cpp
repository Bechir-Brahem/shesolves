#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(int a){
    return a==7;
}
void solve()
{
    int N,ans=0;
    cin>>N;
    int a[N],sorted_a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
        sorted_a[i]=a[i];
    }
    sort(sorted_a,sorted_a+N);
    
    for(int i=0;i<N;i++){
        if(sorted_a[i]!=a[i])   ans++;
    }  
    cout<<ans<<endl;
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