#include <iostream>
#include <vector>
#define ll long long

using namespace std;

bool valid(vector<int> &arr, size_t k, int s) {
    ll sum{};
    size_t i;
    for (i = 0; i < k; i++) {
        sum += (ll)arr[i];
    }
    if (sum < s)
        return false;
    for (i = k; i < arr.size(); i++) {
        sum += (ll)arr[i];
        sum -= (ll)arr[i - k];
        if (sum < s)
            return false;
    }
    return true;
}

int main() {
    size_t n;
    int s;
    cin >> n >> s;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    size_t k{};
    for (k = 1; k <= n; k++) {
        if (valid(arr, k, s))
            break;
    }
    if (k <= n)
        cout << k << endl;
    else
        cout << "impossible" << endl;
    return 0;
}
