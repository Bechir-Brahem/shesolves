#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve()
{
    int A,B,C,K,ans=0;
    cin>>A>>B>>C>>K;
    while(B<=A){
        B*=2;
        K--;
    }
    while(C<=B){
        C*=2;
        K--;
    }

    cout<<(K>=0?"You tricked us!":"Oh no!")<<endl;
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
