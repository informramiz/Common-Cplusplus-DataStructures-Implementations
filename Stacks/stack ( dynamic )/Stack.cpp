#include "Stack.h"

template < class T >

Stack < T >::Stack (  )
{
	topCount = 0;
	top = 0;
}

#if 0
template < class T >
Stack< T >::Stack ( const Stack<T> & s )
{
	size = s.size;
	top = s.top;

	stackPtr = new T[size];

	for ( int i = 0 ; i < size ; i++ )
		 stackPtr[i] = s.stackPtr[i];
}
#endif

template < class T >
Stack<T>::~Stack ( )
{
	if ( top )
	{
		while ( top )
		{
			StackNode<T> * toDie = top;
			top = top->next;

			delete toDie;
		}

		top = 0;
	}
}

#if 0
template < class T >
Stack<T> & Stack<T>::operator = ( const Stack<T> & s )
{
	if ( &s == this )
		return *this;

	delete [] stackPtr;
	size = s.size;
	top = s.top;

	stackPtr = new T[size];

	for ( int i = 0 ; i <= top ; i++ )
		stackPtr[i] = s.stackPtr[i];

	return *this;
}

#endif

template < class T >
void Stack< T >::push ( const T & value )
{
	top = new StackNode<T> ( value , top );
	topCount++;
}

template < class T >
T Stack<T>::pop ( )
{
	if ( isEmpty ( ) )
		throw StackEmpty ( "StackEmpty" );
	
	StackNode<T> * toDie = top;
	top = top->next;

	T data = toDie->value;

	delete toDie;
	topCount--;

	return data;
}

template < class T >
T Stack<T>::stackTop ( ) const
{
	if ( isEmpty ( ) )
		StackEmpty ( "Stack is empty" );

	return top->value;
}

template < class T >
int Stack<T>::isEmpty ( ) const
{
	return top == 0;
}

template < class T >
int Stack<T>::getTop ( ) const
{
	return topCount ;
}