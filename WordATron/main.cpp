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
#include <sstream>
#include <cstdlib>
#include <fstream>
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
int chooseStruct = 0;
double elapsedTime, elapsedTimeHeap;



//Functions Declaratons

//MAIN FUNCTION
int main (int argc, const char * argv[]) {
    
    cout << "********WordATron 0.01********" <<endl;
    //Load File
    WordMuncher wordmunch("\\w[\\w.]\\S+|\\w[\\w.]\\?|\\w[\\w+]", "example.txt");
    
    
    //WordOut<string> wordsaver();
    WordOut<string> wordsaver((int)(wordmunch.getTotoalWords()), (int)(wordmunch.getTotoalLines()),wordmunch.getTotalParagraphs());
    
    //TREEE
    //Timer Start
    timeval t1, t2;
    gettimeofday(&t1, NULL);
    
    //create Tree;
    tree<string> thetree;
    wordmunch.setTreeSructOfWords(thetree);
    thetree.setTraverse(IN);
    
    // stop timer
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    //cout << elapsedTime << " ms." << endl << endl;
    
    wordsaver.fillWithTree(thetree);
    //set timer 
    wordsaver.setTime(elapsedTime);

    wordmunch.setMostFrequentWords();
    
    for(int i = 0; i < wordmunch.getFrequentCount(); i++){
        wordsaver.setMostFrequent(wordmunch.getMostFrequent(i));
    }
     
    //HEAP
    Heap<AWORD> theHeap;
    //Timer Start
    timeval th1, th2;
    gettimeofday(&th1, NULL);
    //Add To heap and heapafie
    wordmunch.setHeapSructOfWords(theHeap);
    //debug
    theHeap.printInOrder();
    // stop timer
    gettimeofday(&th2, NULL);
    elapsedTimeHeap = (th2.tv_sec - th1.tv_sec) * 1000.0;      // sec to ms
    elapsedTimeHeap += (th2.tv_usec - th1.tv_usec) / 1000.0;   // us to ms
    
    //Create heaps Word out
    WordOut<string> wordsaverHeap((int)(wordmunch.getTotoalWords()), (int)(wordmunch.getTotoalLines()),wordmunch.getTotalParagraphs());
   
    //theHeap.printInOrderToWordOut(wordsaverHeap);
    //Insert Heapafined into wordout
    //set tiem for heap time

    wordsaverHeap.setTime(elapsedTime);
    
    
    //MAIN MENU
    while(working) {
        if(sorting) {
            cout << "1: TREE" << endl;
            cout << "2: HEAP" << endl;
            cin >> chooseNum;
            sorting = false;
            
        }
        if ((sorting == false)&&(chooseNum == 1)) {
            cout << "--Tree1 Sort" << endl << endl;
            //Start///
            
                      
            //End///
            display = true;
            chooseStruct = 1;
            chooseNum = 0;
        }
        if ((sorting == false)&&(chooseNum == 2)) {
            cout << "--Heap Sort" << endl << endl;
            //Start//
            //TODO heap
            //Heap<AWORD> theheap;
            //wordmunch.setHeapSructOfWords(theheap);
            //End//
            display = true;
            chooseStruct = 2;
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
            //Start//
            if(chooseStruct == 1) {
                wordsaver.printSummary(cout); 
            }
            if(chooseStruct == 2) { 
                cout << "HEAP INFO" << endl;
                wordsaver.printSummary(cout); 
                //wordsaverHeap.printSummary(cout);
            }
            cout << endl;
            //End//
            display = true;
            chooseNum = 0;
        }
        if ((display == false)&&(chooseNum == 2)) {
            char chooseChar;
            cout << "--Choose Letter" << endl << endl;
            //Start//
            cin >> chooseChar;
            stringstream ss;
            string s;
            ss << chooseChar;
            ss >> s;
            cout << "--Display " << s << endl << endl;
            if(chooseStruct == 1) {
                wordsaver.printLetters(s); 
            }
            if(chooseStruct == 2) { 
                cout << "HEAP LETTERS" << endl;
                wordsaver.printLetters(s);
            }

            cout << endl;
            //End//
            display = true;
            chooseNum = 0;
        }
        if ((display == false)&&(chooseNum == 3)) {
            cout << "--Save & Quet" << endl << endl;
            //Start//
            if(chooseStruct == 1) {
                fstream output;
                output.open(wordsaver.getSummaryFile().c_str(),ios::out | ios::trunc);
                wordsaver.printSummary(output);
                output.close();
                wordsaver.printEverything();
            }
            if(chooseStruct == 2) { 
                cout << "HEAP LETTERS" << endl;
            }

            //End//
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
    
    cout << "********WordATron 0.01********" <<endl;
    return 0;
    
}

