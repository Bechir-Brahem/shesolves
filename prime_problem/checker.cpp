#include <algorithm>
#include <bits/stdc++.h>
const long long INF = 1e4 + 7;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll md = 1000000007;
#define PB push_back
#define MP make_pair
#define lp(n) for (int i = 0; i < (n); i++)
using namespace std;
ll n, k;
vector<bool> prime (INF, true);
// prime must be a vector if n=1e7
vector<ll> v;
// v containes the prime numbers in increasing order

void SieveOfEratosthenes (ll n)

{
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    for (ll p = 2; p <= n; p++)
        if (prime[p]) v.push_back (p);
}
void solve ()
{
    int n;
    cin >> n;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    // freopen ("2pointersVals.txt", "r", stdin);
    int times = 1;
    // cin>>times;
    SieveOfEratosthenes (INF);
    cin >> n >> k;
    ll n2, n3, p1, p2;
    ll sum;
    cout << endl;
    ll count = 0;
    lp (103)
    {
        string line;
        getline (cin, line);
        if 
        // cin >> n2 >> n3 >> p1 >> p2;

        if (n2 + n3 + 2 != k) {
            cout << "MORE K " << n << " " << k << " " << n2 << " " << n3 << " " << p1 << " " << p2 << '\n';
        }
        if (!binary_search (v.begin (), v.end (), p1)) {
            cout << "NOT PRIME " << n << " " << k << " " << p1 << '\n';
        }
        if (!binary_search (v.begin (), v.end (), p2)) {
            cout << "NOT PRIME " << n << " " << k << " " << p2 << '\n';
        }
        if (p1 + p2 + n2 * 2 + n3 * 3 != n) {
            cout << "NOT EQUAL " << n << " " << k << " " << n2 << " " << n3 << " " << p1 << " " << p2 << '\n';
        }
    }

    return 0;
}
