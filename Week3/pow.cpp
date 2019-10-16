#include <iostream>

using namespace std;

int myPow(int a, int n){
    if (n==0)return 1;
    if (n==1)return a;
    int res = myPow(a, n/2);
    if (n%2) return res*res*a;
    return res*res;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<myPow(a,n);
    return 0;
}