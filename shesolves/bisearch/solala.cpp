/*
 * There exists n bags of gold each of which contains bi golden coins (1 <= i <=
 * n) Samir has to collect at least S golden coins but he does not have much
 * time. so he decided to pick k consecutive bags starting from a random index j
 * (1 <= j <= n - k +1). Help Samir find the minimum integer k so that whatever
 * index j he chooses it is guaranteed that the sum of coins he will collect (bj
 * + ... + bj+k-1) will be greater than or equal to S. if Samir can never
 * collect more than the sum S print "impossible"
 */
#include <bits/stdc++.h>
#define PI 3.14159265359
#define lp(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = numeric_limits<ll>::max();

ll mins(ll *prefix, ll n, ll k) {
    if (k > n) {
        return INF;
    }
    ll ret = INF;
    for (ll i = 1; i <= n - k + 1; i++) {
        ret = min(ret, prefix[i + k - 1] - prefix[i - 1]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while (t--) {
        ll n, s;
        cin >> n >> s;
        vector<ll> arr(n);
        lp(i, n) cin >> arr[i];
        ll prefix[n + 1];
        prefix[0] = 0;
        for (ll i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        ll step = n / 2;
        ll k = 0;
        while (step > 0) {
            if (mins(prefix, n, k + step) < s) {
                k += step;
            } else
                step /= 2;
        }
        if (k == n) {
            cout << "impossible\n";
        } else
            cout << k + 1 << endl;
    }
    return 0;
}

