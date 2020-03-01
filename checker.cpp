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

//     tree = new Trie(); //initialize Trie tree
////insert the words from dictionary into trie


    for (int i = 0; i < 35; i++){ // creating a Trie for each word length
        tree = new Trie();
        array[i] = tree;

    }

    for (int wordcount = 0; wordcount <= numWords; wordcount++) { // inserting words into tries based on word length
      //std::cout << strlen(words[wordcount].word) << std::endl;
        int wordLength = strlen(words[wordcount].word);
        array[wordLength] -> insert(words[wordcount].word); //insert word into trie tree
//
    }






}// Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count) {

    int wordLength = strlen(word);
       array[wordLength] -> find(word, matchingWords, count);


} // findWord()


