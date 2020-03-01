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

bool TrieNode::checkNextNode(char futureLetter){

    int index = (futureLetter - 'a');
    if (children[index]){

        return true;
    }
    else{
        return false;
    }

}

void TrieNode::branchFind(TrieNode* root, const char* word, int k, int position, char letterNow, char nextLetter, char matchingWords[100][34], int error, char storage[37], int *count) {
    root = root->children[k]; // root equal to the child with the future letter
    int depth = 1; // create depth counter
    for (int j = position; (root->letters[(letterNow - 'a')]) && error < 2; j++) {
        if ((!(root->children[(nextLetter - 'a')]) && nextLetter != '\0')) {
            error++;
        } else {
            storage[j] = letterNow;
            if (!(nextLetter == '\0')) {
                root = (root->children[(nextLetter - 'a')]);
                depth++;
            }
            letterNow = word[j + 1];
            nextLetter = word[j + 2];
            //futureLetter = word[j + 3];
            position++;
        }
    }
        if (error == 2){
            int reduce = (position - depth) ;
            //int curPos = position + reduce;
            for (int changeNum = 0; changeNum < (reduce-1); changeNum++){

                storage[position-1] = '\0';
                position--;
            }

        }
        else {
            std::strcpy(*matchingWords, storage);
            *count = *count +1;
            storage[position] = ',';
            position++;
        }

            while ((root->parent) && depth > 0) { // resetting root to be at top of tree

                root = root->parent; // set root = parent of current node
                depth--;
            }

        }



//bool TrieNode::checkRest() {
//
//    if (letters[currentLetter] && root->children[nextLetter]) {
//        root = root->children[nextLetter];
//        storage[pos] = currentLetter;
//
//}




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
        newChild -> letters[i] = NULL;
    }
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

   // std::cout<< "CURRENT WORD: " << word << std::endl; // Printing out current word


    while (word[pos] != '\0'){ // insert / go through nodes until we reach end of word
        char curLetter = word[pos];  //setting the curLetter = the current letter
        char nextLetter = word[pos+1];
        if(!(root->parent)){
            if(!(root->children[(curLetter-'a')])){ // if no child with starting letter
                (root -> children[(curLetter-'a')]) = createChild(); // create one

            }
            root = root -> children[(curLetter-'a')]; // set root equal to new child
        }
        root -> insertchar(curLetter); //inserting the current letter into the root
   //     std::cout<< "TEST: " << curLetter << " = " <<  root -> letters[curLetter - 'a']<< std::endl; // testing

        if(nextLetter == '\0'){
            break;
        }

    if(!(root -> children[(nextLetter - 'a')])){ //if pointer doesn't exist for current letter, make a child

        root -> children[(nextLetter - 'a')] = createChild(); // create a new child and have the children array at correct index point to it
        //std::cout<< "TEST: " << nextLetter << " = " <<  root -> letters[curLetter - 'a']<< std::endl;
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

//        std:: cout << "# OF NEW NODES: " << NewNodes << std::endl; // TEST
//        std:: cout << "LEVEL OF TRIE: " << Level << std::endl; // TEST



    while(root -> parent){ // resetting root to be at top of tree

        root = root -> parent; // set root = parent of current node
    }


    
  } // END OF INSERT


  int* Trie::find(const char *word, char matchingWords[100][MAX_LENGTH + 1], int *count) {
      *count = 0;
      int pos = 0;
      int counter = 0;
      char storage[37];

      for (int i = 0; i<38; i++ ){
          storage[i] = NULL;
      }

      std::cout << "CURRENT WORD: " << word << std::endl;
      //std::cout<< ;

      // while(word[pos] != '\0') {
      int checker = 0;
      //int pos = 0;
      int error = 0;
      char currentLetter = word[pos];
      char nextLetter = word[pos + 1];
      char futureLetter = word[pos + 2];

        if(!(root -> parent)){

            root = root -> children[(currentLetter-'a')];
        }
      for (int position = 0; (root->letters[(currentLetter - 'a')]) && error < 2; position++) {

          if ((!(root->children[(nextLetter - 'a')]) && nextLetter != '\0')) {
              error++;
              storage[position] = currentLetter;
              position++;
              for (int k = 0; k < 28; k++) { // checking siblings
                  if ( (root->children[k]) && ((root->children[k])->checkNextNode( // if siblings child array has the future letter, go
                          futureLetter))) { //if other letter have future letter, could be a correction

                      char letterNow = (root -> children[k] -> letters[k]); //
                      nextLetter = futureLetter;
                      //futureLetter = word[position + 3];
                      root -> branchFind(root, word, k, position, letterNow, nextLetter, matchingWords, error, storage, count);

                          }
                      }
              break;


              } else {
              storage[position] = currentLetter;
              if (!(nextLetter == '\0')) {
                  root = (root->children[(nextLetter - 'a')]);
                  //pos++;

              }
              currentLetter = word[position + 1]; // rotating through to next letter
              nextLetter = word[position + 2];
              futureLetter = word[position + 3];

              if (currentLetter == '\0') {
                  storage[position+1] = '\0';
                  std::strcpy(*matchingWords, storage);
                  *count = *count +1;
                  break;
              }
          }
      }


          while (root->parent) { // resetting root to be at top of tree

              root = root->parent; // set root = parent of current node
          }

          if(*count == 0){


          }




          std::cout << "WORD: ";
          int i = 0;
          while(storage[i] != '\0') {

              std::cout << storage[i];
              i++;
          }

          std::cout << std::endl;

          //if (strcmp(storage, word) == 0) {
              //std::strcpy(matchingWords, storage);
          //}
          //count = &counter;

          return count;


      }







//        } else if (root->children[nextLetter]) {
//            count++; //found an error
//            root = root->children[nextLetter];
