#include <iostream>
#include <vector>
using namespace std;
//Output number of positions where parasite word meets in both students’ results. 
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
    string s1,s2,t;
    cin>>s1>>s2>>t;
    int cnt=0;
    string s11 = t + "#" + s1;
    string s22 = t + "#" + s2;
    vector <int> p1 = prefix_func(s11);
    vector <int> p2 = prefix_func(s22);
    for (int i = 0; i < p1.size(); i++)
        if (p1[i] == t.size() && p2[i] == t.size())cnt++;
    cout<<cnt;
    return 0;
}