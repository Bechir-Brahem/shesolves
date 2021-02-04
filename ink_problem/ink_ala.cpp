#include <bits/stdc++.h>
#define lp(i, n) for (size_t i = 0; i < (size_t)n; i++)
#define nl '\n'
typedef long long ll;

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    lp(i, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = 0;
    ll sum = 0;
    for (; i < n; i++) {
        sum += arr[i];
        if (sum > l)
            break;
    }
    cout << i << nl;
    return 0;
}
