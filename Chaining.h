#include "Chaining.cpp"
#ifndef CHAINING__H
#define CHAINING__H
#include <string>
#include "LinkedList.cpp"
#include "LinkedList.h"
using namespace std;
class HashC
{
	private:
		long tableSize;
		LinkedList<string>* hashTable;
		unsigned long hash(string input); 
		
	public:
		HashC(int);
		void insert(string word); 
		void deleteWord(string word);
		ListItem<string>* lookup(string word);
		~HashC(); 
};
#endif
