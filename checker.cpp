// Author: Sean Davis

#include "CheckerRunner.h"
#include "checker.h"
#include "Trie.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
//#include "TrieNode.h"


Checker::Checker(const DictionaryWord *words, int numWords) {

    Trie tree; //initialize Trie tree
//insert the words from dictionary into trie
    for (int wordcount = 0; wordcount <= numWords; wordcount++) {
        //insert word into trie
        int size = sizeof((words[wordcount]));
        //char curword[37];
        //char word[37] = words[wordcount];

        //std::strcpy( -> word, word);
        //std::strcpy(curword,)
        std::cout<< words[wordcount].word;
        tree.insert(words[wordcount].word); //insert word into trie tree

        // }
//    char word[6];
//    word[0] = 'c';
//    word[1] = 'a';
//    word[2] = 't';
//    word[3] = 's';
//    word[4] = 'l';
//    word[5] = '\0';

//    tree.insert(word); //insert word into trie tree
    }
}// Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count) {



} // findWord()


