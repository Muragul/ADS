#include <iostream>

using namespace std;

int a[1000];

int main(){
    int n,k;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    for (int i=0;i<n;i++){
        if (a[i]==k)cout<<i+1<<" ";
    }
}