#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long int> c;

long int Merge(long int x){
    long int uk1=0, uk2=0;
    for (long int i=0;i<=x;i++){
        if (uk1*uk1<uk2*uk2*uk2){
            c.push_back(uk1*uk1);
            uk1++;
        } else
        if (uk1*uk1>uk2*uk2*uk2){
            c.push_back(uk2*uk2*uk2);
            uk2++;
        } else
        {
            c.push_back(uk1*uk1);
            uk1++;
            uk2++;
        }
    }
    return *(c.rbegin());
}

int main(){
    long int x;
    cin>>x;
    cout<<Merge(x);
}