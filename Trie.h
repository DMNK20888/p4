//
// Created by Dominik Barlow on 2020-02-22.
//

#ifndef P4__TRIE_H_
#define P4__TRIE_H_

class Trie;
class TrieNode {

 protected:
  char *letters; //array holding letters in the alphabet and the null character
  TrieNode **children; // array holding pointers to each child
  TrieNode *parent;
  char letter;


 public:
  TrieNode(TrieNode* p); //issue of explicit?
  TrieNode* insert(char curLetter);
  void setParent(TrieNode *p);


  friend class Trie;
};




class Trie {
  //Member variables
  TrieNode* root;
  char word[37];
 public:
  Trie();
  bool isempty(TrieNode* children[27]);
  void insert(char word[37]);
};



#endif //P4__TRIE_H_
