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

struct WORDS words;
std::vector<WORDS> wordStrcut;

long int counterline;
long int counterparagraph;

int main()
{
    using namespace std;
    using namespace boost;
    //std::vector<WORDS> wordStrcut;
    counterparagraph = counterline = 0;
    //struct WORDS word1;
    //wordStrcut.str = :hello
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
    //wordStrcut->str.push_back("test");
    std::string hello = "hello";
    words.str = hello;
    words.frequency += 1;
    words.syllables = (int)(hello.size()%3);
    words.paratraph.push_back(1);
    words.line.push_back(4);
    //wordStrcut.str.push_back() = hello;
    wordStrcut.push_back(words);
    //wordStrcut.str.push_back(word.str);
    wordStrcut[0].paratraph.push_back(2);
    wordStrcut[0].line.push_back(9);
    cout << wordStrcut[0].str << wordStrcut[0].frequency << wordStrcut[0].paratraph[0] 
    << wordStrcut[0].line[0]  << wordStrcut[0].paratraph[1]  << wordStrcut[0].line[1] << endl;
    //cout << word.str << word.frequency << word.syllables << word.paratraph[0] << word.line[0] << endl;
    
    
    readWordsInTo("\\w[\\w.]\\S+|\\w[\\w.]\\?", "example.txt");
    //readWordsInTo("\\w[\\w.]\\S+|", "example.txt");

    //readWordsInTo("\\w[\\w.]+", "example.txt");
    std::cout << "#OFLINES:" << counterline << endl;
    cout << "#OFPARAGRAPHS:" << counterparagraph << endl;
    cout << "********WordATron 0.01********" << endl<<endl;
    

    
    
    
    //word1.str = "Hello";
    //cout << word1.str << endl;
}
//FUNCTIONS
void createNewWord(std::string word) {
    struct WORDS wordAdd;
    wordAdd.str = word;
    wordAdd.frequency = 1;
    wordAdd.syllables = (int)(word.size()%3);
    wordAdd.paratraph.push_back(counterparagraph);
    wordAdd.line.push_back(counterline);
    wordStrcut.push_back(words);

}

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
        sregex wordNewLine = sregex::compile( "(\\w+)(\\.+)|(\\w+)(\\?)|(\\w+)(!)|(\\w+)(,)|(\\w+)(;)|(\\w+)(:)" );
        sregex wordDot = sregex::compile( "(\\w+)(\\.)" );
        sregex wordDots = sregex::compile( "(\\w+)(\\.+)" );
        sregex wordQuestion = sregex::compile( "(\\w+)(\\?)" );
        sregex wordExclamation = sregex::compile( "(\\w+)(!)" );
        sregex wordComa = sregex::compile( "(\\w+)(,)" );
        sregex wordSemiColin = sregex::compile( "(\\w+)(;)" );  
        sregex wordColin = sregex::compile( "(\\w+)(:)" );
        if( regex_match( word, what, wordNewLine ) ) {
            if (regex_match(word, what, wordDot)) {
                std::cout << "PEDIOD ";
                counterline ++;
            }
            if (regex_match(word, what, wordDots)) {
                std::cout << "DOTDOTDOT  ";
                counterline ++;
            }
            if (regex_match(word, what, wordQuestion)) {
                std::cout << "QESTION ";
                counterline ++;
            }
            if (regex_match(word, what, wordExclamation)) {
                std::cout << "EXCLIMATIN";
                counterline ++;
            }
            if (regex_match(word, what, wordComa)) {
                std::cout << "COMA ";
            }
            if (regex_match(word, what, wordSemiColin)) {
                std::cout << "SEMICOLIN ";
            }
            if (regex_match(word, what, wordColin)) {
                std::cout << "COLIN ";
            }
            std::cout <<"DOT:"<< word << endl;
            std::cout << "WORD FIXED:"<< what[1] << '\n';
            
        }/* else if (regex_match( word, what, wordElse )) {
            std::cout <<"OTHER:"<< word << endl;
            //std::cout << "DOT FIXED:"<< what[1] << '\n';
            if(word !="") {
                std::cout << "WORD FIXED:" << what[1] << std::endl;
            }
            //std::cout << "WORD FIXED:" << what[1] << std::endl;
        
        }*/ else {
        //if( regex_match( "word", "//w//." ) )  
            if(word !="") {
                std::cout << "WORD:" << word << std::endl;
            }
            //std::cout << "WORD:" << word << std::endl;
        }
         //       std::cout << "WORD:" << word << std::endl;
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
                    std::cout << "#OFLINES:" << counterline << endl;
                    std::cout << "NEWLINE" << std::endl;
                    counterparagraph ++;
                    firstcheck = false;
                    counterline = 0;
                    
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