#include <iostream>
#include <set>
#include <iterator>

using namespace std;

long int n1,n2;
set <long int> c;
set <long int> b;

int main(){
    int k;
    cin>>n1;
    for (int i=0;i<n1;i++){
        cin>>k;
        c.insert(k);
    }
    cin>>n2;
    for (int i=0;i<n2;i++){
        cin>>k;
        b.insert(k);
    }
    if (c==b)cout<<"YES"; else
    cout<<"NO";
}