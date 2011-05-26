#ifndef WORDOUT_H
#define WORDOUT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include "tree.h"
//#include "heap.h"

using namespace std;
#define fleschLevel(words,sentences,syllables) (206.835 - (1.015*(words/sentences)) - (84.6*(syllables/words)))
#define oType node<T>

template <typename T>
class WordOut
{
public:
    WordOut(int tWords, int totSentences);
    WordOut();
    ~WordOut();
    
    //Basic setters
    void setTime(float theTime);
    void setTotalSyllables(int totSyllables);
    
    //object manipulation
    void fillWithTree(tree<T> &aTree);
    //void fillWithHeap(MinHeap<T> &aHeap);
    
    //node passing into vector
    void addNode(oType &aNode); // used by fillWithTree(tree aTree);
    void addNode(T item, int aParagraph, int aLine, int aSyllables); //  used by fillWithHeap(MinHeap aHeap);
    
    //Basic print functions
    void printWordCount();
    void printParagraphCount();
    void printReadingLevel();
    void printSentences();
    void printTopTen();
    void printTime();
    
    //UI print functions, what user will see
    void printSummary();
    void printLetters(char aChar);
    
    //SaveOut
    bool deleteFile();
    
    //privates accessors
    int totalWords();
    int totalSyllables();
    int totalSentences();
    string fileName();
    
private:
    fstream fout;
    string outputFile;
    node<T> *wRoot;
    float totalTime;
    int tWords;
    int tSyllables;
    int tSentences;
    
    vector<oType> wordList;
    vector<T> heapList;
};

template<typename T>
WordOut<T>::WordOut()
{
    wRoot = NULL;
    outputFile = "WordList.txt";
    fout.open(outputFile.c_str(), ios::out | ios::trunc);
}

template <typename T>
WordOut<T>::WordOut(int totalWords, int totalSentences)
{
    wRoot = NULL;
    tWords = totalWords;
    tSentences = totalSentences;
    outputFile = "WordList.txt";
    fout.open(outputFile.c_str(), ios::out | ios::trunc);
}

template<typename T>
WordOut<T>::~WordOut()
{
    wordList.clear();
    fout.close();
}

template <typename T>
void WordOut<T>::setTime(float theTime)
{
    totalTime = theTime;
}

template <typename T>
void WordOut<T>::setTotalSyllables(int totSyllables)
{
    tSyllables = totSyllables;
}

template<typename T>
string WordOut<T>::fileName()
{
    return outputFile;
}

template <typename T>
void WordOut<T>::fillWithTree(tree<T> &aTree)
{

    if(!wRoot)
        wRoot = aTree.getRoot();
    if(wRoot)
    {
        if(wRoot->lt)
            inOrder(wRoot->lt);
        //root->print();//insertion
        addNode(wRoot);
        if(wRoot->gt)
            inOrder(wRoot->gt);
    }
    else
        return;

 }

//void fillWithHeap(MinHeap<T> &aHeap)

template <typename T>
void WordOut<T>::addNode(node<T> &aNode)
{
    wordList.push_back(aNode);
}

template <typename T>
void WordOut<T>::addNode(T item, int aParagraph, int aLine, int aSyllables)
{
    //if (!findNode(item))
    {
        //
    }
    
    /*
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
     throw return;
     }
     }
     */
}

template <typename T>
void WordOut<T>::printWordCount()
{
    fout << "Total words: " << tWords << ". " << endl;
}

template <typename T>
void WordOut<T>::printParagraphCount()
{
    //
}

template <typename T>
void WordOut<T>::printReadingLevel()
{
    fout << "Flesch Reading Ease: " << fleschLevel(tWords,tSentences,tSyllables) << " " << endl;
}

template <typename T>
void WordOut<T>::printTopTen()
{
    //
}

template <typename T>
void WordOut<T>::printTime()
{
    fout << "Run Time: " << totalTime << "sec. " << endl;
}

template <typename T>
void WordOut<T>::printSummary()
{
    fout << "*** A Caskash Production (2011) ***\n";
    fout << "          "<<fileName()<<"           \n";
    printReadingLevel();
    printWordCount();
    printParagraphCount();
    printSentences();
    printTopTen();
    printTime();
}

template<typename T>
void WordOut<T>::printSentences()
{
    fout << "Number of sentences: " << totalSentences() << ". " << endl;
}

template <typename T>
void WordOut<T>::printLetters(char aChar)
{
    //
}

template <typename T>
bool WordOut<T>::deleteFile()
{
    if( remove(outputFile.c_str()) != 0 )
        return false;
    return true;
}

template <typename T>
int WordOut<T>::totalWords()
{
    return tWords;
}

template <typename T>
int WordOut<T>::totalSyllables()
{
    return tSyllables;
}

template <typename T>
int WordOut<T>::totalSentences()
{
    return tSentences;
}

#endif //WORDOUT_H
