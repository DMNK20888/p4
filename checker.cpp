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

     tree = new Trie(); //initialize Trie tree
//insert the words from dictionary into trie
    for (int wordcount = 0; wordcount <= numWords; wordcount++) {

        tree -> insert(words[wordcount].word); //insert word into trie tree

    }
}// Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count) {

    tree -> find(word, matchingWords, count);

} // findWord()


