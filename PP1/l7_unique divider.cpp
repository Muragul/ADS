#include <iostream>
#include <cmath>
//Check the given number is 2-th degree.
//Print Yes, if given number is a 2-th degree. Else, print No
using namespace std;

void f(double n){
    if (n==1) {cout<<"Yes";} else
    if (floor(n)!=n){ cout<<"No";} else
    return f(n/2);
    
}

int main(){
    double n;
    cin>>n;
    f(n);
    return 0;
}