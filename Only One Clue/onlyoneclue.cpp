#include <bits/stdc++.h>
using namespace std;
void test() {
    int k, x;
    cin >> k >> x;
    for (int i = x - k + 1; i < x + k; i++)
        cout << i << " ";
}
int main() {
    test();
    return 0;
}
