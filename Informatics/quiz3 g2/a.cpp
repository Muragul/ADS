#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <int> get_hash(string s){
    int n = s.size();
    vector <int> hash(n);
    hash[0]=s[0];
    int p = 31;
    int p_pow = 1;
    for (int i=1;i<n;i++){
        p_pow *= p;
        hash[i] += hash[i-1] + s[i]*p_pow;
    }
    return hash;
}

int tInS(string t, string s){
    int cnt=0;
    vector <int> hash_s = get_hash(s);
    int hash_t = get_hash(t)[t.size()-1];
    int n = s.size();
    vector <int> p(n);
    p[0] = 1;
    for (int i=1;i<n;i++)
        p[i] = p[i-1] * 31;
    for (int i=0; i<s.size()-t.size()+1;i++){
        int j = i+t.size()-1;
        int hash_i_j = hash_s[j];
        if (i>0)
            hash_i_j = hash_s[j] - hash_s[i-1];
        if (hash_i_j == hash_t * p[i])
            cnt++;
    }
    return cnt;
}

string t[100];

int main(){
    int n;
    cin>>n;
    string s;
    while (n!=0){
        map <string, int> map1;
        for (int i=0;i<n;i++)
            cin>>t[i];
        cin>>s;
        for (int i=0;i<n;i++){
            int cnt = tInS(t[i],s);
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

        cin>>n;
    }

    return 0;
}