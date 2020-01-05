#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> factorize(int x) {
    vector<int> factors;

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    if (x != 1) {
        factors.push_back(x);
    }

    return factors;
}

int main(){
    int n;
    cin>>n;
    cout<<n<<"=";
    vector<int> factor = factorize(n);
    for (int i=0;i<factor.size();i++)
        cout<<factor[i]<<"*";
    return 0;
}