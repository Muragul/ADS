#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,a[1000];
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a, a+n, greater<int>());
    int i=0;
    while (a[i]==a[0]){
        i++;
    }
    cout<<a[i];
}