#include <iostream>

using namespace std;

long int a[100000];

int main(){
    long int n,k,cnt=0;
    cin>>n;
    for (long int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    for (long int i=0;i<n;i++){
        if (a[i]==k)cnt++;
    }
    cout<<cnt;
}