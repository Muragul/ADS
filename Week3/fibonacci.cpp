#include <iostream>

using namespace std;

int **mult(int **a, int **b){
    int **c = new int *[2];
    c[0] = new int [2];
    c[1] = new int [2];
    c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            for (int k=0;k<2;k++){
                c[i][j] +=a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

int **func(int **a, int n){
    if (n==1) return a;
    int **res=func(a,n/2);
    if (n%2) return mult(res,res); else
    return mult(mult(res,res),a);
}

int main(){
    int **a;
    a = new int *[2];
    a[0] = new int [2];
    a[1] = new int [2];
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    
    int n;
    cin>>n;
    int **b=func(a,n);

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++)
        cout<<b[i][j]<<" ";
        cout<<endl;
    }
}