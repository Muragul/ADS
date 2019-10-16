#include <iostream>
#include <cmath>
#include <iomanip>

//Given two integers a and b – sides of triangle. 
//You need to write a function that calculates the hypotenuse of the triangle.
//Use setprecision(4) to output the answer. 
//In order to use this function, you need to include iomanip library.

using namespace std;

int Hyp(int a,int b){
    cin>>a>>b;
    cout<<setprecision(4)<<sqrt(a*a+b*b);
}

int main(){
    int a,b;
    Hyp(a,b);
    return 0;
}