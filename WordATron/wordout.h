#ifndef WORDOUT_H
#define WORDOUT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "tree.h"
//#include "heap.h"

using namespace std;
#define fleschLevel(words,sentences,syllables) (206.835 - (1.015*(words/sentences)) - (84.6*(syllables/words)))
//#define oType node<T>

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
    //walk down the tree
    void traverse(node<T> *root);
    //void fillWithHeap(MinHeap<T> &aHeap);

    //node passing into vector
    void addNode(node<T> *aNode); // used by fillWithTree(tree aTree);
    void addNode(T item, int aParagraph, int aLine, int aSyllables); //  used by fillWithHeap(MinHeap aHeap);

    //Basic print functions
    void printWordCount(ostream &out);
    void printParagraphCount(ostream &out);
    void printReadingLevel(ostream &out);
    void printSentences(ostream &out);
    void printTopTen(ostream &out);
    void printTime(ostream &out);

    //UI print functions, what user will see
    void printSummary(ostream &out);//MUST PASS PARAMETER IN MAIN!!
                                    //IF TO FILE, FOLLOW THE STEPS IN my MAIN.CPP
                                    //
    //void printLetters(char aChar);//BUG comparing. operator==
    void printLetters(string aStr);//BUG comparing. operator==
    void printEverything();

    //SaveOut
    bool deleteFile();//If user chooses NOT to save the output file, call this function

    //privates accessors
    int totalWords();
    int totalSyllables();
    int totalSentences();
    string fileName();//returns 'WordList.txt'
    string getSummaryFile();//returns 'printSummary.txt'

    //converter for print letters
    string charConvert(char arg);//CONVERTS CHAR TO STRING

private:
    fstream fout;
    string outputFile, outputSummary;
    node<T> *wRoot;
    words<T> conv;
    float totalTime;
    int tWords;
    int tSyllables;
    int tSentences;

    vector< node<T>* > wordList;//Vector for TREE's nodes
    vector<T> heapList;
};

template<typename T>
WordOut<T>::WordOut()
{
    totalTime = 0.0;
    tWords = 0;
    tSyllables = 0;
    tSentences = 0;
    wRoot = NULL;
    outputFile = "WordList.txt";
    outputSummary = "PrintSummary.txt";
    fout.open(outputFile.c_str(), ios::out | ios::trunc);

}

template <typename T>
WordOut<T>::WordOut(int totalWords, int totalSentences)
{
    totalTime = 0.0;
    //tWords = 0;
    tSyllables = 0;
    //tSentences = 0;
    wRoot = NULL;
    tWords = totalWords;
    tSentences = totalSentences;
    outputFile = "WordList.txt";
    outputSummary = "PrintSummary.txt";
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
    traverse(aTree.getRoot());
}

template<typename T>
void WordOut<T>::traverse(node<T> *root)
{
    if(root)
    {
        if(root->lt)
            traverse(root->lt);
        //Add total syllables for the current node from the tree
        tSyllables += root->totalSyllables();
        tWords += root->wordCount;


        //wordList.push_back(root);
        //heapList.push_back(root->word);

        //Push in the tree's node
        addNode(root);
        if(root->gt)
            traverse(root->gt);
    }
    else
        return;
}

//void fillWithHeap(MinHeap<T> &aHeap)

template <typename T>
void WordOut<T>::addNode(node<T> *aNode)
{
    //
    wordList.push_back(aNode);
    //cout << "wordList[0]: " << wordList[0]->word<<endl;
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
     if( int(paragrahsLines.size()) == 0 || int((paragrahsLines.size()-1)) < paragraph )
     {
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
    }
    else if( int((paragrahsLines.size()-1)) == paragraph )
    {
      paragrahsLines[paragraph].push_back(line);
    }
    else
     {
         return;
     }
 }
 */
}

template <typename T>
void WordOut<T>::printWordCount(ostream &out)
{
    out << "Words: " << tWords << ". " << endl;
}

template <typename T>
void WordOut<T>::printParagraphCount(ostream &out)
{
    int para = 1000;
    out << "Paragraphs: " << para << "." << endl;
}

template <typename T>
void WordOut<T>::printReadingLevel(ostream &out)
{
    out << "Flesch Reading Ease: " << fleschLevel(tWords,tSentences,tSyllables) << "." << endl;
}

template <typename T>
void WordOut<T>::printTopTen(ostream &out)
{
    string temp = "The";
    out << "TOP TEN FREQUENTLY MOST USED WORDS:\n";
    for(int i = 0; i < 10; i++)
        out << "     " << temp << endl;
}

template <typename T>
void WordOut<T>::printTime(ostream &out)
{
    out << "Run Time: " << totalTime << "ms. " << endl;
}

template<typename T>
string WordOut<T>::getSummaryFile()
{
    return outputSummary;
}

template <typename T>
void WordOut<T>::printSummary(ostream &out)
{
        out << "*** A Caskash Production (2011) ***\n";
        out << "        printSummary.txt           \n\n";

        //printReadingLevel(out);//CAUTION if parameters for this are not set, divide by zero error == CRASH!
        printWordCount(out);
        printParagraphCount(out);
        printSentences(out);
        printTime(out);
        printTopTen(out);
        out << "\n***********************************\n";
}

template<typename T>
void WordOut<T>::printSentences(ostream &out)
{
    out << "Sentences: " << totalSentences() << ". " << endl;
}

template <typename T>
void WordOut<T>::printLetters(string aStr)
{
    
    string temp, temp2;
     aStr[0]=toupper(aStr[0]);
    for(int i = 0; i < int(wordList.size()); i++)
    {
        temp = wordList[i]->word;
        temp2 = temp[0];
        if(temp2 == aStr )
        {
            wordList[i]->print(cout);
        }
    }
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

template<typename T>
string WordOut<T>::charConvert(char arg)
{
     stringstream sstr;
     string str;

     sstr << arg;
     sstr >> str;

     return str;
}

template<typename T>
void WordOut<T>::printEverything()
{
    for(int i = 0; i < int(wordList.size()); i++)
    {
        wordList[i]->print(fout);
    }
    fout.close();
}

#endif //WORDOUT_H
