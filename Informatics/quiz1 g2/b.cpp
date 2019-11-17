#include <iostream>

using namespace std;

int p[1000000];

int main(){
    int n,a,b,cnt=0;
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
    for (int i=2;i<n;i++){
        if (p[i]==0){
            for (int j=2;j<n;j++){
                if (i+j==n && p[j]==0){
                    cnt++;
                    if (cnt==1){
                        a=i;
                        b=j;
                    }
                }
            }
        }
    }
    cout<<a<<" "<<b;
}