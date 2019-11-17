#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;

class Heap{
    public:
    int size;
    
    Heap(){
        size = 0;
    }

    int Parent (int i){
        return (i-1)/2;
    }
    int Left (int i){
        return 2*i+1;
    }
    int Right (int i){
        return 2*i+2;
    }

    void insert (int k){
        size++;
        a.push_back(k);
    }

        void heapify(int i){
        if (Left(i)>size - 1)return;
        int j = Left(i);
        if (a[j]<a[Right(i)])j = Right(i);
        if (a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        };
    }
    int incKey(int j, int new_value){
        int i = j - 1;
        a[i] += new_value;
        while (i>0 && a[Parent(i)]<a[i]){
            swap(a[Parent(i)], a[i]);
            i = Parent(i);
        }
        return i + 1;
    }
    void Print(){
        for (int i=0;i<size;i++)
            cout<<a[i]<<" ";
    }

};

int main(){
    Heap *heap = new Heap();
    int n,k;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        heap->insert(k);
    }
    int a,b,c;
    cin>>a;
    for (int i=0;i<a;i++){
        cin>>b>>c;
        cout<<heap->incKey(b,c)<<endl;
    }
    heap->Print();

}
//the inverse
// #include <iostream>

// using namespace std;

// void out_array(int *a, int n) {
//  for (int i = 1; i <= n; i++) {
//   printf("%d%c", a[i], " \n"[i == n]);
//  }
// }

// int heapify_down(int *a, int n, int v) {
//  while (v <= n) {
//   int l = 2 * v; // left son
//   int r = 2 * v + 1; // right son
//   int s = v; // max among a[v],a[l],a[r]

//   /* let's find max */
//   if (l <= n && a[l] > a[s])
//    s = l;
//   if (r <= n && a[r] > a[s])
//    s = r;

//   // if v is max, then everything is ok
//   if (s == v) break;
//   // go down to vertex s
//   swap(a[v], a[s]);
//   v = s;
//  }
//  return v;
// }


// // these variables are lower than functions,
// // so functions can't see them
// int a[100005], n;

// int main() {

//  /*
//   problem from
//   https://informatics.msk.ru/mod/statements/view3.php?id=1234&chapterid=1165#1
//  */

//  scanf("%d", &n);
//  for (int i = 1; i <= n; i++) {
//   scanf("%d", a + i);
//  }
//  int q;
//  scanf("%d", &q);
//  for (int i = 1; i <= q; i++) {
//   int pos, x;
//   scanf("%d %d", &pos, &x);
//   a[pos] -= x;
//   int newPos = heapify_down(a, n, pos);
//   printf("%d\n", newPos);
//  }
//  out_array(a, n);


