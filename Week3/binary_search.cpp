#include <iostream>

using namespace std;
int p[1000000];

int main(){
    int n,k,left,right,mid;
    cin>>n;
    for (int i=0;i<n;i++)cin>>p[i];
    cin>>k;
    left=0;
    right=n-1;
    while(left<right){
        mid=(left+right)/2;
        if (p[mid]<k)left=mid+1; else
        right=mid;
    }
    //вывести последний экземпляр
    if (p[right]==k){
        while(p[right+1]==k)right++;
        cout<<++right;
    } else
    //вывести первый экземпляр
    //if (p[right]==k)cout<<right+1; else 
    {
    cout<<"not found"<<endl<<"Could be on "<<left+1<<" place"<<endl<<"Closest is ";
    int a=p[right-1];
    int b=p[right];
    if (k-a==b-k)cout<<a<<" and "<<b; else
    if (k-a<b-k)cout<<a; else cout<<b;

    }
}