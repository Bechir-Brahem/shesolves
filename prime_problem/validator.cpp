#include <bits/stdc++.h>
#define output cin

const int MAX = (int)1e5 + 5;

using namespace std;

vector<int> isPrime(MAX, 1);
vector<int> primes;

void sieve() {
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i < MAX; i += 1 + (i != 2)) {
        if (!isPrime[i])
            continue;
        int j = 2 * i;
        while (j < MAX) {
            isPrime[j] = 0;
            j += i;
        }
    }
    for (size_t i = 2; i < MAX; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
}

inline bool failedNotEof(const istream &in) {
    return (bool(in.rdstate() & in.failbit) &&
            bool(!(in.rdstate() & in.eofbit)));
}

bool possible(int n, int k) {
    if (n & 1) {
        if (k == 2) {
            return isPrime[n - 2];
        } else {
            return n - 3 - (k - 3) * 2 > 2;
        }
    } else {
        return n - (k - 2) * 2 > 2;
    }
}

/* using my_map = map<pair<int, int>, bool>; */
/* my_map mem; */

/* bool possible(int n, int k) { */
/*     assert(k > 0); */
/*     if (k == 1) */
/*         return isPrime[n]; */
/*     my_map::iterator it; */
/*     if ((it = mem.find({n, k})) != mem.end()) { */
/*         return it->second; */
/*     } */
/*     for (int i = 0; i < (int)primes.size() && primes[i] <= n; i++) { */
/*         int p = primes[i]; */
/*         if (possible(n - p, k - 1)) */
/*             return mem[{n, k}] = true; */
/*     } */
/*     return mem[{n, k}] = false; */
/* } */

int main(int argc, char *argv[]) {
    fstream input(argv[1]);
    /* fstream output("output"); */
    const string path = argv[3] + string{"judgement.txt"};
    freopen(path.c_str(), "w", stdout);
    sieve();
    int t=1;
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        input >> n >> k;
        string res;
        getline(output, res);
        if (!output) {
            cout << "NO\n";
            exit(43);
        }
        if (res == "impossible") {
            if (possible(n, k)) {
                cout << "NO: solution is possible but output says impossible "
                        "in test "
                     << tt << " n = " << n << " k = " << k << endl;
                exit(43);
            }
        } else {
            stringstream in{res};
            vector<int> v;
            int x;
            while (in >> x) {
                if (x <= 0 || x >= MAX) {
                    cout << "NO: element out of range in test " << tt
                         << " n = " << n << " k = " << k << endl;
                    exit(43);
                }
                if (!isPrime[x]) {
                    cout << "NO: element " << x << " is not prime in test "
                         << tt << " n = " << n << " k = " << k << endl;
                    exit(43);
                }
                v.push_back(x);
            }
            if (failedNotEof(in)) {
                cout << "NO: error in reading sequence of integers in test "
                     << tt << " n = " << n << " k = " << k << endl;
                exit(43);
            }
            int sum = 0;
            for (int el : v)
                sum += el;
            if ((int)v.size() != k) {
                cout << "NO: number of elements is not equal to k in test "
                     << tt << " n = " << n << " k = " << k << endl;
                exit(43);
            }
            if (sum != n) {
                cout << "NO: sum is not equal to n in test " << tt
                     << " n = " << n << " k = " << k << endl;
                exit(43);
            }
        }
    }
    cout << "YES\n";
    return 42;
}
