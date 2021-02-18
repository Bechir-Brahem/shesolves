#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(int a){
    return a==7;
}
void solve()
{
    int R,C,x,y;
    cin>>R>>C>>x>>y;

    cout<<(R-x)*(C-y)<<endl;
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