#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
class Heap {
private:
    vector<T> heap;
public:
    Heap():
        heap()
    { push(0);}

    ~Heap(){}

    void push(T n) {
        heap.push_back(n);
    }

    void buildheap(){
        int pos = floor(heap.size()/3);

        while(pos){
            siftdown(pos, heap.size()-1);
            --pos;
        }
    }

    void siftdown(int start,int end){
        if((start*3)-1 > end) return;

        int left =(start*3)-1,
            center = (start*3<=end) ? start*3 : 0,
            right= ((start*3)+1<=end) ? (start*3)+1 : 0;

        int max = maxChild(left,center,right);

        if(heap[start] < heap[max]) swap(start,max);
        siftdown(max,end);

    }

    bool isLeaf(int node){return (node*3)-1 > heap.size(); }

    int maxChild(int l, int c, int r){
        if(heap[l]>heap[c]) return (heap[l]>heap[r]) ? l : r;
        return (heap[c]>heap[r]) ? c : r;
    }

    void swap(int c, int p){
        T temp = heap[c];
        heap[c] = heap[p];
        heap[p] = temp;
    }

    void print(){
        cout << "\nHeap: ";
        for(int i=0;i<heap.size();++i) cout << " " << heap[i] << " ";
        cout << endl;
    }

    void sort(){
        int start = 1, end=heap.size()-1;

        while(end > 3){
            swap(start,end);

            siftdown(start,--end);
        }

        if(heap[start] > heap[end]) swap(start,end);
    }

    void clear(){heap.clear();}

};


#endif //_HEAP_HPP
