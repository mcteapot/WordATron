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

#include "WordMuncher.h"
#include "tree.h"
#include "heap.h"

using namespace std;
//Data
bool sorting = true;
bool display = false;
bool working = true;
int chooseNum = 0;

struct AWORD awords;
struct AWORD bwords;

//Functions Declaratons
void menu();

int main (int argc, const char * argv[]) {
    
    cout << "********WordATron 0.01********" <<endl;
    //Load File
    
    tree<string> test2;

    
    //WordMuncher wordmunch("\\w[\\w.]\\S+|\\w[\\w.]\\?|\\w[\\w+]", "example.txt");
    
    /*
    test2.insert("john");
    test2.insert("john");
    test2.insert("mandy");
    test2.insert("buff");
    test2.insert("apples");
    test2.insert("ZeBra");    
    
    cout << "\nIn Order: \n";
    test2.setTraverse(IN);
    test2.print();
    cout << endl;
     */
    //wordmunch.printStrcutOfWords();
    //wordmunch.printFrequencytOfWords();
    //wordmunch.setMostFrequentWords();
    //wordmunch.printMostFrequencytOfWords();
    //wordmuch().working();
    /*
    MinHeap<AWORD> testHeap;
    awords.str = "boobs";
    testHeap.push(awords);
     */
    
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
    testHeap.debug();
    testHeap.printInOrder();
    //cout << awords.str << endl;
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
        cout << "1: SHOW TOP 10" << endl;
        cout << "2: CHOOSE LETTER" << endl;
        cout << "3: READING LEVEL" << endl;
        cout << "4: SAVE & QUIT" << endl;
        cout << "5: QUIT" << endl;
        cin >> chooseNum;
        display = false;
    }
    if ((display == false)&&(chooseNum == 1)) {
        cout << "--Shop Top 10" << endl << endl;
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
        cout << "--Reading Level" << endl << endl;
        display = true;
        chooseNum = 0;
    }
    if ((display == false)&&(chooseNum == 4)) {
        cout << "--Save & Quet" << endl << endl;
        display = true;
        working = false;
        chooseNum = 0;
    }
    if ((display == false)&&(chooseNum == 5)) {
        cout << "--Quet" << endl << endl;
        display = true;
        working = false;
        chooseNum = 0;
    }
    
}