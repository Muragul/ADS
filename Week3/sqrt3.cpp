#include <iostream>

using namespace std;

double find(double x){
    double left=1,right=x,range=0.000001;
    while (right-left>range){
        double middle=(right+left)/2;
        if (middle*middle*middle>x) right = middle;
        else
        left = middle;
    }
    return right;
}

int main(){
    double x;
    cin>>x;
    printf("%.10f",find(x));
    return 0;
}