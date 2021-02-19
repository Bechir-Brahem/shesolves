#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll MAXN = (ll)1e6 + 7;
const ll INF = (ll)__builtin_huge_vall(); // return float
const ll md = 1000000007;
#define PB      push_back
#define MP      make_pair
#define all(x)  (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lp(n)   for (int i = 0; i < (n); i++)
int count_oct(int n)
{
    int c=0;
    while(n>0)
    {
        if(n%8==7){
            return false;
        }
        n/=8;
    }
    return true;
}

int count_dec(int n)
{
    int c=0;
    while(n>0)
    {
        if(n%10==7)
        {
            return false;
        }
        n/=10;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(count_dec(i) and count_oct(i))
        {
            c++;
        }
    }
    cout<<c<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    // freopen("f.in", "r", stdin);
    int times = 1;
    // cin>>times;
    while (times--) { solve(); }
    return 0;
}
