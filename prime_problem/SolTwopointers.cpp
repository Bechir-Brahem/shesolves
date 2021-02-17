#include <bits/stdc++.h>
#include <cstdio>
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
	//INF = max value of n
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
    /*
     * v is sorted in increasing order so we can use two pointers
     * to find two primes that sum to the new n (n-(k-2 primes))
     */
    auto it1 = v.begin (), it2 = v.end ();
    it2--;
    ll sum;
    while (it1 != it2) {
        sum = *it1 + *it2;
        if (sum < n)
            it1++;
        else if (sum > n)
            it2--;
        else
            break;
    }
    /*
     * this condition is important when n is odd and k=2 this way
     * a solution isn't always guarateed
     */
    if (k == 2 and *it1+*it2 != n) {
        cout << "Impossible\n";
        return;
    }
    // print the last two primes
    cout << s << *it1 << " " << *it2 << endl;
    /*
     * solve() has a complexity of O(n)
     * sieve=O(n)+two_pointers_over_the_number_of_primes=O(n/ln(n))
     */
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    // freopen("random","r",stdin);
    int times = 1;
    while (times--) {
        solve ();
    }
    return 0;
}
