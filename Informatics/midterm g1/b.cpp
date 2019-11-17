# include <bits/stdc++.h>
 
using namespace std;
 
int n, d;
vector < int > a;
 
int main(){
  cin >> n >> d;
  for(int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    a.push_back(x);
  }
  int ans = 0;
  sort(a.begin(), a.end()); // Сортируем массив
  while(!a.empty()){
    ans++;
    int last = a.back(); // Максимальное число
    a.pop_back();
    for(int i = (int)(a.size()) - 1; i >= 0; --i){
      if(a[i] + last <= d){ // Если число a[i] подоходит
        a.erase(a.begin() + i); // Удаляем число a[i]
        break;
      }
    }
  }
  cout << ans;
  return 0;
}