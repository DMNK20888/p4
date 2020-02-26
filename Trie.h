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
  TrieNode* insertchar(char curLetter);
  void setParent(TrieNode *p);


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
};



#endif //P4__TRIE_H_
