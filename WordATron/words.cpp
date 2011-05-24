#include "words.h"

words::words()
{
    outputFile = "WordList.txt";
}

words::words(string fileName)
{
    title = fileName;
    outputFile = "WordList.txt";
    openFile(fileName);
}

words::~words()
{
    preWordList.clear();
    sortedWordList.clear();
    noRepsList.clear();
    //TODO fix this BAD_ACCESER
    //deLinkList();
}

void words::deLinkList()
{
     nodetype *current, *tmp;
    //TODO fix this BAD_ACCESER
     current = start->ptr;
     start->ptr = NULL;
    while(current != NULL)
    {
        tmp = current->ptr;
        delete(current);
        current = tmp;
    }
}

void words::initLinkList()
{    
    string info;

    start = new nodetype;
    start->ptr = NULL;
    last = start;
    //cout << "noRepsList.size(): " << noRepsList.size() << endl;

    for (vector<string>::iterator i = noRepsList.begin(); i != noRepsList.end(); ++i)
    {
        info = *i;

        newnode = new nodetype;
        newnode->data = info;
        newnode->ptr = NULL;
        last->ptr = newnode;
        last = newnode;
    }
    sort();
}

bool words::deleteFile()
{
    if( remove(outputFile.c_str()) != 0 )
        return false;
    return true;
}

void words::openFile(string fileName)//CHANGE FILE PATH FOR OUTSIDE USE
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

void words::print()
{
    writeSortedListToFile();
}

void words::writeSortedListToFile()
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
                 cout << sortedWordList[i].c_str() << endl;
             }
    }
    out.close();
}

void words::delRepeatsPreWordList()
{
    bool found = false;

    noRepsList.push_back(preWordList[0]);
    //create a node with the word and incrememnt count here...
    for(vector<string>::iterator k = preWordList.begin(); k != preWordList.end(); ++k)
    {
        for (vector<string>::iterator i = noRepsList.begin(); i != noRepsList.end(); ++i)
        {
            if(stoupper(*k) == stoupper(*i))
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
            noRepsList.push_back(*k);
        }
    }
    initLinkList();
}

int words::wordCount()
{
    return sortedWordList.size();
}

string words::stoupper(string &str)
{
    string temp;
      for(unsigned int i = 0; i < str.length(); i++)
      {
          temp += toupper(str[i]);
          //cout << "temp: " << temp << endl;
      }
      return temp;
}

void words::sort()
{
    nodetype *next, *temp;

    last = start->ptr;
    while(last != NULL)
    {
        next = last;
        while(next != NULL)
        {
            if( stoupper(last->data) > stoupper(next->data) )
            {
                temp = new nodetype;
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

bool words::search(string key, int list)//preWordList = 1, sortedWordList = 2;
{
    bool found = false;

    switch(list)
    {
    case 1: //search preWordList
    {
        for (vector<string>::iterator i = preWordList.begin(); i != preWordList.end(); ++i)
        {
            if(stoupper(key) == stoupper(*i))
            {
                cout << "key: " << key << endl << "*i: " << *i << endl;
                found = true;
                break;
            }
            else
                found = false;
        }
        return found;
        break;
    }

    case 2: //search sortedWordList
            find(key);
            break;
    default:
            return false;
            break;
    }
}

bool words::find(string key)
{
    nodetype *current = new nodetype;
/*
    current = start->ptr;
    while(current != NULL && stoupper(key) != stoupper(current->data))
        current = current->ptr;
    if(current == NULL)
    {
        delete entry;
         return false;
    }
    */
    return true;
}

void words::push(string word)
{
    preWordList.push_back(word.c_str());
}

void words::pop(string word)
{
    for (vector<string>::iterator i = sortedWordList.begin(); i != sortedWordList.end(); ++i)
    {
        if(*i == word)
            sortedWordList.erase(i);
    }
}



