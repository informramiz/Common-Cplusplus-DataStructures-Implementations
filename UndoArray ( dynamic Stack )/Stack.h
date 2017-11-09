#include <iostream>
#include <cstdlib>
using namespace std;

#include "StackNode.h"
#include "StackEmpty.h"
#include "InvalidSize.h"


template < class T >
class Stack
{
	private:

		StackNode<T> * top;
		int topCount;

	public:

		Stack (  );
		//Stack ( const Stack & );
		~Stack ( );

		//Stack & operator = ( const Stack & );

		void push ( const T & );
		T pop ( ) ;

		//int isFull ( ) const;
		int isEmpty ( ) const;

		T stackTop ( ) const;
		int getTop ( ) const;

};