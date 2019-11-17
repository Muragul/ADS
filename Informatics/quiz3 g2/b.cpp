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

bool tinS(string t, string s){
    string s1 = t + "#" + s;
    vector<int> p = prefix_func(s1);
    for (int i = 0; i < s1.size(); i++){
        if (p[i] == t.size())
            return 1;
    }
    return 0;
}

int main(){
    int n;
    bool ans=0;
    string s;
    cin>>s>>n;
    string t[n];
    for (int i=0;i<n;i++){
        cin>>t[i];
    }
    for (int i=0;i<n;i++){
        if (tinS(t[i],s)){
            for (int j=i+1;j<n;j++){
                string s1 = t[i]+t[j];
                string s2 = t[j]+t[i];
                if (s1==s || s2==s)ans=1;
            }
        }
    }
    if (ans)cout<<"YES"; else cout<<"NO";
    return 0;
}