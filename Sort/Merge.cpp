#include <iostream>

using namespace std;

long int n;
long int a[1000000];

void Merge(long int l, long int m, long int r){
    long int uk1=0, uk2=0, k=l;
    long int left = m-l+1;
    long int right = r-m;
    long int L1[left];
    long int R1[right];

    for (long int i=0;i<left;i++)
        L1[i] = a[i+l];
    for (long int i=0;i<right;i++)
        R1[i] = a[m+i+1];
    while (uk1<left && uk2<right){
        if (L1[uk1]<R1[uk2]){
            a[k] = L1[uk1];
            uk1++;
        } else
        {
            a[k]=R1[uk2];
            uk2++;
        }
        k++;
    }
    while (uk1<left){
        a[k] = L1[uk1];
        uk1++;
        k++;
    }
    while (uk2<right){
        a[k] = R1[uk2];
        uk2++;
        k++;
    }
}

void MergeSort(long int l, long int r){
    if (l<r){
        long int m = (l+r)/2;
        MergeSort(l,m); 
        MergeSort(m+1,r);
        Merge(l,m,r);
    }
}

int main(){
    cin>>n;
    for (long int i=0;i<n;i++)
        cin>>a[i];
    MergeSort(0, n-1);
    for (long int i=0;i<n;i++)
        cout<<a[i]<<" ";
}