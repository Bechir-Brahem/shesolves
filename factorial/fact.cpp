
#include <bits/stdc++.h>
using namespace std;



void solve() {
	int n,result = 0;
	cin>>n;
    for(long long i=5; n/i>0; i*=5){
        result += (n/i);
    }
    cout<<result<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		}
	}
