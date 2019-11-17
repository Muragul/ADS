#include <iostream>
#include <algorithm>

using namespace std;

int a[1000][1000];

//1 2 3 4
//1 2 3 4
//1 2 3 4
//1 2 3 4

int main(){
    int n,m,cnt = 0;
    cin>>n>>m;
    int maxm[m];
    int minm[n];

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];

    for (int i=0;i<n;i++){
        int mini = a[i][0]; 
        for (int j=0;j<m;j++)
            mini = min(mini, a[i][j]);
        minm[i] = mini;
    }

    for (int j=0;j<m;j++){
        int maxi = a[0][j];
        for (int i=0;i<n;i++)
            maxi = max(maxi, a[i][j]);
        maxm[j] = maxi;
    }

    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    if (a[i][j]==maxm[j] && a[i][j]==minm[i])cnt++;

    cout<<cnt;
}