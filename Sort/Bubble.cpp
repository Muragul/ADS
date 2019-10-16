#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,a[1000];
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];

    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
        if (a[j]<a[i])
            swap(a[i],a[j]);
        
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
}