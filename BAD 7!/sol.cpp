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
    ans=N;
    for(int i=1;i<=N;i++){
        if(check(i%10)||check(i/10)||check(i%8)||check((i/8)%8))
            ans--;
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