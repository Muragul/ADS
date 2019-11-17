#include <iostream>

using namespace std;

int gcd(int b, int d){
    if (b==0 || d == 0) return b+d;
    return gcd(d,b%d);
}

int lcm(int b, int d){
    return (b*d)/gcd(b,d);
}

int main(){
    int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    y = lcm(b,d);
    x = (y/b)*a + (y/d)*c;
    int nod = gcd(x,y);
    x = x / nod;
    y = y / nod;
    cout<<x<<" "<<y;
}