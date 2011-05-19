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


#include<iostream>
#include<boost/tokenizer.hpp>
#include<string>
#include <fstream>

void readFile();
void readText();

int main()
{
    using namespace std;
    using namespace boost;
    readFile();
    //readText();
    cout << "WordATron 0.01" << endl;
    
}

void readFile() {
    
    using namespace std;
    using namespace boost;
    
    ifstream file( __FILE__ ) ;
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