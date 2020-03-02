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

void TrieNode::branchFind(TrieNode* root, const char* word, int k, int position, char letterNow, char nextLetter, char matchingWords[100][34], int error, char storage[37], int *count, int storagePos, char storage2[37]) {
    root = root->children[k]; // root equal to the child with the future letter
    int depth = 1; // create depth counter
    for (int j = position; (root->letters[(letterNow - 'a')]) && error < 2; j++) {
        if ((!(root->children[(nextLetter - 'a')]) && nextLetter != '\0')) {
            error++;
        } else {
//
//                if (*count > 0){
//                    storagePos = (*count * (strlen(word)) + position);
//                    storage[storagePos] = letterNow;
//
//                }
//                else {

            storage[j] = letterNow;
            // }
            if (!(nextLetter == '\0')) {
                root = (root->children[(nextLetter - 'a')]);
                depth++;
            }
            letterNow = word[j + 1];
            nextLetter = word[j + 2];
            position++;
            storagePos++;


        }

    }

    if (error == 2) {
        int b = strlen(storage2);
        if (b == 0){
            b++;
        }
        for (int i = storagePos; i > b; i--) {
            storage[i] = '\0';
            storagePos++;
        }

    } else {


//        *count = *count + 1;
//        std::strcpy(*matchingWords, storage);
        std::strcpy(matchingWords[*count], storage);
        ++*count;
        storagePos = position;
        int b = strlen(storage2);

        for (int i = storagePos; i >= b; i--) {
            storage[i] = '\0';
            storagePos++;
//
//            }
//            for (int i = 0; i < b; i++) {
//                storage[storagePos] = storage2[i];
//                storagePos++;
//
//            }



        }

        while ((root->parent) && depth > 0) { // resetting root to be at top of tree

            root = root->parent; // set root = parent of current node
            depth--;
        }

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
        newChild -> letters[i] = '\0';
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
                root -> insertchar(curLetter);

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
      char storage2[37];

      for (int i = 0; i<38; i++ ){
          storage[i] = '\0';
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
      int storagePos = 0;

      if (strcmp(word, "hyyochondria")==0){
          std::cout<<"TRUE";
      }

        if(!(root -> parent) && (root -> children[(currentLetter-'a')])){ // if there is no parent, move down a level to find the first letter

            root = root -> children[(currentLetter-'a')]; // root now equals child of first letter
        }


      for (int position = 0; (root->letters[(currentLetter - 'a')]) && error < 2; position++) { // going through all the letters in the word and incrementing errors, if any

          if ((!(root->children[(nextLetter - 'a')]) && nextLetter != '\0')) {
              error++;
              strcpy(storage2, storage);
              int curPos = position;
              storage[position] = currentLetter;
              position++;
              //storagePos = position;

              for (int k = 0; k < 28; k++) { // checking siblings
                  if ( (root->children[k])){// && ((root->children[k])->checkNextNode(futureLetter))) { //if other letter have future letter, could be a correction

                      char letterNow = (root -> children[k] -> letters[k]); //
                      //nextLetter = futureLetter;
                      //futureLetter = word[position + 3];
                      root -> branchFind(root, word, k, position, letterNow, futureLetter, matchingWords, error, storage, count, storagePos, storage2);

                          }
                      }

              root = root -> parent;
              position = curPos;
              for (int k = 0; k < 28; k++) { // checking siblings
                  if ( (root->children[k])){ //&& ((root->children[k])->checkNextNode( // if siblings child array has the future letter, go
                          //nextLetter))) { //if other letter have future letter, could be a correction

                      char letterNow = (root -> children[k] -> letters[k]); //
                      //nextLetter = futureLetter;
                      //futureLetter = word[position + 3];
                      root -> branchFind(root, word, k, position, letterNow, nextLetter, matchingWords, error, storage, count, storagePos, storage2);

                  }
                  storagePos++;
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

              if (currentLetter == '\0') { // noticing the end of a word
                  storage[position+1] = '\0'; // put NULL char in

                  storagePos = (position +2);
                  std::strcpy(matchingWords[*count], storage);
                  ++*count; // increment count
                  //std::strcpy(*matchingWords, storage);


                  break;
              }
          }
      }


          while (root->parent) { // resetting root to be at top of tree

              root = root->parent; // set root = parent of current node
          }

          if(*count == 0) {
              error = 0;

              nextLetter = word[1];
              futureLetter = word[2];
              for (int i = 0; i < 26; i++) { // checking for first letter errors
                  if((root->children[i])){ //-> checkNextNode(nextLetter))){ //&& (root -> children[i] -> children[(nextLetter - 'a')] -> checkNextNode(futureLetter))){ // check that they have the next and future letter before branch find
                      currentLetter = root ->  letters[i]; // set letter to new current letter
                      root -> branchFind(root, word, i, 0, currentLetter, nextLetter, matchingWords, error, storage, count, storagePos, storage2); // branch find

              }
          }
          }

           // std::strcpy(*matchingWords, storage);


          std::cout << "WORD: ";

         for (int i =0; i < 37; i++) {

              std::cout << storage[i];

          }
//
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
