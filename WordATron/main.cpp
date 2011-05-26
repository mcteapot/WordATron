//
//  main.cpp
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 cyborgDino. All rights reserved.
//


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <sys/time.h>  

#include "WordMuncher.h"
#include "AWord.h"
#include "tree.h"
#include "words.h"
#include "node.h"
#include "heap.h"
#include "WordOut.h"


using namespace std;
//Data
bool sorting = true;
bool display = false;
bool working = true;
int chooseNum = 0;
double elapsedTime;


//Functions Declaratons
void menu();

int main (int argc, const char * argv[]) {
    
    cout << "********WordATron 0.01********" <<endl;
    //Load File
    WordMuncher wordmunch("\\w[\\w.]\\S+|\\w[\\w.]\\?|\\w[\\w+]", "example.txt");
    
    
    //WordOut<string> wordsaver();
    WordOut<string> wordsaver((int)(wordmunch.getTotoalWords()), (int)(wordmunch.getTotoalLines()));
    
    //Timer Start
    timeval t1, t2;
    gettimeofday(&t1, NULL);
    
    //create Tree;
    tree<string> thetree;
    wordmunch.setTreeSructOfWords(thetree);
    thetree.setTraverse(IN);
    //wordsaver.fillWithTree(thetree);
    
    //TODO heap
    //Heap<AWORD> theheap;
    //wordmunch.setHeapSructOfWords(theheap);
    
    // stop timer
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    cout << elapsedTime << " ms." << endl << endl;
        
    
    //set timer 
    wordsaver.setTime(elapsedTime);
    
    
    //debug
    wordsaver.printSummary();
    wordsaver.printLetters('a');
    thetree.print();
    
    
    
    //wordmunch.printStrcutOfWords();
    //wordmunch.printFrequencytOfWords();
    //wordmunch.setMostFrequentWords();
    //wordmunch.printMostFrequencytOfWords();
    //cout << "TOTAL WORDS: " << wordmunch.getTotoalWords() << endl;
    
    /*//Struct compare test
    struct AWORD awords;
    struct AWORD bwords;
    vector<AWORD> awordstrcut;
     
    awords.str = "apple";
    bwords.str = "zebra";
    awordstrcut.push_back(bwords);
    cout << awords.str << " < ";
    cout << awordstrcut[0].str << endl;  
    if(awords < awordstrcut[0]) {cout<<"WORKING"<<endl;}
    */
        
    /*//Tree test
    tree<string> test2;
    test2.insert("john", 3, 4, 1);
    test2.insert("john", 5, 2, 1);
    test2.insert("mandy", 2, 9, 2);
    test2.insert("buff", 2, 12, 1);
    test2.insert("apples", 111, 2, 5);
    test2.insert("ZeBra", 12, 12, 6);    
    
    cout << "\nIn Order: \n";
    test2.setTraverse(IN);
    test2.print();
    cout << endl;
     */
    
    /*//Heap strcut test
    MinHeap<AWORD> testHeap;
    struct AWORD awords;
    struct AWORD bwords;
     
    awords.str = "apples";
    testHeap.push(awords);
    awords.str = "bananas";
    testHeap.push(awords);
    awords.str = "bees";
    testHeap.push(awords);
    awords.str = "lebra";
    testHeap.push(awords);
    awords.str = "clear";
    testHeap.push(awords);
    testHeap.debug();
    //testHeap.printInOrder();
    */
    
    /*//Heap test
    MinHeap<string> testHeap;
    string awords = "boobls";
    testHeap.push(awords);
    awords = "oobls";
    testHeap.push(awords);
    awords = "zebra";
    testHeap.push(awords);
    awords = "fist";
    testHeap.push(awords);
    awords = "fist";
    testHeap.push(awords);
    awords = "poop";
    testHeap.push(awords);
    
    testHeap.debug();
    testHeap.printInOrder();
    */
    
    //Main Menu//
    
    /*
    while (working) {
        menu();
    }
    */
    cout << "********WordATron 0.01********" <<endl;
    return 0;

}

//Function Defenetions
void menu() {
    if(sorting) {
        cout << "1: TREE" << endl;
        cout << "2: HEAP" << endl;
        cin >> chooseNum;
        sorting = false;
        
    }
    if ((sorting == false)&&(chooseNum == 1)) {
        cout << "--Tree1 Sort" << endl << endl;
        display = true;
        chooseNum = 0;
    }
    if ((sorting == false)&&(chooseNum == 2)) {
        cout << "--Heap Sort" << endl << endl;
        display = true;
        chooseNum = 0;
    }
    if (display) {
        cout << "1: SHOW INFO" << endl;
        cout << "2: CHOOSE LETTER" << endl;
        cout << "3: SAVE & QUIT" << endl;
        cout << "4: QUIT" << endl;
        cin >> chooseNum;
        display = false;
    }
    if ((display == false)&&(chooseNum == 1)) {
        cout << "--Show Info" << endl << endl;
        display = true;
        chooseNum = 0;
    }
    if ((display == false)&&(chooseNum == 2)) {
        char chooseChar;
        cout << "--Choose Letter" << endl << endl;
        cin >> chooseChar;
        cout << "--Display " << chooseChar << endl << endl;
        display = true;
        chooseNum = 0;
    }
    if ((display == false)&&(chooseNum == 3)) {
        cout << "--Save & Quet" << endl << endl;
        display = true;
        working = false;
        chooseNum = 0;
    }
    if ((display == false)&&(chooseNum == 4)) {
        cout << "--Quet" << endl << endl;
        display = true;
        working = false;
        chooseNum = 0;
    }
    
}