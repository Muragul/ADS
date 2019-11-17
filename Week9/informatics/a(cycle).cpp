#include <iostream>
//Строка S была записана много раз подряд, после чего из получившейся строки взяли подстроку и дали вам. 
//Ваша задача определить минимально возможную длину исходной строки S.
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
    string s;
    cin>>s;
    vector <int> p = prefix_func(s);
    int answer = s.size() - p [s.size() - 1];  
    cout<<answer;
}