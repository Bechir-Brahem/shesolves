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

string generateString(int n) {
    string ret = randomString(n, 'A', 'Z');
    for (int i = 0; i < n; i++) {
        if (randomInt(0, 1) == 0) {
            ret[i] = tolower(ret[i]);
        }
    }
    return ret;
}

int main() {
    const int tests = 100;
    const int width = digitsNbr(tests);
    for (int i = 1; i <= tests; ++i) {
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
        switch (i) {
        case 1:
            cout << "3 Ahmed\n";
            break;
        case 2:
            cout << "5 Aycha\n";
            break;
        case 3:
            cout << "1 z" << nl;
            break;
        case 4:
            cout << "1 abc" << nl;
            break;
        case 5:
            cout << "100 " << generateString(100) << nl;
            break;
        case 6:
            cout << "1 " << generateString(100) << nl;
            break;
        case 7:
            cout << "100 a" << nl;
            break;
        default:
            cout << randomInt(1, 100) << ' '
                 << generateString(randomInt(1, 100)) << nl;
            break;
        }
    }
}
