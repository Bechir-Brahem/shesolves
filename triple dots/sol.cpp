#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(int a){
    return a==7;
}
void solve()
{
    int K;
    string S;
    cin>>K>>S;
    for(int i=0;i<min((int)S.size(),K);i++){
        cout<<S[i];
    }
    if(S.size()>K)  
        cout<<"...";
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