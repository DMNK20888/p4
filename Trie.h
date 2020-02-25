//
// Created by Dominik Barlow on 2020-02-22.
//

#ifndef P4__TRIE_H_
#define P4__TRIE_H_

class Trie;
class TrieNode {

 protected:
  char letters [27]; //array holding letters in the alphabet and the null character
  TrieNode *children [27]; // array holding pointers to each child
  TrieNode *parent;
  char letter;
  TrieNode* child;
 public:
  TrieNode(char curLetter, TrieNode* p, char letters, TrieNode* children);
  void setParent(TrieNode *p);

  friend class Trie;
};




class Trie {
  //Member variables
  TrieNode* root;

  //char word[37];
 public:
  Trie(char word[37]);
  void insert(char word[37]);
};





#endif //P4__TRIE_H_
