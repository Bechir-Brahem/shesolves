
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, result = 0;
    /* while (cin >> n) { */
    /*     result = 0; */
    /*     for (long long i = 5; n / i > 0; i *= 5) { */
    /*         result += (n / i); */
    /*     } */
    /*     cout << result << endl; */
    /* } */
    cin >> n;
    for (long long i = 5; n / i > 0; i *= 5) {
        result += (n / i);
    }
    cout << result << endl;
}
