//
//  WordMuncher.cpp
//  WordATron
//
//  Created by arjun prakash on 5/21/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#include "WordMuncher.h"
//Init Functions//

WordMuncher::WordMuncher() {
    debug = true;
    counterparagraph = counterline = 0;
    //printTest();
}

WordMuncher::WordMuncher(string reg, string filename) {
    debug = true;
    counterparagraph = counterline = 0;
    filenames = filename;
    regex = reg;
    readIfStream(regex, filenames);
    printTest();
}
WordMuncher::~WordMuncher() {}
//Member Functions//

//void readFileRegex(std::string filename) : combo functions to read in file and parce
void WordMuncher::readFileRegex(string reg, string filename) {
    readIfStream(reg, filename);
}

//std::string* readIfStream(std::string stream) : reads instream with a file passed to it, need to return
void WordMuncher::readIfStream(std::string reg, std::string filename) {
    using namespace boost::xpressive;
    string line;
    ifstream myfile (filename.c_str());
    bool firstcheck = false;
    bool iscounting = false;
    if (myfile.is_open()) {
        while ( myfile.good() ) {
            getline (myfile,line);
            //Debug
            if(debug) {
                cout << line << endl;
                cout << endl;
            }    
            //checks for new paragraph
            if(line == "") {
                if(firstcheck == false && iscounting != true) {
                    iscounting = true;
                    firstcheck = true;
                }
                if(iscounting == true && firstcheck == true) {
                    //Debug
                    if(debug) {
                        cout << "#OFLINES:" << counterline << endl;
                        cout << "NEWLINE" << std::endl;
                    }    
                    counterparagraph ++;
                    firstcheck = false;
                    counterline = 0;
                    
                }
            } else if(line != ""){
                iscounting = false;
                firstcheck = false;
            }
            //Send to get parsed
            readWriteTokenizer(reg, line);
        }
        myfile.close();
    }
    
    else cout << "Unable to open file"; 
}
//void readwiterator(std::string reg, std::string text) :: idderates over a string 
void WordMuncher::readWriteTokenizer(string reg, string text) {
    string str( text );
    sregex token = sregex::compile(reg);
    boost::xpressive::sregex_iterator cur( str.begin(), str.end(), token );
    boost::xpressive::sregex_iterator end;
    for( ; cur != end; ++cur ) {
        boost::xpressive::smatch const &what = *cur;
        string word = what[0];
        //Debug
        if(debug) {
            cout << word << '\n';
        }
        //addWordToStruct(word);
    }
}

void WordMuncher::addWordToStruct(std::string word) {
    using namespace boost::xpressive;
    std::istringstream inpStream(word);
    double inpValue = 0.0;
    if (inpStream >> inpValue) {
        std::cout << "NUMBER:" << word << std::endl;
    }
    else {

        smatch what;
        sregex wordNewLine = sregex::compile( "(\\w+)(\\.+)|(\\w+)(\\?)|(\\w+)(!)|(\\w+)(,)|(\\w+)(;)|(\\w+)(:)|(\\w+)(\\d+)" );
        sregex wordDot = sregex::compile( "(\\w+)(\\.)" );
        sregex wordDots = sregex::compile( "(\\w+)(\\.+)" );
        sregex wordQuestion = sregex::compile( "(\\w+)(\\?)" );
        sregex wordExclamation = sregex::compile( "(\\w+)(!)" );
        sregex wordComa = sregex::compile( "(\\w+)(,)" );
        sregex wordSemiColin = sregex::compile( "(\\w+)(;)" );  
        sregex wordColin = sregex::compile( "(\\w+)(:)" );
        sregex wordNumbers = sregex::compile( "(\\w+)(\\d+)" );
        if( regex_match( word, what, wordNewLine ) ) {
            if (regex_match(word, what, wordDot)) {
                std::cout << "PEDIOD ";
                counterline ++;
            }
            if (regex_match(word, what, wordDots)) {
                std::cout << "DOTDOTDOT  ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
                counterline ++;
            }
            if (regex_match(word, what, wordQuestion)) {
                std::cout << "QESTION ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
                counterline ++;
            }
            if (regex_match(word, what, wordExclamation)) {
                std::cout << "EXCLIMATIN ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
                counterline ++;
            }
            if (regex_match(word, what, wordComa)) {
                std::cout << "COMA ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
            }
            if (regex_match(word, what, wordSemiColin)) {
                std::cout << "SEMICOLIN ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
            }
            if (regex_match(word, what, wordColin)) {
                std::cout << "COLIN ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
            }
            if (regex_match(word, what, wordNumbers)) {
                std::cout << "NUMBER ";
                std::cout << "WORD FIXED:"<< what[1] << '\n';
                word = what[1];
            }
            
        } 
        if(word !="") {
            bool newWord = true;
            for(int i = 0; i < wordStrcut.size(); i++) {
                if (wordStrcut[i].str == word ) {
                    wordStrcut[i].frequency ++;
                    wordStrcut[i].paratraph.push_back(counterparagraph);
                    wordStrcut[i].line.push_back(counterline);
                    std::cout << "WORD ADDED:" << word << std::endl;
                    newWord = false;
                }
            }
            if(newWord) {
                //(word);
                std::cout << "WORD CREATED:" << word << std::endl;
            }
        }
        
    }
    //std::cout << word << std::endl;
    
}

//void WordMuncher::printTest() : Print out to seee if it is working
void WordMuncher::printTest() {
    cout << "Working" << endl;
}