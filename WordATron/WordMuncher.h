//
//  WordMuncher.h
//  WordATron
//
//  Created by arjun prakash on 5/21/11.
//  Copyright 2011 bellmonde. All rights reserved.
//
#ifndef WORDMUNCHER_H
#define WORDMUNCHER_H

#include <iostream>
#include <boost/tokenizer.hpp>
//#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <string>
#include <fstream>
#include <algorithm>

#include "AWord.h"

#include "tree.h"
#include "heap.h"

//function defentions
using namespace std;
using namespace boost;
using namespace boost::xpressive;


enum ERRORS {EMPTY, FULL};


class WordMuncher {
public:
    //INITS
    WordMuncher(bool debuger = false);
    WordMuncher(string reg,string filename, bool debuger = false);
    ~WordMuncher();
    //METHODS
    void readFileRegex(std::string reg, std::string filename);
    void readIfStream(string reg, string filename);
    void readWriteTokenizer(string reg, string text);
    void addWordToStruct(std::string word);
    
    void setTreeSructOfWords(tree<string> &thetree);
    void setHeapSructOfWords(Heap<AWORD> &theheap);
    
    void printStrcutOfWords();
    void setFrequentWords();
    void printFrequencytOfWords();
    void setMostFrequentWords();
    void printMostFrequencytOfWords();
    
    void strLowerCase(string &astr);
    void firstLetterUpperCase(string &astr);
    
    long int getTotoalWords();
    long int getTotoalLines();
    
private:
    //DATA
    string regex;
    string filenames;
    struct AWORD theword;
    vector<AWORD> wordstrcut;
    vector<AWORD> wordstrcutfrequent;
    vector<AWORD> wordstrcutmostfrequent;
    long int totalWords;
    long int totalLines;
    long int counterline;
    long int counterparagraph;
    bool debug;


};

#endif //WORDMUNCHER_H