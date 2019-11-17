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

bool sContainsT(string s, string t){
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
    cin>>n;
    bool answer[n];
    for (int i=0;i<n;i++){
        answer[i] = 1;
        int m;
        cin>>m;
        string nums[m];
        for (int j=0;j<m;j++){
            cin>>nums[j];
            if (j>0){
                for (int k=0;k<j;k++){
                    if (sContainsT(nums[j],nums[k]) || sContainsT(nums[k], nums[j]))answer[i]=0;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        if (answer[i]==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}