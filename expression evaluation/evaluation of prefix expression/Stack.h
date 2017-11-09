#include <iostream>
#include <cstdlib>
using namespace std;

#include "StackEmpty.h"
#include "StackFull.h"


template < class T >
class Stack
{
	private:

		T * stackPtr;
		int size;
		int top;

	public:

		Stack ( int = 100 );

		void push ( const T & );
		T pop ( ) ;

		int isFull ( ) const;
		int isEmpty ( ) const;

		T stackTop ( ) const;
		int getCapacity ( ) const;

};