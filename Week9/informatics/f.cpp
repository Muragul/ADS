#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPalindrome(string s){
    if (s=="" || s.size()==1)return true;
        if (s[0]==s[s.size()-1]) return isPalindrome(s.substr(1,s.size()-2)); else
        return false;
}

int a[1000000];

void isp(string s){
    int m = s.size()/2;
    if (m==0)return;
    if (m==s.size()-1)return;
    for (int i=0;i<m;i++){
        int k = 1;
        string s1 = s.substr(m-i, k);
        if (isPalindrome(s1)) a[m]=s1.size();
        k++;
    }
    isp(s.substr(0,m));
    isp(s.substr(m,s.size()-1));
}

int main(){
    string s;
    cin>>s;
    a[0]=1;
    a[s.size()-1]=1;
    isp(s);
    for (int i=0;i<s.size();i++)
        cout<<a[i]<<" ";
    return 0;
}