# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
 
const int N = (int)3e5 + 5;
const int inf = (int)1e9 + 7;
 
struct node{
  node *l, *r;
  int val;
  node(){
    l = r = nullptr;
    val = 0;
  }
  node(int val) : val(val), l(nullptr), r(nullptr){}
};
 
void insert(node *&cur, int val){
  if(val < cur -> val){
    if(cur -> l != nullptr){
        insert(cur -> l, val);
    } else{
        cur -> l = new node(val);
    }
  } else{
     if(cur -> r != nullptr){
       insert(cur -> r, val);
     } else{
       cur -> r = new node(val);
     }
  }
}
 
int sum[5001], mx;
 
void go(node *cur, int dep){
  if(cur == nullptr) return;
  mx = max(mx, dep);
  sum[dep] += cur -> val;
  go(cur -> l, dep + 1);
  go(cur -> r, dep + 1);
}
 
node *root = nullptr;
int n;
 
int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    if(root == nullptr){
      root = new node(x);
    } else{
      insert(root, x);
    }
  }
  go(root, 0);
  cout << mx + 1 << "\n"; 
  for(int i = 0; i <= mx; ++i){
    cout << sum[i] << " ";
  }
  return 0;
}