#include <iostream>
#include <vector>
#include <map>

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
    map <string, int> map1;
    string s;
    int n;
    cin>>s>>n;
    for (int i=0;i<n;i++){
        string t;
        cin>>t;
        t[0] = t[0] - 'A' + 'a';
        string s1 = t + "#" + s;
        vector<int> p = prefix_func(s1);
        if (t[0] == s[s.size()-1])p[0]=1;
        int max = 0;
        for (int k = 0; k < s1.size(); k++){
            if (p[k] > max)max = p[k];
        }
        t[0] = t[0] - 'a' + 'A';
        map1.insert(make_pair(t,max));
    }
    map<string,int>::iterator it;
    int cnt = 0;
    int c = 0;
    for (it=map1.begin();it!=map1.end();it++){
         if ((*it).second>cnt)cnt = (*it).second;
        }
    for (it=map1.begin();it!=map1.end();it++){
        if ((*it).second==cnt)c++;
    }
    cout<<c<<endl;
    for (it=map1.begin();it!=map1.end();it++){
        if ((*it).second==cnt)
            cout<<(*it).first<<endl;
    }
    return 0;
}