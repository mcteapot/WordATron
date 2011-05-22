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
#include <boost/xpressive/xpressive.hpp>
#include <string>
#include <fstream>
#include "Words.h"

//function defentions
void readwiterator(std::string reg, std::string text);
void readBoostRegex(std::string reg, std::string text);
//void readBoostRegex();
void readIfStream();
void readFile();
void readText();


int main()
{
    using namespace std;
    using namespace boost;
    //readFile();
    //readText();
    //readIfStream();
    //readBoostRegex( "\\w+","hello world!");
    //readBoostRegex( "(\\w+) (\\w+)!","hello world!");
    //readBoostRegex( "(\\w+)!","world!");
    //readwiterator("\\w+","This is his sdf4 fasce.");
    readwiterator("\\w+\\d | \\w+","This44 is his sdf4 fasce.");
    //cout << "WordATron 0.01" << endl;
    struct WORDS word1;
    //word1.str = "Hello";
    cout << word1.str << endl;
}

//functions
void readwiterator(std::string reg, std::string text) {
    using namespace boost::xpressive;
    std::string str( text );
    // find a whole word
    //sregex token = +alnum;
    sregex token = sregex::compile(reg);
    //wsregex token = "+_w";
    sregex_iterator cur( str.begin(), str.end(), token );
    sregex_iterator end;
    for( ; cur != end; ++cur ) {
        smatch const &what = *cur;
        std::string word = what[0];
        std::cout << word << '\n';
    
    }
}

void readBoostRegex(std::string reg, std::string text) {
using namespace boost::xpressive;
    std::string hello(text);
     //sregex rex = ;
    sregex rex = sregex::compile(reg);
    smatch what;
    
    if( regex_match( hello, what, rex ) )
    {
        std::cout << "working size:";
        std::cout << what.size() << "\n\n";
        std::cout << what[0] << '\n'; // whole match
        std::cout << what[1] << '\n'; // first capture
        std::cout << what[2] << '\n'; // second capture
    } else {
        std::cout << "not working" << std::endl;
    }
        
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