#include <iostream>
#include <cmath>

using namespace std;

int a[1000];

int main(){
    int n,k;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    int x = 0;
    int r = abs(k - a[0]);
    for (int i=1;i<n;i++){
        if (abs(k-a[i])<r){
            x = i;
            r = abs(k-a[i]);
        }
    }
    cout<<a[x];
}