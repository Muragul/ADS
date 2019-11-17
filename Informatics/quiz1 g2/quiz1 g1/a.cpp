#include <iostream>

using namespace std;
int p[1000000];
int a[1000000];

int main(){
    int n,cnt=0;
    cin>>n;
    for (int i=2;i*i<=n;i++){
        if (!p[i]){
            int k=i;
            while (k+i<=n){
                k+=i;
                p[k]=1;
            }
        }
    }
    int j=0;
    for (int i=2;i<=n;i++){
        if (!p[i]){
            a[j] = i;
            j++;
        };
    }
    int k = n;
    for (int i=0;i<k;i++){
        if (a[i]!=0)
        if (n%a[i]==0){
            n=n/a[i];
            cnt++;
        }
    }
    cout<<cnt;
}