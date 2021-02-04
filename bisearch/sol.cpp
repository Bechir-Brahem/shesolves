minimum 
#include <bits/stdc++.h>
#define PI 3.14159265359
#define lp(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = numeric_limits<int>::max();

int mins(int *prefix, int n, int k) {
    if (k > n) {
        return INF;
    }
    int ret = INF;
    for (int i = 1; i <= n - k + 1; i++) {
        ret = min(ret, prefix[i + k - 1] - prefix[i - 1]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        lp(i, n) cin >> arr[i];
        int prefix[n + 1];
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        int step = n / 2;
        int k = 1;
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
