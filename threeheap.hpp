/********************************************************************
* Project 3 - Heap sort, 3-Heap implementation
*
* Author: Paul Thompson  
*
* Purpose: 3-heap is a different view on the traditional binary heap.
* This implementation treats every node in the heap as having 3 
* children instead of the typical 2. This increases the speed of the
* sort since elements need not be sifted down through as many levels
* as a binary heap. 
*
********************************************************************/
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
    // Constructor and Destructor
    Heap():
        heap()
    { push(0);}

    ~Heap(){}

    void push(T n) {
        heap.push_back(n);
    }

    // Organizes the vector in a max-heap, with every node holding
    // a greater value than its 3 children. buildheap() calls
    // siftdown() on all internal nodes
    void buildheap(){
        // A 3-heap's last internal node is found at n/3
        int pos = floor(heap.size()/3);

        while(pos){
            siftdown(pos, heap.size()-1);
            --pos;
        }
    }

    // Does the heavy lifting of finding the largest child and swaping
    // values where the parent is less than the max child. siftdown() 
    // takes a starting and ending position and is recursive
    void siftdown(int start,int end){
        // Base case. If a node doesn't have a left child it is a leaf.
        // Left child is found at (start*3)-1 in a 3-heap
        if((start*3)-1 > end) return;

        // Find all 3 children. We use the ternary operator to determine
        // if the center and right children exist. If their expected position
        // is beyond the end, they do not exist and we set them to 0 for use
        // in the maxChild() function
        int left =(start*3)-1,
            center = (start*3<=end) ? start*3 : 0,
            right= ((start*3)+1<=end) ? (start*3)+1 : 0;

        // Return the index of the greatest child
        int max = maxChild(left,center,right);

        // Swap the parent with the maxChild if necessary
        if(heap[start] < heap[max]) swap(start,max);
        
        // Recursive call on the position of the max child. This value may
        // need to be sifted down further
        siftdown(max,end);

    }

    // External check if a node is a leaf
    bool isLeaf(int node){return (node*3)-1 > heap.size(); }

    // Find the max value between three children, l=left, c=center,r=
    // right. Note: these are the indexes of the values. The value at
    // position 0 is 0, so if either the c or r children do not exist,
    // the comparison will return 0.
    int maxChild(int l, int c, int r){
        // Max of 2 compares. If l > c, compar to r and return largest
        if(heap[l]>heap[c]) return (heap[l]>heap[r]) ? l : r;
        // Otherwise, compare c and r and return largest
        return (heap[c]>heap[r]) ? c : r;
    }

    // Swaps the values at the given child c and parent p indexes
    void swap(int c, int p){
        T temp = heap[c];
        heap[c] = heap[p];
        heap[p] = temp;
    }

    // Print the heap
    void print(){
        cout << "\nHeap: ";
        for(int i=0;i<heap.size();++i) cout << " " << heap[i] << " ";
        cout << endl;
    }

    // Sorting. Note: must call buildheap() prior to calling sort.
    void sort(){
        int start = 1, end=heap.size()-1;

        // Swap the start and the end, placing the largest value at end.
        // Call siftdown() to re-heap the elements between start and --end
        // Conintue until only 3 unsorted elements remain
        while(end > 3){
            swap(start,end);

            siftdown(start,--end);
        }

        // Because we're using a max-heap, the start is the largest node
        // and must be swapped one final time. We perform a check to make sure
        if(heap[start] > heap[end]) swap(start,end);
    }

    void clear(){heap.clear();}

};


#endif //_HEAP_HPP
