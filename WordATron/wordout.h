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
#include "AWord.h"
//#include "heap.h"

using namespace std;
#define fleschLevel(words,sentences,syllables) (0.39*(words/sentences) + (11.8*(syllables/words)) - 15.59)

template <typename T>
class WordOut
{
public:
    WordOut(int tWords, int totSentences, int toParag);
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
    void clear();
    void setMostFrequent(string aStr);
    
private:
    //fstream fout;
    string outputFile, outputSummary, prevHeapItem;
    node<T> *wRoot;
    words<T> oWords;
    float totalTime;
    int tWords;
    int tSyllables;
    int tempSyllables;
    int tSentences;
    int para;
    
    vector< node<T>* > wordList;//Vector for TREE's nodes
    vector< AWORD* > heapList;
    vector<string> mostFrequent;
};

template<typename T>
WordOut<T>::WordOut()
{
    prevHeapItem = "";
    tempSyllables = 0;
    para = 0;
    totalTime = 0.0;
    tWords = 0;
    tSyllables = 0;
    tSentences = 0;
    wRoot = NULL;
    outputFile = "WordList.txt";
    outputSummary = "PrintSummary.txt";
    //fout.open(outputFile.c_str(), ios::out | ios::trunc);
    
}

template <typename T>
WordOut<T>::WordOut(int totalWords, int totalSentences)
{
    prevHeapItem = "";
    tempSyllables = 0;
    totalTime = 0.0;
    para = 0;
    tSyllables = 0;
    wRoot = NULL;
    tWords = totalWords;
    tSentences = totalSentences;
    outputFile = "WordList.txt";
    outputSummary = "PrintSummary.txt";
    //fout.open(outputFile.c_str(), ios::out | ios::trunc);
}

template <typename T>
WordOut<T>::WordOut(int totalWords, int totalSentences, int toParag)
{
    totalTime = 0.0;
    tSyllables = 0;
    wRoot = NULL;
    para = toParag;
    tWords = totalWords;
    tSentences = totalSentences;
    outputFile = "WordList.txt";
    outputSummary = "PrintSummary.txt";
    //fout.open(outputFile.c_str(), ios::out | ios::trunc);
}

template<typename T>
WordOut<T>::~WordOut()
{
    wordList.clear();
    heapList.clear();
    //fout.close();
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
    if (oWords.stoupper(item) != oWords.stoupper(prevHeapItem))
    {
        tempSyllables = aSyllables;
        tSyllables += aSyllables;
        node<T> *saveMe = new node<T>;
        saveMe->word = item;
        saveMe->wordCounts();
        saveMe->update(aParagraph,aLine,aSyllables);
        wordList.push_back(saveMe);
        delete saveMe;
        
        AWORD *pushMe = new AWORD;
        pushMe->str = item;
        pushMe->frequency++;
        pushMe->syllables = tempSyllables;
        pushMe->paratraph.push_back(aParagraph);
        pushMe->line.push_back(aLine);
        prevHeapItem = item;
        heapList.push_back(pushMe);
        delete pushMe;
    }
    else
    {
        int position = int(heapList.size()-1);
        heapList[position]->frequency++;
        heapList[position]->syllables += tempSyllables;
        tSyllables += aSyllables;
        heapList[position]->paratraph.push_back(aParagraph);
        wordList[position]->wordCounts();
        heapList[position]->line.push_back(aLine);
    }
    //cout << "heapList[0]: " << heapList[0]->str << endl;
}

template<typename T>
void WordOut<T>::clear()
{
    wordList.clear();
}

template <typename T>
void WordOut<T>::printWordCount(ostream &out)
{
    out << "Words: " << tWords << ". " << endl;
}

template <typename T>
void WordOut<T>::printParagraphCount(ostream &out)
{
    out << "Paragraphs: " << para << "." << endl;
}

template <typename T>
void WordOut<T>::printReadingLevel(ostream &out)
{
    out << "Flesch Reading Level: " << fleschLevel(tWords,tSentences,tSyllables) << "." << endl;
}

template <typename T>
void WordOut<T>::printTopTen(ostream &out)
{
    string temp = "The";
    out << "TOP TEN FREQUENTLY MOST USED WORDS:\n";
    for(int i = 0; i < mostFrequent.size(); i++) {
        out << mostFrequent[i] << ", ";
    }
    out << endl;
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
    
    printReadingLevel(out);//CAUTION if parameters for this are not set, divide by zero error == CRASH!
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
    for(int i = 0; i < int(wordList.size()); i++)
    {
        temp = wordList[i]->word;
        temp2 = temp[0];
        if(oWords.stoupper(temp2) == oWords.stoupper(aStr) )
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
    fstream fout;
    fout.open(outputFile.c_str(), ios::out | ios::trunc);
    for(int i = 0; i < int(wordList.size()); i++)
    {
        wordList[i]->print(fout);
    }
    fout.close();
    wordList.clear();
}
template<typename T>
void WordOut<T>::setMostFrequent(string aStr) {
    mostFrequent.push_back(aStr);
}

#endif //WORDOUT_H
