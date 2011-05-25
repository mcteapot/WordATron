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
#include <vector>
#include <string.h>

using namespace std;

    
struct AWORD {
    
    string str;
    long int frequency;
    int syllables; 
    vector<long int> paratraph;
    vector<long int> line;
    
    //TODO to make a true compare need to be the same case, upper case will throw it off
    
    //friend bool operator<(const AWORD &me,const AWORD& other) {
      //  cout << "lessthan" << endl;
    //return (me.str < other.str);
        
    //}
    
    
    friend bool operator<(const AWORD &me, AWORD &other);
    friend ostream& operator<<(ostream& out, const AWORD &me);
    /*    
    bool operator>(AWORD& other) {
        cout << "greaterthan" << endl;
        return (str > other.str);
        
    }
    bool operator==(AWORD& other) {
        cout << "equal" << endl;
        return (str == other.str);
        
    }
    */

};



#endif //AWORDS_H