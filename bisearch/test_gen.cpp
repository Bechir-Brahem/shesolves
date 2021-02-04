#include <iostream>
#include <random>
using namespace std;
int main()
{
    random_device rd;
    mt19937 mt(rd());
    int n, s;
    uniform_int_distribution<int> distN(0, 100000);  // range is 20 to 22
    uniform_int_distribution<int> distS(0, 1000000); // range is 20 to 22
    uniform_int_distribution<int> distP(0, 100000);  // range is 20 to 22


    for (int i = 1; i < 100; i++) {
        int n = distN(mt), S = distS(mt);
        cout << n << ' ' << S << '\n';
        for (int j = 0; j < n; j++) { cout << distP(mt) << ' '; }
        cout << endl;
    }
}
