#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int used[100];
vector <int> g[100];
int n,m,x,y;
stack <int> q;

void dfs(int v){
    if (used[v]==0){
    q.push(v);
    used[v]=1;
    for (int i=0;i<g[v].size();i++){
        y = g[v][i];
        if (used[y]==0)dfs(y);
    }
    } else
    {
        if (used[v]==1)
    }
    

}

int main(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>x>>y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt=0;
    for (int i=0; i<n; i++)
        if (used[i]==0){
            dfs(i);
            cnt++;
        }
    cout<<cnt;
    return 0;
}