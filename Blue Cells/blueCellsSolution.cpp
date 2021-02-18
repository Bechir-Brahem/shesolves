#include<bits/stdc++.h>
using namespace std;


int main(){
    int r,c,x,y;
    cin >> r >> c >> x >> y;
    cout << r * c - (x*c + y*r - x*y);
}