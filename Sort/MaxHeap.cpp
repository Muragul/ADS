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
        return (i-1)/2;
    }
    int Left (int i){
        return i*2+1;
    }
    int Right (int i){
        return i*2+2;
    }
    int getMax(){
        return a[0];
    }
    void insert(int i){
        size++;
        a.push_back(i);
        int k = size-1;
        while (k>0 && a[Parent(k)]<a[k]){
            swap(a[Parent(k)], a[k]);
            k = Parent(k);
        }
    }
    void heapify(int i){
        if (Left(i)>size - 1)return;
        int j = Left(i);
        if (a[j]<a[Right(i)])j = Right(i);
        if (a[i]<a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }
    void extractMax(){
            swap(a[0],a[size-1]);
            size--;
            heapify(0);
    }
    void decKey(int i, int new_value){
        a[i] = new_value;
        heapify(i);
    }
    void incKey(int i, int new_value){
        a[i] = new_value;
        while (i>0 && a[Parent(i)]<a[i]){
            swap(a[Parent(i)], a[i]);
            i = Parent(i);
        }
    }
    void Print(){
        for (int i=0;i<size;i++)
            cout<<a[i]<<" ";
    }
};

int main(){
    MaxHeap *maxheap = new MaxHeap();
    int n, k;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        maxheap->insert(k);
    }
    maxheap->heapify(0);
    maxheap->Print();

    return 0;
}