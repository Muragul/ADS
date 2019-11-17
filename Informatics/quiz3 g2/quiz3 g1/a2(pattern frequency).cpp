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
string t[100];
int main(){
    map <string, int> map1;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t[i];
    }
    string s;
    cin>>s;
    for (int i=0;i<n;i++){
        string s1 = t[i] + "#" + s;
        int cnt = 0;
        vector<int> p = prefix_func(s1);
        for (int j = 0; j < s1.size(); j++){
        if (p[j] == t[i].size())
            cnt++;
        }
        map1.insert(make_pair(t[i],cnt));
    }
    map<string,int>::iterator it;
    int max = 0;
    for (it=map1.begin();it!=map1.end();it++){
        if ((*it).second>max)max = (*it).second;
    }
    cout<<max<<endl;
    for (it=map1.begin();it!=map1.end();it++){
        if ((*it).second==max)
            cout<<(*it).first<<endl;
    }

    return 0;
}