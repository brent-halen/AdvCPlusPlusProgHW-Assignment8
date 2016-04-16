#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include "stdafx.h"
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);

	void push_back(T);	// New push_back member
	T pop_back();		// New pop_back member
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//***********************************************************
// The push_back function pushes its argument onto the back *
// of the vector.                                           *
//***********************************************************

template <class T>
void SimpleVector<T>::push_back(T val)
{
	// Allocate a new array 1 element larger than the current one.
	T *tempPtr = new T [arraySize + 1];

	// Copy the current array contents to the new array
	for(int count = 0; count < arraySize; count++)
		*(tempPtr + count) = *(aptr + count);

	// Copy the argument value to the end of the array
	*(tempPtr + arraySize) = val;

	// Get rid of the old array
	if (arraySize > 0)
		delete [] aptr;

	// Make aptr point to the new array
	aptr = tempPtr;

	// Adjust arraySize
	arraySize++;
}

//***********************************************************
// The pop_back function removes the last element           *
// of the vector. It also returns that value.               *
//***********************************************************

template <class T>
T SimpleVector<T>::pop_back()
{
	if (arraySize == 0)
		throw "ERROR: vector contains no values.\n";
	else
	{
		// Save the last value in the array
		T lastValue = aptr[arraySize - 1];

		// Allocate a new array 1 element smaller than the current one.
		T *tempPtr = new T [arraySize - 1];

		// Copy the current array contents (except the last element)
		// to the new array
		for(int count = 0; count < (arraySize - 1); count++)
			*(tempPtr + count) = *(aptr + count);

		// Get rid of the old array
		delete [] aptr;

		// Make aptr point to the new array
		aptr = tempPtr;

		// Adjust arraySize
		arraySize--;

		return lastValue;
	}
}

#endif