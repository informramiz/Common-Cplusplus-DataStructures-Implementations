#include "Stack.h"

template < class T >

Stack < T >::Stack ( int s )
{
	if ( s <= 0 )
		exit ( 0 );

	size = s;
	top = -1;

	stackPtr = new T [ size ];
}

template < class T >
void Stack< T >::push ( const T & value )
{
	if ( isFull ( ) )
		throw StackFull ( "Stack is full" );

	stackPtr[++top] = value;
}

template < class T >
T Stack<T>::pop ( )
{
	if ( isEmpty ( ) )
		throw StackEmpty ( "StackEmpty" );

	return stackPtr[top --];
}

template < class T >
T Stack<T>::stackTop ( ) const
{
	if ( isEmpty ( ) )
		StackEmpty ( "Stack is empty" );

	return stackPtr[top];
}

template < class T >
int Stack<T>::isEmpty ( ) const
{
	return top == -1;
}

template < class T >
int Stack<T>::isFull ( ) const
{
	return top == size - 1;
}

template < class T >
int Stack<T>::getCapacity ( ) const
{
	return size;
}