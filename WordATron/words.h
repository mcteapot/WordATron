#ifndef WORDS_H
#define WORDS_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "node.h"

#define NType node<T>
using namespace std;


//struct nodetype for linked list
template<typename T>
struct nodetype
{
    NType data;
    nodetype *ptr;
};

//#define NType node<T>
//run errors
enum rERRORS { FILE_IO_ERROR, FILE_DELETE_ERROR };

template<typename T>
class words
{
    public:
        words();//default constructor. Does nothing.
        words(string fileName);//single arguement constructor. USE THIS ONE.
        ~words();//destructor

        bool deleteFile();//deletes "outputFile"
        void openFile(string fileName);//CHANGE FILE PATH FOR OUTSIDE USE
        void print();//prints list of words without repeats and alphabetically, "outputFile"

        void sort();//sort vector list via linked list
        void push(NType *item);//push a word into preWordList
        void pop(NType *item);//remove word from sortedWordList
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


        vector< NType > preWordList;
        vector< NType > noRepsList;
        vector< NType > sortedWordList;

    protected:

    private:
        int size();
        nodetype<T> *start, *last, *entry, *newnode;
        string title, outputFile;
};


/* DEFINITIONS */
#include "words.h"
//#include "tree.h"

template<typename T>
words<T>::words()
{
    outputFile = "WordList.txt";
}

template<typename T>
words<T>::words(string fileName)
{
    title = fileName;
    outputFile = "WordList.txt";
    openFile(fileName);
}

template<typename T>
words<T>::~words()
{
    preWordList.clear();
    sortedWordList.clear();
    noRepsList.clear();
    //deLinkList();
}

template<typename T>
void words<T>::deLinkList()
{
     nodetype<T> *current, *tmp;

     current = start->ptr;
     start->ptr = NULL;
    while(current != NULL)
    {
        tmp = current->ptr;
        delete(current);
        current = tmp;
    }
}

template<typename T>
void words<T>::initLinkList()
{
    T info;

    start = new nodetype<T>;
    start->ptr = NULL;
    last = start;
    //cout << "noRepsList.size(): " << noRepsList.size() << endl;

    //for (vector< NType >::iterator i = noRepsList.begin(); i != noRepsList.end(); ++i)
    for(int i = 0; i < int(noRepsList.size()); i++)
    {
        info = noRepsList[i]->word;

        newnode = new nodetype<T>;
        newnode->data = info;
        newnode->ptr = NULL;
        last->ptr = newnode;
        last = newnode;
    }
    sort();
}

template<typename T>
bool words<T>::deleteFile()
{
    if( remove(outputFile.c_str()) != 0 )
        return false;
    return true;
}

template<typename T>
void words<T>::openFile(string fileName)//CHANGE FILE PATH FOR OUTSIDE USE
{
    fstream file;
    string name;
    name = "C:\\Users\\Castillo\\Documents\\Qt C++\\Projects\\tree(2)\\" + fileName + ".txt";

    file.open(name.c_str(), ios::in);
    if( !(file.is_open()) )
    {
        throw FILE_IO_ERROR;
    }
    else
    {
        preWordList.clear();
        string lineInput;
        while( getline(file,lineInput, '\n') )
            preWordList.push_back(lineInput);
        file.close();
    }
    delRepeatsPreWordList();
}

template<typename T>
void words<T>::print()
{
    writeSortedListToFile();
}

template<typename T>
void words<T>::writeSortedListToFile()
{
     fstream out;

    out.open(outputFile.c_str(),ios::out | ios::trunc);
    if( !(out.is_open()) )
    {
        throw FILE_IO_ERROR;
    }
    else
    {
         entry = start->ptr;
             while(entry != NULL)
                 {
                     sortedWordList.push_back(entry->data);
                     out << entry->data << endl;
                     entry = entry->ptr;
                 }
             for(unsigned int i = 0; i < sortedWordList.size(); i++)
             {
                 cout << sortedWordList[i]->word << endl;
             }
    }
    out.close();
}

template<typename T>
void words<T>::delRepeatsPreWordList()
{
    bool found = false;

    noRepsList.push_back(preWordList[0]);
    //create a node with the word and incrememnt count here...
    //for(vector<NType>::iterator k = preWordList.begin(); k != preWordList.end(); ++k)
    for(int i = 0; i < int(preWordList.size()); i++)
    {
        //for (vector<NType>::iterator i = noRepsList.begin(); i != noRepsList.end(); ++i)
        for(int k = 0; i < int(noRepsList.size()); k++)
        {
            if(stoupper(noRepsList[k]->word) == stoupper(preWordList[i]->word))
            {
                //increment count of node by 1.
                //cout <<"stoupper(*k): " << stoupper(*k) << endl;
                //cout << "stoupper(*i): " << stoupper(*i) << endl<<endl;
                found = true;
                break;
            }
            else
            {
                //create new node and increment count by 1.
                found = false;
            }
        }
        if(found == false)
        {
            noRepsList.push_back(noRepsList[i]);
        }
    }
    initLinkList();
}

template<typename T>
int words<T>::wordCount()
{
    return sortedWordList.size();
}

template<typename T>
string words<T>::stoupper(string &str)
{
    string temp;
      for(unsigned int i = 0; i < str.length(); i++)
      {
          temp += toupper(str[i]);
          //cout << "temp: " << temp << endl;
      }
      return temp;
}

template<typename T>
void words<T>::sort()
{
    nodetype<T> *next, *temp;

    last = start->ptr;
    while(last != NULL)
    {
        next = last;
        while(next != NULL)
        {
            if( stoupper(last->data->word) > stoupper(next->data->word) )
            {
                temp = new nodetype<T>;
                temp->data = next->data;
                next->data = last->data;
                last->data = temp->data;
                delete temp;
            }
            next = next->ptr;
        }
        last = last->ptr;
    }
}

template<typename T>
bool words<T>::search(string key, int list)//preWordList = 1, sortedWordList = 2;
{
    switch(list)
    {
    case 1: //search preWordList
    {
        for(int k = 0; k < int(preWordList.size()); k++)
            cout << preWordList[k]->word << endl;
        cout <<"preWordList.size(): " << preWordList.size() << endl;

        //for (vector<NType>::iterator i = preWordList.begin(); i != preWordList.end(); ++i)
        for(int i = 0; i < int(preWordList.size()); i++)
        {
            if(stoupper(key) == stoupper(preWordList[i]->word))
            {
                cout << "key: " << key << endl << "*i: " << preWordList[i]->word << endl;
                return true;
            }
        }
        return false;
    }
        break;


    case 2: //search sortedWordList
            return find(key);
            break;
    default:
            break;
    }
    return false;
}

template<typename T>
bool words<T>::find(string key)
{
    nodetype<T> *current;
    current = new nodetype<T>;

    current = start->ptr;
    while( (current != NULL) && (stoupper(key) != stoupper(current->data->word)) )
    {
        current = current->ptr;
    }
    if(current == NULL)
    {
        delete current;
         return false;
    }
    else
        delete current;
    return true;
}

template<typename T>
void words<T>::push(NType *item)
{
    preWordList.push_back(item);
}

template<typename T>
void words<T>::pop(NType *item)
{
    //for (vector<NType>::iterator i = sortedWordList.begin(); i != sortedWordList.end(); ++i)
    for(int i = 0; i < int(sortedWordList.size()); i++)
    {
        if(stoupper(sortedWordList[i]->word) == stoupper(item->word))
            sortedWordList.erase(i);
    }
}

#endif // WORDS_H
