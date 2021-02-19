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
    const int tests = 50;

    for(int i=1; i<=tests; ++i){
        stringstream ss;
        ss << "tests/test" << i << ".in";
        
        char fileName[20];
        ss >> fileName;
        freopen(fileName, "w", stdout);
        
// ------------------------------------------ CHANGE THIS 
        // 1 <= n <= 100
        // 1 <= a_i <= n
        int n;
        if(i <= 25) n = randomInt(1, 9);
        else n = randomInt(10, 100);
        int a[n+1];
        for(int j=1; j<=n; ++j) a[j]=j;
        shuffle(a+1, a+1+n, rng);

        cout << n << '\n';
        for(int j=1; j<=n; ++j) cout << a[j] << ' ';
        cout << '\n';
    }
}
