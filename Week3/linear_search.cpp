#include <iostream>

using namespace std;
int p[1000000];

int main(){
    int n,k,cnt=-1;
    cin>>n;
    for (int i=0;i<n;i++)cin>>p[i];
    cin>>k;
    for (int i=0;i<n;i++){
        if (k==p[i])cnt=i;
    }
    if (cnt==-1)cout<<"not found"; else
    cout<<++cnt;
}