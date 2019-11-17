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

bool Cycle(string t, string s){
    bool isCycle = false;
    string s1 = t + t;
    string s2 = s + "#" +s1;
    vector <int> p = prefix_func(s2);
    for (int i=0;i<s2.size();i++)
        if (p[i]==s.size())
            isCycle++;
    return isCycle;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Cycle(t,s);
    return 0;
}