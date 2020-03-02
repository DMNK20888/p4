//
// Created by Dominik Barlow on 2020-02-22.
//

#ifndef P4__TRIE_H_
#define P4__TRIE_H_

#include "CheckerRunner.h"

class Trie;
class TrieNode {

 protected:
  char *letters; //array holding letters in the alphabet and the null character
  TrieNode **children; // array holding pointers to each child
  TrieNode *parent;



 public:
  TrieNode(TrieNode* p);
  void insertchar(char curLetter);
  void insertNULLChar();
  void setParent(TrieNode *p);
  bool checkNextNode(char futureLetter);
  bool checkRest();
  void branchFind(TrieNode* root, const char* word, int k, int pos, char currentLetter, char nextLetter, char matchingWords[100][34], int error, char storage[37], int *count, int storagePos, char storage2[37]);



  friend class Trie;
};




class Trie {
  //Member variables
  TrieNode* root;
  char word[37];
  char curLetter;
 public:
  Trie();
  bool isempty(TrieNode* children[27]);
  TrieNode* createChild();
  void insert(const char curword[34]);
  int* find(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count);


};



#endif //P4__TRIE_H_
