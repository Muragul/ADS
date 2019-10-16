#include <iostream>

using namespace std;
int p[1000000];

int main(){
    int n;
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
    for (int i=2;i<=n;i++){
        if (!p[i])cout<<i<<" ";
    }
    return 0;
}