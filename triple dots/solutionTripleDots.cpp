#include <bits/stdc++.h>
using namespace std;

void tripleDots()
{
    int K;
    string S;
    cin>>K>>S;
    if(S.size()>K)
        cout<<S.substr(0,K) << "...";
    else cout<<S;
    cout<<endl;
}
    
int main()
{
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++)
	{
		tripleDots();
	}
	return 0;
}
