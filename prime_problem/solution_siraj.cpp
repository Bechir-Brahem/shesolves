#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define PI = arccos(-1)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;

vector <int> primes; 

// Sieve of Sundaram
// This algorithm is slower than Sieve of Erastosthenes with a time complexity of O(n log n) but it's kinda fun to implement!
void sieve(int n) 
{ 
    bool marked[n/2+100]={0}; 
    for (int i=1;i<=(sqrt(n)-1)/2;++i) 
        for (int j=(i*(i+1))<<1;j<=n/2;j=j+2*i+1) 
            marked[j]=true; 
    primes.push_back(2); 
    for (int i=1;i<=n/2;++i) 
        if (!marked[i]) 
            primes.push_back(2*i+1); 
} 

//Goldbach's conjecture
void goldbach(int n){ 
    for (int i=0;primes[i]<=n/2;++i){ 
        int gap=n-primes[i]; 
        if(binary_search(primes.begin(),primes.end(),gap)){ 
            cout<<primes[i]<<' '<< gap;
            return; 
        } 
    } 
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
int n,k;
cin>>n>>k;

sieve(n);

if(n<2*k) cout<<"Impossible";

/* If K==2 : 1- If N is even : Simply apply the conjecture
             2- If N is odd : 1- If N-2 is prime that means we can write N in the form of  2+(N-2)
                              2- If N-2 is not prime, we can't write N as a sum of 2 primes
*/
else if(k==2){
    if(n%2==0) goldbach(n);
    else{
        if(binary_search(primes.begin(),primes.end(),n-2)) {
            cout<<"2 "<<n-k;
        }
    else cout<<"Impossible";
    }
}

/* If K>2 : 1- If N is even : N=2*(K-2) + the conjecture of the remaining
            2- If N is odd : N=2*(K-3) + 2 + the conjecture of the remaining
    Also if K==3 and N is odd, there's no need to add the number 2 to the sum
*/
else{
    if(n%2==0){
        for(int i=0;i<k-2;++i) cout<<"2 ";
        goldbach(n-(2*(k-2)));
    }
    else{
        for(int i=0;i<k-3;++i) cout<<"2 ";
        cout<<"3 ";
        goldbach(n-(2*(k-2))-1);
    }
}


return 0;
}