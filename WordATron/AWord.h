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
#include <string.h>

using namespace std;

    
struct AWORD {
    
    string str;
    long int frequency;
    int syllables; 
    vector<long int> paratraph;
    vector<long int> line;
    
    //TODO to make a true compare need to be the same case, upper case will throw it off

    bool operator<(AWORD& other) {
        
        return (strcmp(str.c_str(), other.str.c_str()) < 0);
    
    }
/*
    bool operator>(AWORD& other) {
        
        return (strcmp(str.c_str(), other.str.c_str()) > 0);
        
    }
    bool operator=(AWORD& other) {
        
        return (strcmp(str.c_str(), other.str.c_str()) != 0);
        
    }
 */
};

//bool operator< ( const AWORD& a, const AWORD& b) { return (strcmp(a.str.c_str(), b.str.c_str()) < 0); }



#endif //AWORDS_H