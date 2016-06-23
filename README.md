# 3Heap
3Heap is based on a traditional heap data structure, but forces each node to have 3 children instead of 2.

In selecting 3 children for each node, the aim is to reduce the height of the tree for use in sorting. The siftdown function is called fewer times than in a 2-chil, binary heap, and the sorting process is accomplished faster. 

# Finding Children Nodes
Child nodes are located at the following positions where i equals the index of the parent:

left child = (i*3) - 1
center child = (i*3)
right child = (i*3) + 1

With this structure we can traverse the entire array with fewer recursive calls to siftdown.
