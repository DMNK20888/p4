//
// Created by Dominik Barlow on 2020-02-22.
//
#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

// Constructor
TrieNode::TrieNode(char curLetter, TrieNode* p, char letters[27], TrieNode* children[27]): letter(curLetter), parent(p), child(children)
{

  letters[curLetter - 'a'] = curLetter; //when a new Node is created the current letter is inserted into the array
  //set parent?

} //TrieNode()

void TrieNode::setParent(TrieNode * p) {
  parent = p;
}





//Constructor
Trie::Trie(char word[37])
{
  root = new TrieNode(word[37]);
  insert(word);

} //Trie::Trie()




void Trie::insert(char word[37]) {








}// Trie::insert()
