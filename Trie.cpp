//
// Created by Dominik Barlow on 2020-02-22.
//
#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

// Constructor
TrieNode::TrieNode(TrieNode* p): parent(p)
{
  children = new TrieNode* [27];
  letters = new char [27];
  //letters[curLetter - 'a'] = curLetter; //when a new Node is created the current letter is inserted into the array

} //TrieNode()


TrieNode* TrieNode::insert(char curLetter){ //somehow increment cur letter in word[ ]
  letters[curLetter - 'a'] = curLetter;

  return NULL;
} //TrieNode insert()


void TrieNode::setParent(TrieNode * p) {
  parent = p;
} //setParent()




//****Trie Class******************************************************************


//Constructor
Trie::Trie() //maybe needs max height max something???? like BTree has
{

  root = new TrieNode(NULL);
  //insert(word);

} //Trie::Trie()

//bool Trie::isempty(TrieNode* children[27]){
//  if (children)
//}



void Trie::insert(char word[37]) {

  if((root->children).empty()){
    
  }









//  TrieNode* node = root -> insert(word[0]); //insert letter into root
//  TrieNode* newRoot = NULL;
//  if(node) {
//    newRoot = new TrieNode(NULL);
//    newRoot -> insert(root);
//    newRoot -> insert(node);
//    root = newRoot;
//  }






//  if(!(root -> children[word[0]-'a'])){ //if first pointer of word is not in root
//    //create new Node
//    TrieNode* child = new TrieNode(root);

  //}


}// Trie::insert()
