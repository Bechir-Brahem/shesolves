#include <bits/stdc++.h>

using namespace std;

bool check(int n, int base) {
    while (n > 0) {
        if (n % base == 7)
            return true;
        n /= base;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int ret{};
    for (int i = 1; i <= n; i++) {
        if (!check(i, 10) && !check(i, 8))
            ret++;
    }
    cout << ret << endl;
    return 0;
}
