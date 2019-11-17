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

int findAnswer(string s){
    vector <int> p = prefix_func(s);
    for (int i=0;i<p.size();i++){
        if (p[i]>0){
            string t = s.substr(0,p[i]);
            string s1 = "";
            while (s1.size()<s.size())s1+=t;
            if (s1==s)return p[i];
        }
    }
    return s.size();
}

int main(){
    string s;
    cin>>s;
    int max = findAnswer(s);
    cout<<s.substr(0,max)<<endl<<max;
    return 0;
}