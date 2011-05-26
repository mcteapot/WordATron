#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

enum nERRORS//node errors
{
    RECORD_ERROR, NO_DATA
};

template<typename T>
struct node
{
    node();
    node(T data);
    node(const node<T> &other);
    node<T> operator=(const node<T> &other);
    void copy(const node<T> &other);
    ~node();
    
    T word;
    int wordCount;
    int syllables;
    void wordCounts()
    {
        wordCount++;
    }
    
    int totalSyllables()
    {
        return syllables*wordCount;
    }
    
    vector< vector<int> > paragrahsLines;
    
    bool isString(T item);
    void update(int paragraph, int line, int syllable);
    void print();
    
    node *lt, *gt;
};

template<typename T>
node<T>::node(const node<T> &other)
{
    copy(other);
}

template<typename T>
node<T> node<T>::operator=(const node &other)
{
    if(this == other)
        return *this;
    copy(other);
}

template<typename T>
void node<T>::copy(const node<T> &other)
{
    word = other.word;
    syllables = other.syllables;
    gt = other.gt;
    lt = other.lt;
    wordCount = other.wordCount;
    
    vector<T> row;
    for(int i = 0; i < int(other.paragrahsLines.size()); i++)
    {
        for(int k = 0; k < int(other.paragrahsLines[i].size()); k++)
        {
            row.push_back(other.paragrahsLines[i][k]);
            //node.paragrahsLines[i].push_back(other.paragrahsLines[i][k]);
        }
        paragrahsLines.push_back(row);
    }
}

template<typename T>
void node<T>::print()
{
    cout << "\n"<<word << "(" << wordCount<<") ";
    
    for(int i = 0; i < int(paragrahsLines.size()); i++)
    {
        if(paragrahsLines[i].size() > 0)
        {
            cout << i << ":";
            for(int k = 0; k < int(paragrahsLines[i].size()); k++)
                cout<<paragrahsLines[i][k]<<" ";
        }
    }
}

template<typename T>
node<T>::node()
{
    wordCount = 0;
    syllables = 0;
    lt = NULL;
    gt = NULL;
}

template<typename T>
node<T>::node(T data)//look over! possible issues with counter
{
    word = data;
    syllables = 0;
    wordCount++;
    lt = NULL;
    gt = NULL;
}

template<typename T>
node<T>::~node()
{
    lt = NULL;
    gt = NULL;
}

template<typename T>
void node<T>::update(int paragraph, int line, int syllable)
{
    syllables = syllable;
    //cout << "paragrahsLines.size()-1:" << paragrahsLines.size()-1 << endl;
    if( int(paragrahsLines.size()) == 0 || int((paragrahsLines.size()-1)) < paragraph )
    {
        //cout << "toDo: " << (paragraph+1) - paragrahsLines.size() << endl;
        int toDo = (paragraph+1) - paragrahsLines.size();
        for(int i = 0; i < (toDo-1); i++)
        {
            vector<int> newRow;
            for(int j = 0; j <= 1; j++)
            {
                //newRow.push_back('\0');
                ;
            }
            paragrahsLines.push_back(newRow);
        }
        vector<int> newRow2;
        newRow2.push_back(line);
        paragrahsLines.push_back(newRow2);
        //cout << paragrahsLines[1][0] << endl;
    }
    else if( int((paragrahsLines.size()-1)) == paragraph )
    {
        //cout << paragrahsLines[1].size() << endl;
        paragrahsLines[paragraph].push_back(line);
        //cout << paragrahsLines[1][1] << endl;
    }
    else
    {
        throw RECORD_ERROR;
    }
}
/*
 template<typename T>
 bool node<T>::operator<(node<T> lhs, node<T> rhs)
 {
 if(isString())
 {
 return (toUpper(lhs->word) < toUpper(rhs->word));
 }
 else
 {
 return (lhs < rhs);
 }
 }
 
 template<typename T>
 bool node<T>::operator==(node<T> lhs, node<T> rhs)
 {
 if(isString())
 {
 return( toUpper(lhs->word) == toUpper(rhs->word) );
 }
 else
 return( lhs->word == rhs->word );
 
 }
 */

template<typename T>
bool node<T>::isString(T item)
{
    try
    {
        try
        {
            throw item;
        }
        catch(string x)
        {
            return true;
        }
    }
    catch(...)
    {
        return false;
    }
}

#endif // NODE_H
