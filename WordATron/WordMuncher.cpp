//
//  WordMuncher.cpp
//  WordATron
//
//  Created by arjun prakash on 5/21/11.
//  Copyright 2011 bellmonde. All rights reserved.
//

#include "WordMuncher.h"
//Init Functions//

WordMuncher::WordMuncher(bool debuger) {
    debug = debuger;
    counterparagraph = counterline = 0;
    //printTest();
}

WordMuncher::WordMuncher(string reg, string filename, bool debuger) {
    debug = debuger;
    counterparagraph = counterline = 1;
    theword.paratraph.push_back(counterparagraph);
    theword.line.push_back(counterline);
    filenames = filename;
    regex = reg;
    readIfStream(regex, filenames);
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
                    counterline = 1;
                    
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
        addWordToStruct(word);
    }
}

//void addWordToStruct(std::string word) //skims off extras characters and addes to vector
void WordMuncher::addWordToStruct(std::string word) {
    //using namespace boost::xpressive;
    istringstream inpStream(word);
    double inpValue = 0.0;
    //finds Numers
    if (inpStream >> inpValue) {
        if(debug) {
            std::cout << "NUMBER:" << word << std::endl;
        }    
    }
    //Finding matching to weed out puncution
    else {

        smatch what;
        boost::xpressive::sregex wordNewLine = sregex::compile( "(\\w+)(\\.+)|(\\w+)(\\?)|(\\w+)(!)|(\\w+)(,)|(\\w+)(;)|(\\w+)(:)|(\\w+)(\\d+)" );
        boost::xpressive::sregex wordDot = sregex::compile( "(\\w+)(\\.)" );
        boost::xpressive::sregex wordDots = sregex::compile( "(\\w+)(\\.+)" );
        boost::xpressive::sregex wordQuestion = sregex::compile( "(\\w+)(\\?)" );
        boost::xpressive::sregex wordExclamation = sregex::compile( "(\\w+)(!)" );
        boost::xpressive::sregex wordComa = sregex::compile( "(\\w+)(,)" );
        boost::xpressive::sregex wordSemiColin = sregex::compile( "(\\w+)(;)" );  
        boost::xpressive::sregex wordColin = sregex::compile( "(\\w+)(:)" );
        boost::xpressive::sregex wordNumbers = sregex::compile( "(\\w+)(\\d+)" );
        if( regex_match( word, what, wordNewLine ) ) {
            if (regex_match(word, what, wordDot)) {
                if(debug) {
                    std::cout << "PEDIOD ";
                }
                word = "";
                counterline ++;
            }
            if (regex_match(word, what, wordDots)) {
                if(debug) {
                    std::cout << "DOTDOTDOT  ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
                counterline ++;
            }
            if (regex_match(word, what, wordQuestion)) {
                if(debug) {
                    std::cout << "QESTION ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
                counterline ++;
            }
            if (regex_match(word, what, wordExclamation)) {
                if(debug) {
                    std::cout << "EXCLIMATIN ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
                counterline ++;
            }
            if (regex_match(word, what, wordComa)) {
                if(debug) {
                    std::cout << "COMA ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
            }
            if (regex_match(word, what, wordSemiColin)) {
                if(debug) {
                    std::cout << "SEMICOLIN ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
            }
            if (regex_match(word, what, wordColin)) {
                if(debug) {
                    std::cout << "COLIN ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
            }
            if (regex_match(word, what, wordNumbers)) {
                if(debug) {
                    std::cout << "NUMBER ";
                    std::cout << "WORD FIXED:"<< what[1] << '\n';
                }
                word = what[1];
            }
            
        } 
        if(word !="") {
            if(debug) {
                cout <<word<< " ADD WORD TO VECTOR" << endl;
                
            }
            theword.str = word;
            theword.frequency = 1;
            if((int)(word.size()%3) == 0) {
                theword.syllables = 1;
            
            }else {
                theword.syllables = (int)(word.size()/3);
            }
            theword.paratraph[0] = counterparagraph;
            theword.line[0] = counterline;
            
        }
        if(debug) {
            cout << theword.str << " " << theword.frequency << " " << theword.syllables << " " <<  theword.paratraph[0] << " " << theword.line[0] << " " << endl;
        }
        //Pushes words and finds most frequent word
        wordstrcut.push_back(theword);
        setFrequentWords();
    }

    
}
    
//void printStrcutOfWords() : print out strcut of words
void WordMuncher::printStrcutOfWords() {
    for(int i = 0; i < wordstrcut.size(); i++) {
        cout << "WORD " << i << ": "<< wordstrcut[i].str << endl;
        cout << "SYLB : " << wordstrcut[i].syllables << endl;
        cout << "PRGH : " << wordstrcut[i].paratraph[0] << endl;
        cout << "LINE : " << wordstrcut[i].line[0] << endl;
        cout << endl;
    }
}
void WordMuncher::printFrequencytOfWords() {
    for(int i = 0; i < wordstrcutfrequent.size(); i++) {
        cout << "WORD " << i << ": "<< wordstrcutfrequent[i].str << endl;
        cout << "FREQ : " << wordstrcutfrequent[i].frequency << endl;
        cout << "SYLB : " << wordstrcutfrequent[i].syllables << endl;
        cout << "PRGH : ";

        for(int j = 0; j < wordstrcutfrequent[i].paratraph.size(); j++) {
            cout << wordstrcutfrequent[i].paratraph[j] << " ";
        }
        cout << endl;
     
        cout << "LINE : ";
        for(int j = 0; j < wordstrcutfrequent[i].line.size(); j++) {
            cout << wordstrcutfrequent[i].line[j] << " ";
        }
        cout << endl << endl;
    }
}
//void setFrequentWords() : find most frequent words
void WordMuncher::setFrequentWords() { 
    bool newword = true;
    for(int i = 0; i < wordstrcutfrequent.size(); i++) {
        if(wordstrcutfrequent[i].str == theword.str) {
            wordstrcutfrequent[i].frequency ++;
            wordstrcutfrequent[i].paratraph.push_back(counterparagraph);
            wordstrcutfrequent[i].line.push_back(counterline);
            newword = false;
        }
    }
    if(newword) {
        wordstrcutfrequent.push_back(theword);
    }
    
}

