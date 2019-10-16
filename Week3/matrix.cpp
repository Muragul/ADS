#include <iostream>

using namespace std;

int **func(int **a){
    a = new int *[2];
    a[0] = new int [2];
    a[1] = new int [2];
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;     
    return a;
}

int main(){
    int **a;
    int **b = func(a);
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++)
        cout<<b[i][j]<<" ";
        cout<<endl;
    }
}