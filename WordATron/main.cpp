//
//  main.cpp
//  WordATron
//
//  Created by arjun prakash on 2011-05-19.
//  Copyright 2011 cyborgDino. All rights reserved.
//


#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <string>
#include <fstream>
#include "Words.h"

//function defentions
void addWordToStruct(std::string word); 
void readWordsInTo(std::string reg, std::string filename);
void readwiterator(std::string reg, std::string text);
void readBoostRegex(std::string reg, std::string text);
//void readBoostRegex();
std::string* readIfStream(std::string reg, std::string filename);
void readFile();
void readText();

struct WORDS word;
long int counterline;
long int counterparagraph;

int main()
{
    using namespace std;
    using namespace boost;
    
    counterparagraph = 0;
    //struct WORDS word1;
    
    //readFile();
    //readText();
    //readIfStream("example.txt");
    //readBoostRegex( "\\w+","hello world!");
    //readBoostRegex( "(\\w+) (\\w+)!","hello world!");
    //readBoostRegex( "(\\w+)!","world!");
    //readwiterator("\\w+","This is his sdf4 fasce.");
    //readwiterator("\\w+\\d | \\w+","This44 is his sdf4 fasce.");
    //readWordsInTo("\\w+\\d | \\w+", "example.txt");
    //readWordsInTo("\\w+\\d|[\\w.]+", "example.txt");    
    
    readWordsInTo("\\w[\\w.]+", "example.txt");
    //readWordsInTo("\\w[\\w.]+", "example.txt");
    cout << "#OFPARAGRAPHS:" << counterparagraph << endl;
    cout << "********WordATron 0.01********" << endl<<endl;
    

    
    
    
    //word1.str = "Hello";
    //cout << word1.str << endl;
}
//FUNCTIONS

void addWordToStruct(std::string word) {
    using namespace boost::xpressive;
    std::istringstream inpStream(word);
    double inpValue = 0.0;
    if (inpStream >> inpValue) {
        std::cout << "NUMBER:" << word << std::endl;
    }
    else {
        //sregex sre = "//w";
        //sregex sre = +_w;
        smatch what;
        sregex wordDotMore = sregex::compile( "(\\w+)(\\.+)" );
        sregex wordDot = sregex::compile( "(\\w+)(\\.)" );
        if( regex_match( word, what, wordDotMore ) ) {
            if (regex_match(word, what, wordDot)) {
                std::cout << "SINGLE ";
            }
            std::cout <<"DOT:"<< word << endl;
            std::cout << "DOT FIXED:"<< what[1] << '\n';
            
        } else {
        //if( regex_match( "word", "//w//." ) )  
        std::cout << "WORD:" << word << std::endl;
        }
    }
    //std::cout << word << std::endl;
    
}
//void readWordsInTo(std::string filename) : combo functions to read in file and parce
void readWordsInTo(std::string reg, std::string filename) {
    //std::string regextest = "\\w+\\d | \\w+";
    readIfStream(reg, filename);
    
    

}
//void readwiterator(std::string reg, std::string text) :: idderates over a string 
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
        addWordToStruct(word);
        //std::cout << word << '\n';
    
    }
}
//void readBoostRegex(std::string reg, std::string text) : xpressive regex test
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
//std::string* readIfStream(std::string stream) : reads instream with a file passed to it, need to return 
std::string* readIfStream(std::string reg, std::string filename) {
    using namespace boost::xpressive;
    string line;
    ifstream myfile (filename.c_str());
    bool firstcheck = false;
    bool iscounting = false;
    //ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            
            getline (myfile,line);
            cout << line << endl;
            cout << endl;
            /*
            sregex newLine = sregex::compile( "/\n\n/" );
            //sregex newLine = sregex::compile( "(\\n)" );

            smatch what;
            //std::cout<< "WORKING" << endl;
            if (regex_match(line, what, newLine)) {
                std::cout << "SINGLE ";
            }
            */
            if(line == "") {
                if(firstcheck == false && iscounting != true) {
                    iscounting = true;
                    firstcheck = true;
                }
                if(iscounting == true && firstcheck == true) {
                    std::cout << "NEWLINE" << std::endl;
                    counterparagraph ++;
                    firstcheck = false;
                }
            } else if(line != ""){
                iscounting = false;
                firstcheck = false;
            }
            readwiterator(reg, line);
        }
        return &line;
        myfile.close();
    }
    
    else cout << "Unable to open file"; 
    return &line;
}
//void readFile(std::string filename) : uses old boost tokenizer
void readFile(std::string filename) {
    
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
//void readText() : uses boots tokenizer to breakup a string
void readText() {
    
    using namespace std;
    using namespace boost;
    
    string s = "This is, a test";
    tokenizer<> tok(s);
    for(tokenizer<>::iterator beg=tok.begin(); beg!=tok.end(); ++beg) {
        cout << *beg << "\n";
    }

}