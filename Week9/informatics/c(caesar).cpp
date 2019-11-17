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

int isCycleFunc(string s, string t){
    if (s==t)
        return 0;
    int answer;
    bool isCycle = false;
    string s1 = t + t;
    string s2 = s + "#" +s1;
    vector <int> p = prefix_func(s2);
    for (int i=0;i<s2.size();i++)
        if (p[i]==s.size()){
            isCycle++;
            answer = i - s.size() - s.size();
        }
    if (isCycle==0)return-1;
    return answer;

}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<isCycleFunc(s,t);
    return 0;
}