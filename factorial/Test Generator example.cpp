#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randomInt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

string randomString(int n, char l, char r) {
    int len = r - l + 1;
    string res;
    for (int i = 1; i <= n; ++i)
        res += char(l + randomInt(0, len - 1));
    return res;
}

int digitsNbr(int x) {
    if (x == 0) {
        return 1;
    }
    int ret{};
    while (x != 0) {
        ret++;
        x /= 10;
    }
    return ret;
}

const char nl = '\n';

int main() {
    const int tests = 66;
    const int width = digitsNbr(tests);
    for (int i = 51; i <= tests; ++i) {
        stringstream ss;
        const int testWidth = digitsNbr(i);
        string testNumber(width - testWidth, '0');
        char *testNumberStr = new char[testWidth + 1];
        sprintf(testNumberStr, "%d", i);
        testNumber += testNumberStr;
        ss << "tests/test" << testNumber << ".in";
        delete[] testNumberStr;

        char fileName[20];
        ss >> fileName;
        freopen(fileName, "w", stdout);

        // ------------------------------------------ CHANGE THIS
        switch (i - 50) {
        case 1:
            cout << "1" << nl;
            break;
        case 2:
            cout << "2" << nl;
            break;
        case 3:
            cout << "3" << nl;
            break;
        case 4:
            cout << "5" << nl;
            break;
        case 5:
            cout << "100000" << nl;
            break;
        case 6:
            cout << "25" << nl;
            break;
        case 7:
            cout << "24" << nl;
            break;
        case 8:
            cout << "26" << nl;
            break;
        case 9:
            cout << "125" << nl;
            break;
        case 10:
            cout << "126" << nl;
            break;
        case 11:
            cout << "124" << nl;
            break;
        case 12:
            cout << 78125 << nl;
            break;
        case 13:
            cout << 15625 << nl;
            break;
        case 14:
            cout << 1024 << nl;
            break;
        case 15:
            cout << 78126 << nl;
            break;
        case 16:
            cout << 15624 << nl;
            break;
        }
    }
}
