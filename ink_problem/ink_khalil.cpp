#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, n, sol = 0;
    cin >> n >> l;
    int I[n];
    for (auto &i : I) cin >> i;
    sort(I, I + n);

    for (auto &i : I) {
        if (l >= i) {
            l -= i;
            sol++;
        } else {
            break;
        }
    }
    cout << sol << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) { solve(); }
    return 0;
}
