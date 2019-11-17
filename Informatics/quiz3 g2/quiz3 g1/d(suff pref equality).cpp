#include <iostream>
#include <vector>

using namespace std;

vector <int> prefix_func (string s){
    int n = s.size();
    vector <int> p(n);
    p[0] = 0;
    for (int i=1;i<n;i++){
        int j=p[i-1];
        while (j>0 && s[i]!=s[j])j=p[j-1];
        if (s[i]==s[j])j++;
        p[i]=j;
    }
    return p;
}


int main(){
    string s,t,s1;
    cin>>s>>t;
    s1 = s + "#" + t;
    vector <int> p = prefix_func(s1);
    cout<<p[s1.size()-1];
    return 0;
}