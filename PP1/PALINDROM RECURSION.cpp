#include <iostream>

//You are given a string. Identify, wheather it is a palindrom or not. 
//Palindrom is word that can be read from left to right the same as from right to left.

using namespace std;

bool f(string s){
    if (s=="" || s.size()==1)return true;
        if (s[0]==s[s.size()-1]) return f(s.substr(1,s.size()-2)); else
        return false;
}

int main(){
    string s;
    cin>>s;
    if (f(s))cout<<"YES"; else cout<<"NO";
    return 0;
}