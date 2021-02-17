#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll n) {
    if (n == 0)
        return 0;
    return n / 5 + solve(n / 5);
}

int main() {
    /* ll x; */
    /* while (cin >> x) { */
    /*     cout << solve(x) << endl; */
    /* } */
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
