#include <iostream>

using namespace std;

int main(){
    int a,b,c,n,mid;
    int r=100000,l=1,res=0;
    cin>>n>>a>>b>>c;
    while(l<=r){
        mid = (l+r)/2;
        if ((mid/a + mid/b + mid/c)>=n){
            res = mid;
            r = mid - 1;
        } else
        l = mid + 1;
    }
    cout<<res;
}