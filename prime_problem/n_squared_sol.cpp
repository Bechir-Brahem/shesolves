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
vector<int> v;
ll n, k;
bool is_prime(int p)
{
    int i = 2;
    while (i <= p / 2)

    {
        if (p % i == 0) return false;
        i++;
    }
    return true;
}
void fill(int n=3000)
{
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) v.PB(i);
    }
}
string handle()
{
    // i still have doubts about this
    string s = "";
    if (n % 2 == 0) {
        n -= max(0ll, k - 2) * 2;
        lp(k - 2) s += "2 ";
    } else {
        n -= max(k - 3, 0ll) * 2;
        lp(k - 3) s += "2 ";
        if (k > 2) {
            n -= 3;
            s += "3 ";
        }
    }
    return s;
}
void solve()
{
    // INF = max value of n
    fill();
    cin >> n >> k;
    /*
     * if n<2*k then there can't be any combination of primes that sum
     * to n because 2*k is the smallest sum of any k primes
     */
    if (n < 2 * k) {
        cout << "Impossible\n";
        return;
    }
    /*
     * handle() will return a string s containing the first
     * k-2 primes if k>2 and will be empty if k==2
     * and it will substract the k-2 primes from n
     */
bool found=false;
    string s = handle();
    int i,j;
    for( i=0;i<v.size() ;i++)
    {
        for( j=i;j<v.size();j++)
        {
            if(v[i]+v[j]==n)
            {
                found=true;
                break;
            }
        }
        if(found)break;
    }
    // auto it1 = v.begin(), it2 = v.end();
    // it2--;
    // set<ll> visited;
    // bool found = false;
    // while (it1 != it2) {
        // if (visited.find(n - *it1) != visited.end() or 2 * *it1 == n) {
            // found = true;
            // break;
        // }
        // visited.insert(*it1);
        // it1++;
    // }
    // if (found) {
        // cout << s << *it1 << " " << n - *it1 << endl;
        // // print the last two primes
        // return;
    // }
    if(found){
        cout<<s<<v[i]<<" "<<v[j]<<endl;
        return ;
    }
    cout << "Impossible\n";
    /*
     * solve() has a complexity of O(n)
     * sieve=O(n)+O(nlogn/ln(n))
     */
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
