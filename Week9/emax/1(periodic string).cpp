#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        for (int j=1;j<s.size();j++){
            string s1;
            while (s1.size()<s.size())
                s1 += s.substr(0,j);
            if (s1 == s)cout<<j<<" ";
        }
    }
    return 0;
}