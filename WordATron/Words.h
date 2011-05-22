//
//  Words.h
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 bellmonde. All rights reserved.
//
#ifndef WORDS_H
#define WORDS_H

#include <string>
#include "boost/tuple/tuple.hpp"

using namespace std;

struct CountStore {
    int paratraph;
    int line;
};
    
struct WORDS {
    
    string str;
    long int frequency;
    int syllables; 
    vector<long int> paratraph;
    vector<long int> line;
    void Count(int p, int l);
};


#endif //WORDS_H