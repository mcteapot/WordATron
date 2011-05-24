//
//  WordOut.h
//  WordATron
//
//  Created by arjun prakash on 5/24/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#ifndef WORDOUT_H
#define WORDOUT_H

#include <iostream>
#include <string>
#include <string.h>

#include "tree.h"
#include "heap.h"
#include "node.h"

using namespace std;

template <typename T>
class WordOut { 
public:
    WordOut(long int tWords, long int totalSentences);
    //Basic setters
    void setTime(float theTime);
    void setTotalSyllables(long int tSyllables);
    
    void fillWithTree(tree<T> &aTree);
    void fillWithHeap(MinHeap<T> &aHeap);
    
    //template<typename T>
    void addNode(node<T> &aNode); // used by fillWithTree(tree aTree);
    void addNode(string aString, int aParagraph, int aLine, int aSyllables); //  used by fillWithHeap(MinHeap aHeap);
    
    //Basic print functions
    void printWordCount();
    void printParagraphCout();
    void printReadingLevel();
    void printTopTen();
    void printTime();

    //UI print functions, what user will see
    void printSummary();
    void printLetters(char aChar);
    //SaveOut
    void saveOut();
    
    
private:
    float totalTime;
    int totalWords();
    int totalSyllables();
    int totalSentences();
    vector< node<T> > wordList;
    

};








#endif //WORDOUT_H