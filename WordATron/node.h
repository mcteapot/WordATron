#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

enum errors//node errors
{
    RECORD_ERROR, NO_DATA
};

template<typename T>
struct node
{
    node();
    node(T data);
    ~node();

    T word;
    int wordCount;
    int syllables;
    vector< vector<int> > paragrahsLines;

    bool isLeaf();
    bool isString(T item);
    void update(int paragraph, int line);

    node *lt, *gt;
 };


 template<typename T>
 node<T>::node()
 {
     wordCount = 0;
     lt = NULL;
     gt = NULL;
 }

 template<typename T>
 node<T>::node(T data)//look over! possible issues with counter
 {
     word = data;
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
 void node<T>::update(int paragraph, int line)
 {
     //cout << "paragrahsLines.size()-1:" << paragrahsLines.size()-1 << endl;
     if( paragrahsLines.size() == 0 || (paragrahsLines.size()-1) < paragraph )
     {
         //cout << "toDo: " << (paragraph+1) - paragrahsLines.size() << endl;
         int toDo = (paragraph+1) - paragrahsLines.size();
        for(int i = 0; i < (toDo-1); i++)
        {
            vector<int> newRow;
                for(int j = 0; j <= 1; j++)
                {
                    newRow.push_back(-1);
                }
            paragrahsLines.push_back(newRow);
        }
        vector<int> newRow2;
        newRow2.push_back(line);
        paragrahsLines.push_back(newRow2);
        //cout << paragrahsLines[1][0] << endl;
    }
    else if( (paragrahsLines.size()-1) == paragraph )
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

 template<typename T>
 bool node<T>::isLeaf()
 {
     return ( (lt == NULL) && (gt ==NULL) );
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
