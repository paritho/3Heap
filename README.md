# 3Heap
3Heap is based on a traditional heap data structure, but forces each node to have 3 children instead of 2.

In selecting 3 children for each node, the aim is to reduce the height of the tree for use in sorting. The siftdown function is called fewer times than in a 2-child, binary heap, and the sorting process is accomplished faster. 

# Finding Children Nodes
Child nodes are located at the following positions where i equals the index of the parent:

left child = (i*3) - 1
center child = (i*3)
right child = (i*3) + 1

With this structure we can traverse the entire array with fewer recursive calls to siftdown.

# Using 3Heap

Compile threeheap.hpp with a main.cpp that instantiates a Heap object, populate it, then call buildheap() and then sort():

    Heap<int> my3heap;
    // populate the heap with your data
    my3heap.buildheap();
    my3heap.sort();

You may also print the heap by calling print(). Please be wary of doing this with large data sets.

threeheap is templated and should accept all data types, though only int has been tested at this time.
