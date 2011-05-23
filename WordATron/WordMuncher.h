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


#include "Words.h"

//function defentions
using namespace std;
using namespace boost;
using namespace boost::xpressive;

enum ERRORS {EMPTY, FULL};
\







class WordMuncher {
public:
    //INITS
    WordMuncher();
    WordMuncher(string reg,string filename);
    ~WordMuncher();
    //METHODS
    void readFileRegex(std::string reg, std::string filename);
    void readIfStream(string reg, string filename);
    void readWriteTokenizer(string reg, string text);
    void addWordToStruct(std::string word);
    void printStrcutOfWords();
    
    
private:
    //DATA
    string regex;
    string filenames;
    struct WORDS theword;
    vector<WORDS> wordstrcut;
    long int counterline;
    long int counterparagraph;
    bool debug;


};

#endif //WORDMUNCHER_H