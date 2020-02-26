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


void TrieNode::insertchar(char curLetter){ //somehow increment cur letter in word[ ]

        int index = curLetter - 'a'; //getting correct index
        letters[index] = curLetter; // inserting letter at correct index

} //TrieNode insert()


void TrieNode::insertNULLChar() {

        letters[27] = '\0'; // insert null char at 27th position in letters

}

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

    TrieNode* newChild = new TrieNode(root); // create a new node with the parent as the current root
    for (int i = 0; i < 29; i++){ // set all children pointers = NULL
        newChild -> children[i] = NULL;
    }

    return newChild; // return Child


}



void Trie::insert(const char curword[34]) {

    int pos = 0;
    int Level = 0;
    int NewNodes = 0;

    std::strcpy(this -> word, curword);

    std::cout<< "CURRENT WORD: " << word << std::endl; // Printing out current word

    while (word[pos] != '\0'){ // insert / go through nodes until we reach end of word
        char curLetter = word[pos];  //setting the curLetter = the current letter
        char nextLetter = word[pos+1];
        root -> insertchar(curLetter); //inserting the current letter into the root
        std::cout<< "TEST: " << curLetter << " = " <<  root -> letters[curLetter - 'a']<< std::endl; // testing

        if(nextLetter == '\0'){
            break;
        }

    if(!(root -> children[(nextLetter - 'a')])){ //if pointer doesn't exist for current letter, make a child

        root -> children[(nextLetter - 'a')] = createChild(); // create a new child and have the children array at correct index point to it
        root = root -> children[(nextLetter - 'a')]; // set root = newChild
        Level++; //increment level
        NewNodes++; //increment # NewNodes

    }
    else{
        root = root -> children[(nextLetter - 'a')]; // if pointer exists, root equals child node
        Level++; // increment level
    }
        pos++; // go to next letter in char array
    } // END OF WHILE

        root -> children[27] = createChild(); // creating a child for the NULL Char
        root = root -> children[27]; // moving to the NULL Char Child
        root -> insertNULLChar(); // inserting NULL Char
        Level++; // increment level

        std:: cout << "# OF NEW NODES: " << NewNodes << std::endl; // TEST
        std:: cout << "LEVEL OF TRIE: " << Level << std::endl; // TEST



    while(root -> parent){ // resetting root to be at top of tree

        root = root -> parent; // set root = parent of current node
    }


    
  }




