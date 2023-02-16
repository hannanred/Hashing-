#ifndef LINEARPROBING_CPP
#define LINEARPROBING_CPP

#include "linearProbing.h"
#include "HashFunction.cpp"

// do not change the value of the tableSize
HashL::HashL()
{
   
    tableSize = 1000; 
    hashTable = new block*[tableSize]; //declaration
    for(int i = 0;i<tableSize;i++)
    {
        hashTable[i] = NULL; //initializing each element to NULL
    }
    count = 0; //global variable used to calculate load factor
   
}

HashL::~HashL()
{
    delete[] hashTable;
}

unsigned long HashL :: hash(string value)
{
    return bitwiseHash(value);
}

void HashL::resizeTable()
{
    if(count/tableSize>0.5) // if load factor is too great
    {
        block** hashTable2; //hashtable used for resizing
        long tableSize2 = tableSize;
        tableSize=tableSize*10; // increase old table size by 10 times
        hashTable2 = new block*[tableSize]; //a new table is made using the new table size
        int p = 0;
        for (int i = 0; i <tableSize; i++)
        {
            hashTable2[i]=NULL; //initializing each of its element to NULL
       
        }
        for(int i = 0;i<tableSize2;i++) //loop to send elements of the original hashtable to the new one
        {
            if(hashTable[i]!=NULL and hashTable[i]->key!=1) // This condition will remove deleted elements from the original hashtable 
            {
            unsigned long temp = hash(hashTable[i]->value);
            temp = divCompression(temp,tableSize);
            unsigned long p = 0;
           
            while(hashTable2[divCompression((temp+p),tableSize)] !=NULL)
             {
               p++; //loop until you find an empty place in the new hashtable
               
           }
            hashTable2[divCompression((temp+p),tableSize)] = hashTable[i];
           
        }
    }
    delete[] hashTable;
      hashTable = hashTable2;
    }
}

void HashL::insert(string value)
 {
    unsigned long temp = hash(value);
    unsigned long p = 0;
   
     while(hashTable[divCompression((temp+p),tableSize)] !=NULL) // Finding a NULL element or a deleted element
             {
               p++;
             }
   
    block *temp2 = new block(0,value);
    hashTable[divCompression((temp+p),tableSize)] = temp2;
    
    count++; //incrementing global count
    resizeTable();
    
}
void HashL::deleteWord(string value)
{
	block* x = lookup(value);
	if(x!= NULL)
	{
		x->key=1; //1 key represents that the value is deleted, 0 key represents that the value is still here
	}

    count--; //decrementing global count
}

block* HashL::lookup(string value)
{
	block* x;
	unsigned long temp = hash(value);
	unsigned long p = 0;
	while(hashTable[divCompression((temp+p),tableSize)]->value != value and divCompression((temp+p),tableSize)!= tableSize)
	{
	  p++; //loop until you find the word youre looking for, or until you reach the end of table
	
	}
	if(hashTable[divCompression((temp+p),tableSize)]!= NULL and hashTable[divCompression((temp+p),tableSize)]->value == value and hashTable[divCompression((temp+p),tableSize)]->key ==0)
{
	x= hashTable[divCompression((temp+p),tableSize)]; //if an element exists, its value matches the lookup value and it is not deleted
}
	else if(hashTable[divCompression((temp+p),tableSize)]==NULL or hashTable[divCompression((temp+p),tableSize)]->key == 1)
	{
	x= NULL; //If no element exists at the index or the value of the key is 1 (meaning its deleted)
	}
	return x;
}

#endif
