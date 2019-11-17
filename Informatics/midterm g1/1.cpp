#include <iostream>
#include <algorithm>

using namespace std;
int p [1000000];

int main(){
    int n, sum=0;
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
        if (!p[i])
        if (n%i==0)sum+=i;
    }

    while (sum!=1){
        int i=2;
            if (p[i]==0 && sum%i==0){
                cout<<i<<" ";
                sum = sum/i;
            }
        i++;
    }
}