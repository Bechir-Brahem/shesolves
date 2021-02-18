#include <iostream>
#include <vector>
#define ll long long

using namespace std;

bool valid(vector<int> &arr, size_t k, int s) {
    for (size_t i = 0; i <= arr.size() - k; i++) {
        ll sum{};
        for (size_t j = i; j < i + k; j++) {
            sum += (ll)arr[j];
        }
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
