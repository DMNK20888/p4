// Author: Sean Davis

#include "CheckerRunner.h"
#include "checker.h"
#include "Trie.h"
//#include "TrieNode.h"


Checker::Checker(const DictionaryWord *words, int numWords) {

Trie object(); //initialize Trie object
//insert the words from dictionary into trie
  for(int wordcount = 0; wordcount <= numWords; wordcount++) {
    //insert word into trie
    object.insert(words[wordcount]); //insert word into trie object

  }

} // Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count) {



} // findWord()


