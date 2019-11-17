#include <iostream>

using namespace std;

int a[1000];

int main(){
    int n, max=-1001,cnt=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]>max){
            max=a[i];
            cnt = i;
            }
    }
    cout<<cnt+1;
}