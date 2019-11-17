#include <iostream>
#include <vector>

using namespace std;

vector <int> a;

class MaxHeap{
    public:
    int size;
    
    MaxHeap(){
        size = 0;
    }

    int Parent (int i){
        return i/2;
    }
    int Left (int i){
        return i*2;
    }
    int Right (int i){
        return i*2+1;
    }
    void insert(int k){
        size++;
        a.push_back(k);
        int i = size-1;
        while (i>0 && a[Parent(i)]<a[i]){
            swap(a[Parent(i)], a[i]);
            i = Parent(i);
        }
    }
    void heapify(int i){
        if (Left(i)>size - 1)return;
        int j = Left(i);
        if (a[j]<a[Right(i)] && Right(i)<size)j = Right(i);
        if (a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    int extractMax(){
        int max = a[0];
            swap(a[0],a[size-1]);
            size--;
            heapify(0);
        return max;
    }
};

int main(){
    int n, k, p;
    MaxHeap *maxHeap = new MaxHeap();
    cin>>n;
    for (int j=0;j<n;j++){
        cin>>k;
        if (k==1)cout<<maxHeap->extractMax()<<endl; else
        {
            cin>>p;
            maxHeap->insert(p);
        }
    }
}