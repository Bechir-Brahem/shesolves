#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define PI = arccos(-1)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;

int main()
{
    random_device rd;
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> N(1, 100); 
    uniform_int_distribution<int> L(10, 200); 
    uniform_int_distribution<int> I(1, 200);  

    for (int i=1;i<=50;++i) {
      string str;
      if(i<=9)  str="test00"+to_string(i)+".in";
      else str="test0"+to_string(i)+".in";
        ofstream file {str};
        int n=N(mt),l=L(mt);
        file<<n<<' '<<l<<'\n';
        for (int j=0;j<n;++j) {file<<I(mt)<<' ';}
        file <<'\n';
    }

}