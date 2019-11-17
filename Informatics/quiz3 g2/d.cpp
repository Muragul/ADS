#include <iostream>

using namespace std;

string removeV(string s){
    string t;
    for (int i=0;i<s.size()/2;i++){
        if (s[i]=='a' || s[i]=='A' || s[i]=='u' || s[i]=='U' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='y' || s[i]=='Y'){}
        else {
            t+=s[i];
        }
    }
    return t;
}
string reverseS(string s){
    string s1 = s.substr(s.size()/2);
    for (int i=0;i<s1.size()/2;i++)
        swap(s1[i],s1[s1.size()-i-1]);
    return s1;
}
int main(){
    int ans=0;
    string f = "0123456789";
    string s;
    cin>>s;
    int n = s.size()/2;
    string s1 = removeV(s);
    string s2 = reverseS(s);
    s = s1+s2;
    for (int i=0;i<=f.size();i++){
        if (s[0]==f[i])ans++;
    }
    f = "abcdefghijklmnopqrstuvwxyz";
    string f1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0;i<f.size();i++){
        if (s[0]==f[i])s[0]=f1[i];
    }
    cout<<s;
    return 0;
}