#include <iostream>
#include <vector>
//Дана непустая строка s. Нужно найти такое наибольшее число k и строку t, что s совпадает со строкой t, выписанной k раз подряд.
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
    string s;
    string s1="";
    int cnt = 0;
    cin>>s;
    vector <int>p = prefix_func(s);
    int k = s.size() - p[s.size()-1];
    string t = s.substr(0,k);
    while (s1.size()<s.size()){
        s1+=t;
        cnt++;
    }
    cout<<cnt;
    return 0;
}