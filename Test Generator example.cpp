#include "bits/stdc++.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randomInt(int l, int r){
    return uniform_int_distribution<int>(l,r)(rng);
}

string randomString(int n, char l, char r){
    int len = r-l+1;
    string res;
    for(int i=1; i<=n; ++i) res += char(l + randomInt(0,len-1));
    return res;
}

int main(){
    const int tests = 100;

    for(int i=1; i<=tests; ++i){
        stringstream ss;
        ss << "tests/test" << i << ".in";
        
        char fileName[20];
        ss >> fileName;
        freopen(fileName, "w", stdout);
        
// ------------------------------------------ CHANGE THIS 
        // 1 <= k <= 100
        // 1 <= s <= 100,000
        int k = randomInt(1, 100);
        int s = randomInt(1, 100000);
        cout << k << ' ' << s << '\n';
    }
}
