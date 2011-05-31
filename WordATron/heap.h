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
#include "WordOut.h"
#include <string>
typedef int Index;

template <typename T>
class Heap {
	public:
        //Node based strcut
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
        void printInOrderToWordOut(WordOut<string> &wordsaver);

};



template <typename T>
void Heap<T>::push( const T& x ) {
	nodes.push_back(x);

	Index cur = ( nodes.size() - 1 ),
		parent;

	while ( exists(parent = parentOf(cur)) &&  (x < nodes[parent]) ) { 

		nodes[cur] = nodes[parent];
		cur = parent;
	}
	nodes[cur] = x; 
}
	
template <typename T>
void Heap<T>::pop() {
	T& data = nodes.back(); 

	Index cur = 0, child; 
    while ( (child = smallestChildOf(cur)) 
        &&    (nodes[child] < data) ) {
        nodes[cur] = nodes[child];
        cur = child;
    }
    nodes[cur] = data; 
	nodes.pop_back();
}

template <typename T>
T& Heap<T>::top() {
	return nodes.front();
}

template <typename T>
bool Heap<T>::isEmpty() {
	return nodes.empty();
}

template <typename T>
Index Heap<T>::parentOf(Index i) {
    return ( ( (i + 1) 
                >> 1 )  
                - 1  ); 
}

template <typename T>
Index Heap<T>::smallestChildOf(Index i) {
    Index left = ( ( ( i +1) 
                       << 1)
                        - 1);
    Index right = left +1;
                
    if (exists(right)) {
        return ( nodes[right] < nodes[left])? right: left;
    } else {
        return (exists(left)) ? left : 0;  
    }
}    

template <typename T>
bool Heap<T>::exists(Index i) {
    return ((i >=0 ) && (i < nodes.size()));
} 

#include <iostream>
template <typename T>
void Heap<T>::debug() {
	std::cout << "debugging Heap #" << this << "\n";
	for (int i = 0; i < (int)nodes.size(); i++) {
        //TODO
		std::cout << nodes[i] << ", ";
	}
	std::cout << "\n\n";
}
template <typename T>
void Heap<T>::printInOrder() {
    std::cout << "Printout of Heap #" << this << "\n";
	for ( ; ! isEmpty(); pop() ) {
        //TODO
        std::cout << top().str << ", ";
    }
    std::cout << "\n\n";
}
template <typename T>
void Heap<T>::printInOrderToWordOut(WordOut<string> &wordsaver) {
	for ( ; ! isEmpty(); pop() ) {
        //TODO
        wordsaver.addNode(top().str, top().paratraph[0], top().line[0], top().syllables);
        //std::cout << top() << ", ";
    }
}

#endif //HEAP_H