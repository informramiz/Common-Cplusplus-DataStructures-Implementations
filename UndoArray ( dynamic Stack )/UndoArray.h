#ifndef UNDOARRAY_H
#define UNDOARRAY_H

#include "Stack.cpp"
#include "InvalidSize.h"
#include "InvalidIndex.h"

template < class T >
class UndoArray
{
	private:

		int size;
		Stack<T> * values;

		int isValidIndex ( int ) const;

	public:

		UndoArray ( int s = 10 );

		void undo ( int );

		void set ( int , T );
		T get ( int ) const;
};

#endif