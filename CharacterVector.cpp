#ifndef __CHARACTER_VECTOR_CPP__
#define __CHARACTER_VECTOR_CPP__

#include "IntegerVector.h"
#include "DoubleVector.h"
#include "CharacterVector.h"
#include <stdexcept>

CharacterVector::CharacterVector()  {}
CharacterVector::~CharacterVector() {}

int CharacterVector::size() 
{  
   return characterVector.size();
}

// just return the character at the specified index; use the at() method rather
// than [] so that an out_of_range error will be thrown for an invalid index
char CharacterVector::get(int index) 
{ 
    int size =characterVector.size();
   if (index >= size)
   {   throw std::invalid_argument("Out of range");
   }
   return characterVector.at(index);
}

// if index is size-legitimate, put the value at that index;
// otherwise, use push_back to append to the end of the vector
void CharacterVector::put(char value, int index)
{	int size =characterVector.size();
	if (index < size)
	{
		characterVector.at(index) = value; // puts the value at that index if the index is size-legitimate

	}else
	{
		characterVector.push_back(value); // adds a new element at the end of the vector
	}
}

// use push_back to append
void CharacterVector::put(char value)
{
	characterVector.push_back(value);
}

// for each integer in integerVector, use static_cast<char> to append as a
// character to characterVector
void CharacterVector::appendIntegerVector(IntegerVector& integerVector)
{ 

        int size = integerVector.size();
        char iv;
	for (int i = 0; i < size; ++i)
	{       iv = static_cast<char>(integerVector.get(i));
                characterVector.push_back(iv);
//		characterVector.push_back(static_cast<char>(integerVector.get(i)));
	}
}

// for each double in doubleVector, use static_cast<char> to append as a
// character to characterVector
void CharacterVector::appendDoubleVector(DoubleVector& doubleVector)
{       int size = doubleVector.size();
        char dv;
	for (int i = 0; i < size; ++i)
	{
		dv = static_cast<char>(doubleVector.get(i));
                characterVector.push_back(dv);
//		characterVector.push_back(static_cast<char>(doubleVector.get(i)));

	}
}

#endif
