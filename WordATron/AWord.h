//
//  Words.h
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 bellmonde. All rights reserved.
//
#ifndef AWORDS_H
#define AWORDS_H

#include <iostream>
#include <string>

using namespace std;

    
struct AWORD {
    
    string str;
    long int frequency;
    int syllables; 
    vector<long int> paratraph;
    vector<long int> line;
};


#endif //AWORDS_H