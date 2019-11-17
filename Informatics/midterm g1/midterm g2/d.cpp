#include <iostream>
#include <algorithm>

using namespace std;

long int n1,n2,n3 = 0;
long int a[1000000];
long int b[1000000];
long int c[1000000];

int main(){
    cin>>n1>>n2;
    for (int i=0;i<n1;i++)cin>>a[i];
    for (int i=0;i<n2;i++)cin>>b[i];
    for (int i=0;i<n2;i++)
    for (int j=0;j<n1;j++){
        if (a[j]==b[i]){
            cout<<a[j]<<" ";
            a[j] = -1;
        }
    }
    sort(a,a+n1);
    for (int i=0;i<n1;i++){
        if (a[i]!=-1)cout<<a[i]<<" ";
    }
}