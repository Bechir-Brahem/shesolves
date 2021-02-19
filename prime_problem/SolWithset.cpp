#include <algorithm>
#include <bits/stdc++.h>
const long long INF = 1e5 + 7;
typedef long long ll;
#define lp(n) for (int i = 0; i < (n); i++)
using namespace std;
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
ll n, k;

string handle ()
{
    // i still have doubts about this
    string s = "";
    if (n % 2 == 0) {
        n -= max (0ll, k - 2) * 2;
        lp (k - 2) s += "2 ";
    } else {
        n -= max (k - 3, 0ll) * 2;
        lp (k - 3) s += "2 ";
        if (k > 2) {
            n -= 3;
            s += "3 ";
        }
    }
    return s;
}
void solve ()
{
    // INF = max value of n
    SieveOfEratosthenes (INF);
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
    string s = handle ();
    auto it1 = v.begin (), it2 = v.end ();
    it2--;
    set<ll> visited;
    bool found = false;
    while (it1 != it2) {
        if (visited.find (n - *it1) != visited.end () or 2**it1==n) {
            found = true;
			break;
        }
        visited.insert (*it1);
        it1++;
    }
    if (found ) {
        cout << s << *it1 << " " << n - *it1 << endl;
    // print the last two primes
        return;
    }
    cout << "Impossible\n";
    /*
     * solve() has a complexity of O(n)
     * sieve=O(n)+O(nlogn/ln(n))
     */
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    int times = 1;
    while (times--) {
        solve ();
    }

    return 0;
}
