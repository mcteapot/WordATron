//
//  main.cpp
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 cyborgDino. All rights reserved.
//
/*
#include <iostream>

int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
*/


#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/regex.hpp>
#include <string>
#include <fstream>
#include "Words.h"
//function defentions
void readBoostRegex();
void readIfStream();
void readFile();
void readText();


int main()
{
    using namespace std;
    using namespace boost;
    //readFile();
    //readText();
    readIfStream();
    cout << "WordATron 0.01" << endl;
    struct WORDS word1;
    word1.str = "Hello";
    cout << word1.str << endl;
}

//functions
void readBoostRegex() {

}

void readIfStream() {
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            cout << line << endl;
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 
}

void readFile() {
    
    using namespace std;
    using namespace boost;
    ifstream file( "example.txt" ) ;    
    //ifstream file( __FILE__ ) ;
    string str;

    while( getline( file, str ) )
    {
        tokenizer<> toker( str ) ;
        for( tokenizer<>::iterator beg = toker.begin(); 
            beg != toker.end() ; ++beg ) cout << *beg << '\n' ;
    }
}

void readText() {
    
    using namespace std;
    using namespace boost;
    
    string s = "This is, a test";
    tokenizer<> tok(s);
    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end(); ++beg) {
        cout << *beg << "\n";
    }

}