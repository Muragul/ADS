#include <iostream>

using namespace std;

int gcd(int n, int m){
    if ( n == 0 || m == 0 ) return m+n;
    return gcd(m,n%m);
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<gcd(n,m);
}