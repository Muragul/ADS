#include <iostream>
 using namespace std;

void f(int n){
    if (n>1) f(n/2);
    cout<<n%2;
}

 int main() {
    int n;
    cin >> n;
    f(n);
    return 0;
} 