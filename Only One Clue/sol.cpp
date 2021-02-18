#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(int a){
    return a==7;
}
void solve()
{
    int K,X;
    cin>>K>>X;
    for(int i=X-K+1;i<X+K;i++){
        cout<<i<<" ";
    }
    cout<<endl;
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