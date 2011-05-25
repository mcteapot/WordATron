//
//  ExtraFunctions.cpp
//  WordATron
//
//  Created by arjun prakash on 5/24/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#include "AWord.h"

bool operator<(const AWORD &me, AWORD& other) {
    cout << "lessthan" << endl;
    return (me.str < other.str);    
}

ostream& operator<<(ostream& out, const AWORD &me) {
    out << me.str;
    return out;

}