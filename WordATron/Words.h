//
//  Words.h
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 bellmonde. All rights reserved.
//
#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <string>

using namespace std;

    
struct WORDS {
    
    string str;
    long int frequency;
    int syllables; 
    vector<long int> paratraph;
    vector<long int> line;
};


#endif //WORDS_H