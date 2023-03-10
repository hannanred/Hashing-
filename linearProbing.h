#include "linearProbing.cpp"
#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include <string>
#include <iostream>

using namespace std;
class block
{
    public:
        unsigned long key;
        string value;
        block(unsigned long _key,string _value)
        {
            this->key = _key;
            this->value = _value;
        }
};


class HashL{
    private:
        block** hashTable;
        long tableSize;
        unsigned long hash(string value); 
        void resizeTable();
        // count of the number of entries in the table.
        long count; 
    public:
        HashL();
        void insert(string value);
		void deleteWord(string value);
		block* lookup(string value);
        ~HashL();
};

#endif