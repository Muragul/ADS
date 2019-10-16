#include <iostream>

using namespace std;

int d[100];

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[n];
        d[a[n]]++;
    }

    for (int i=0;i<99;i++){
        for (int j=0;j<d[i];j++)
        cout<<i<<" ";
    }
}