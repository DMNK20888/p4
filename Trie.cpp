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


TrieNode* TrieNode::insertchar(char curLetter){ //somehow increment cur letter in word[ ]
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


} //Trie::Trie()

//bool Trie::isempty(TrieNode* children[27]){
//  if (children)
//}

TrieNode* Trie::createChild() {

    TrieNode* newChild = new TrieNode(root);

    return newChild;


}



void Trie::insert(char word[37]) {

    int pos = 0;
    TrieNode* node = root -> insertchar(word[pos]);


    while (word[pos] != '\0'){

    if(!(root -> children[word[pos] - 'a'])){

        root -> children[word[pos] - 'a'] = createChild();
        root = root -> children[word[pos] - 'a'];
    }
    else{
        root = root -> children[word[pos] - 'a'];
    }
        pos++;
    }
   

    
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


// Trie::insert()
