#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int x, y;
    cin >> x >> y;
    cout << r * c - (x * c + y * r - x * y) << endl;
    return 0;
}
