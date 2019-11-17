#include <iostream>

using namespace std;

int a[1000][1000];

int main(){
    int x,n;
    cin>>x>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
        cin>>a[i][j];
    }
    for (int j=0;j<n;j++){
        int cnt=0;
        for (int i=0;i<n;i++)
            if (a[i][j]==x)cnt++;
        if (cnt>0)cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
}