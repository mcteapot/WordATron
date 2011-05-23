//
//  main.cpp
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 cyborgDino. All rights reserved.
//


#include <iostream>

#include "WordMuncher.h"

using namespace std;

int main()
{
    WordMuncher wordmuch("\\w[\\w.]\\S+|\\w[\\w.]\\?|\\w[\\w+]", "example.txt");
    wordmuch.printStrcutOfWords();
    cout << "********WordATron 0.01********" <<endl;
    //wordmuch().working();
    return 0;

}
