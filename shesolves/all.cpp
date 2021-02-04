#include <bits/stdc++.h>
#include <string>
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
		cout << max (0ll, k - 2) << " " << 0 << " ";
    } else {
        n -= max (k - 3, 0ll) * 2;
		cout << max (0ll, k - 3) << " ";
        if (k > 2) {
            n -= 3;
            // s += "3 ";
			cout << 1 << " ";
        } else {
			cout << 0 << " ";
        }
    }
    return s;
}
void solve ()
{
    // INF = max value of n
    /*
     * if n<2*k then there can't be any combination of primes that sum
     * to n because 2*k is the smallest sum of any k primes
     */
    if (n < 2 * k) {
        // cout << "impo\n";
        return;
    }
    /*
     * handle() will return a string s containing the first
     * k-2 primes if k>2 and will be empty if k==2
     * and it will substract the k-2 primes from n
     */
	ll aa=n;
	ll bb=k;
    string s = handle ();
    auto it1 = v.begin (), it2 = v.end ();
    it2--;
    set<ll> visited;
    bool found = false;
    while (it1 != it2) {
        if (visited.find (n - *it1) != visited.end () or 2 * *it1 == n) {
            found = true;
            break;
        }
        visited.insert (*it1);
        it1++;
    }
    if (found) {
        // cout << *it1 << " " << n - *it1 << "\n";
        cout << aa << " " << bb << " "<< "yes"<<'\n';
        return;
    }
    // cout << "impo\n";
    // print the last two primes
    /*
     * solve() has a complexity of O(n)
     * sieve=O(n)+two_pointers_over_the_number_of_primes=O(n/ln(n))
     */
}

void solve2 ()
{
    // INF = max value of n
    /*
     * if n<2*k then there can't be any combination of primes that sum
     * to n because 2*k is the smallest sum of any k primes
     */
	cout << n << " " << k << " ";
	ll aa,bb;
	aa=n;bb=k;
    if (n < 2 * k) {
		cout << "impo\n";
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
    if (k == 2 and *it1 + *it2 != n) {

		cout << "impo\n";
        return;
    }
    // print the last two primes
        // cout << aa << " " << bb <<'\n';
	cout << *it1 << " " << *it2 << '\n';
    /*
     * solve() has a complexity of O(n)
     * sieve=O(n)+two_pointers_over_the_number_of_primes=O(n/ln(n))
     */
}


int main ()
{
    freopen ("2pointersVals.txt", "w", stdout);
    int times = 1;
    SieveOfEratosthenes (INF);
    for (int i = 4; i <= 2500; i++) {
        for (int j = 2; j <= 1000; j++) {
            n = i;
            k = j;
            solve2 ();
        }
    }

    fclose (stdout);
    return 0;
}
