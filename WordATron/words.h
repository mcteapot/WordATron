#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "node.h"

using namespace std;

//struct nodetype for linked list
struct nodetype
{
    string data;
    nodetype *ptr;
};

//run errors
enum ERRORSS { FILE_IO_ERROR, FILE_DELETE_ERROR };

class words
{
    public:
        words();//default constructor. Does nothing.
        words(string fileName);//single arguement constructor. USE THIS ONE.
        ~words();//destructor

        bool deleteFile();//deletes "outputFile"
        void openFile(string fileName);//CHANGE FILE PATH FOR OUTSIDE USE
        void print();//prints list of words without repeats and alphabetically, "outputFile"

        void sort();//sort vector list
        void push(string word);//push a word into preWordList
        void pop(string word);//remove word from sortedWordList
        void initLinkList();//load linked list with words
        void deLinkList();//destructor for linked list
        void writeSortedListToFile();//write sorted linked list to file
        void delRepeatsPreWordList();//creates a new list from preWordList with zero repeats (noRepsList).

        int wordCount();//returns the size of sortedWordList ... how many different words there are
        int preWordSize()//return the preWordList size. Used for total words in the book
        {
            return preWordList.size();
        }
        int nodeCount()//returns how many different words there are.
        {
            return sortedWordList.size();
        }

        string stoupper(string &str);//function that returns an uppercase string
        bool search(string key, int list);//search preWordList (1) or sortedWordList (2) for a key word/node
        bool find(string key);//search sortedWordList for a key/word


    protected:        
        vector<string> preWordList;
        vector<string> noRepsList;
        vector<string> sortedWordList;
        int size();


    private:

    nodetype *start, *last, *entry, *newnode;
        string title, outputFile;

};

#endif // WORDS_H
