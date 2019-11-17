#include <iostream>
#include <set>

using namespace std;

int main(){
    long int n,k;
    cin>>n;
    set <long int> a;
    for (long int i=0;i<n;i++){
        cin>>k;
        a.insert(k);
    }
    long int x;
    cin>>x;
    if (a.find(x)!=a.end())cout<<"YES"; else cout<<"NO";
    return 0;
}