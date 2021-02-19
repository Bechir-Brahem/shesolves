#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    ll K, S;
    cin >> K >> S;
    cout << (K * 5 >= S ? "Rich!" : "Not yet") << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
