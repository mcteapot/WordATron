//
//  Heap.h
//  WordATron
//
//  Created by arjun prakash on 5/23/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#ifndef HEAP_H
#define HEAP_H


#include <vector>
#include "AWord.h"


typedef int Index;

template <typename T>
class MinHeap {
	public:
		std::vector<T> nodes;

		void push( const T& x );
		void pop();

		T& top();

		bool isEmpty();

	private:
		static const Index rootIndex = 0;
		bool exists( Index i );
		Index parentOf( Index node );
		Index smallestChildOf( Index node );

	public: 
        void debug();
		void printInOrder();

};



template <typename T>
void MinHeap<T>::push( const T& x ) {
	// stick it in at the bottom (last slot, next open leaf) / make room there
	nodes.push_back(x);

	Index cur = ( nodes.size() - 1 ),
		parent;

	// bubble up into place a.operator+ (b);
	while ( exists(parent = parentOf(cur)) &&  (x < nodes[parent]) ) { 
		//heap is out of order, swap parent down to make room, and move up
		nodes[cur] = nodes[parent];
		cur = parent;
	}
	nodes[cur] = x; // note, optimization: we only need to copy the data once, into its final position
}
	
template <typename T>
void MinHeap<T>::pop() {
	// removing the root

	// start by swapping the last leaf into the root, then letting it cascade down into place
	T& data = nodes.back(); // optimization: instead of swapping, just hold a ref to the "moving" data

	//cascade down
	Index cur = 0, child; 
    while ( (child = smallestChildOf(cur)) // returns root (0) when no children exist
        &&    (nodes[child] < data) ) {
        nodes[cur] = nodes[child];
        cur = child;
    }
    nodes[cur] = data; // note, no unnecessary copying is done :)

	//right-size the vector
	nodes.pop_back();
}

template <typename T>
T& MinHeap<T>::top() {
	return nodes.front();
}

template <typename T>
bool MinHeap<T>::isEmpty() {
	return nodes.empty();
}

template <typename T>
Index MinHeap<T>::parentOf(Index i) {
    // because the heap is a "complete" binary tree, and stored such,
    // we can compute the parent instead of storing a pointer (, or worse - searching *shudder*)
    return ( ( (i + 1)  // convert to one-based indexes
                >> 1 )  // write out one-based indexes in binary, it'll make sense
                - 1  ); // convert it back to zero-based for use with the vector
}

template <typename T>
Index MinHeap<T>::smallestChildOf(Index i) {
    // get the child indexes
    Index left = ( ( ( i +1) 
                       << 1)
                        - 1); // see MinHeap::paretnOf(Index i) for full rationalization
    Index right = left +1;
                
    if (exists(right)) {
        // because the heap is "complete" we know that if a right child exists, so does the left. 
        // return the least
        return ( nodes[right] < nodes[left])? right: left;
    } else {
        return (exists(left)) ? left : 0;  // signal with 0 (root) if neither child exists
    }
}    

template <typename T>
bool MinHeap<T>::exists(Index i) {
    return ((i >=0 ) && (i < nodes.size()));
} 

#include <iostream>
template <typename T>
void MinHeap<T>::debug() {
	std::cout << "debugging MinHeap #" << this << "\n";
	for (int i = 0; i < (int)nodes.size(); i++) {
        //TODO
		std::cout << nodes[i] << ", ";
	}
	std::cout << "\n\n";
}
template <typename T>
void MinHeap<T>::printInOrder() {
    std::cout << "debugging MinHeap #" << this << "\n";
	for ( ; ! isEmpty(); pop() ) {
        //TODO
        std::cout << top() << ", ";
    }
    std::cout << "\n\n";
}

#endif //HEAP_H