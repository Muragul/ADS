#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (a==0 || b==0) return a+b;
    int res = gcd(b, a % b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int fibonacci(int n){
    if (n==0)return 0;
    if (n==1)return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<lcm(fibonacci(a),fibonacci(b));
}