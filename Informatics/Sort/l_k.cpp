#include <iostream>

using namespace std;

int main(){
    int a[1000];
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    int min = a[0];
    int max = a[0];
    for (int i=0;i<n;i++){
        if (a[i]>max)max = a[i]; else
        if (a[i]<min)min = a[i];
    }
    for (int i=0;i<n;i++){
        if (a[i]==max)cout<<min<<" "; else
        cout<<a[i]<<" ";
    }
}