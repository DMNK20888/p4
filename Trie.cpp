//
// Created by Dominik Barlow on 2020-02-22.
//
#include <iostream>
#include <fstream>
#include <cstring>
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
    int index = curLetter - 'a';
  letters[index] = curLetter;

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



void Trie::insert(const char curword[34]) {

    int pos = 0;
    int totalNodes = 1;

    std::strcpy(this -> word, curword);

    std::cout<< "CURRENT WORD: " << word << std::endl;

    while (word[pos] != '\0'){
        char curLetter = word[pos];
        root -> insertchar(curLetter);
        std::cout<< "TEST: " << curLetter << " = " <<  root -> letters[pos]<< std::endl;


    if(!(root -> children[(curLetter - 'a')])){

        root -> children[(curLetter - 'a')] = createChild();
        root = root -> children[(curLetter - 'a')];
        totalNodes++;

    }
    else{
        root = root -> children[(curLetter - 'a')];
    }
        pos++;
    }
    while(root -> parent){

        root = root -> parent;
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
