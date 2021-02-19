// Problem 2 : The Ink Problem
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define PI = arccos(-1)
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
/* freopen("input.txt","r",stdin); */
/* freopen("output.txt","w",stdout); */
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l, i = 0, ans = 0, sum = 0;
    cin >> n >> l;
    int arr[n];
    for (; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    for (i = 0; i < n && sum <= l; ++i) {
        sum += arr[i];
        ans++;
    }
    if (sum > l) {
        sum -= arr[i - 1];
        ans--;
    }
    cout << ans;

    return 0;
}
