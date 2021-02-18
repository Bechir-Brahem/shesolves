#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve()
{
    int A,B;
    cin>>A>>B;

    cout<<max(A+B,max(A-B,A*B))<<endl;
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
