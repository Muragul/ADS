#include <iostream>
#include <cmath>

using namespace std;

int a[1000000];

int main(){
    int n,h,k,mid,time;
    cin>>n>>h;
    int l=0,r=1000000;
    for (int i=0;i<n;i++)cin>>a[i];
    while(l<=r){
        mid = (l+r)/2;
        time = 0;
        for (int i=0;i<n;i++){
            if (a[i]/mid<1)time++; else 
            if ((a[i]%mid)!=0)time += (a[i]/mid) +1; else
            time += a[i]/mid;
        }
        if (time<=h){
            k = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout<<k;
}