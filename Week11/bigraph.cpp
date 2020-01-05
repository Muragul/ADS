#include <iostream>
#include <vector>
using namespace std;

int used[100];
vector <int> g[100];
int n,m,x,y;
bool ok=1;
void dfs(int v, int c){
    used[v]=c;
    for (int i=0;i<g[v].size();i++){
        y = g[v][i];
        if (used[y]==0)dfs(y,3-c); else
        {
            if (used[y]==c) ok = 0;
        }
        
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
    dfs(0,1);
    cout<<ok;
    return 0;
}