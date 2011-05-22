//
//  WordMuncher.h
//  WordATron
//
//  Created by arjun prakash on 5/21/11.
//  Copyright 2011 bellmonde. All rights reserved.
//
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <string>
#include <fstream>
#include "Words.h"

//function defentions
using namespace std;

enum ERRORS {EMPTY, FULL};

class WordMuncher {
public:
    //Word();
    //function defentions
    void readwiterator(std::string reg, std::string text);
    void readBoostRegex(std::string reg, std::string text);
    //void readBoostRegex();
    void readIfStream();
    void readFiless();
    void readText();
    void printError(std::string string);
    
    
    
private:

};

//void Word::readFiles() {}
void WordMuncher::readFiless(){
    printError("ERROR");
    //cout << "Keeping it lill" << endl;
}


void WordMuncher::printError(std::string string) {
    
    cout << "Keeping it lill" << endl;
}