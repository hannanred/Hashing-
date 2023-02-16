#ifndef HASHFUNCTIONS_CPP
#define HASHFUNCTIONS_CPP
#include <cmath>
#include <string>
#include <iostream>

using namespace std;


unsigned long bitwiseHash(string value)
{
	unsigned long bitwiseHash = 0;

	int length = value.length();

	for(int i = 0;i<length;i++)
	{
			
		bitwiseHash=bitwiseHash^((bitwiseHash<<5)+(bitwiseHash>>2)+value[i]);
	}
	return bitwiseHash;
}


unsigned long divCompression(unsigned long hash, long tableSize)
{
	return hash%tableSize;
}

#endif