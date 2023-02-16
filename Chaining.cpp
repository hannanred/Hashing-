#ifndef CHAINING_CPP
#define CHAINING_CPP
#include "Chaining.h"
#include "HashFunction.cpp"
#include "LinkedList.cpp"
#include "LinkedList.h"
HashC::HashC(int size)
{

	tableSize = size;
	hashTable = NULL;
	hashTable = new LinkedList<string>[size]; //new array of linkedlists

}

unsigned long HashC :: hash(string input)
{

	return bitwiseHash(input); 
}

void HashC::insert(string word)
{
	// unsigned long i = hash(word);
	// i = divCompression(i,tableSize);
	hashTable[divCompression(hash(word),tableSize)].insertAtTail(word);
} 

ListItem<string>* HashC :: lookup(string word)
{
	// unsigned long i = hash(word);
	// i = divCompression(i,tableSize);
	// return hashTable[i].searchFor(word);
return hashTable[divCompression(hash(word),tableSize)].searchFor(word); //returns NULL if word not found
	
}
void HashC :: deleteWord(string word)
{
	
	
	//  unsigned long i = hash(word);
	//  i = divCompression(i,tableSize);
	//  if(hashTable[i].searchFor(word)==NULL){
	//  return;
	//  }		
	// else if(hashTable[i].searchFor(word)!=NULL){
	//  hashTable[i].deleteItem(word);
	//  }

	 hashTable[divCompression(hash(word),tableSize)].deleteItem(word); // if a word exists it deletes it

		
}

HashC::~HashC()
{
	for (int i = 0; i<tableSize;i++)
	{
		while(hashTable[i].getHead()!=NULL){
			hashTable[i].deleteTail();
		}
	}
	
	delete[] hashTable;

}


#endif
