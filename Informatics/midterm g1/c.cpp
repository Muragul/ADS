#include <iostream>

using namespace std;

bool isPrime(int n){
    for (int i=2;i<n;i++)
    if (n%i==0)return false;
    return true;
}

int main(){
    int k;
    cin>>k;
    int cnt=0;
    int i=1;
    while (cnt!=k){
        i++;
        if (isPrime(i))cnt++;
    }
    cout<<i;
}