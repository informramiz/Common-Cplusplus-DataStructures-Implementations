#include "Deque.h"

template < class T >
Deque<T>::Deque ( int size )
{
	if ( size <= 0 )
		throw InvalidCapacity ( "Invalid size" );

	capacity = size;
	data = new T[size];

	rear = -1 ;
	front = -1;

}

template < class T >
Deque<T>::~Deque ( )
{
	if ( data )
	{
		delete [] data;
		data = 0;
	}
}

template < class T >
void Deque<T>::insertAtHead ( T value )
{
	if ( isFull ( ) )
		throw DequeFull ( "deque full" );

	front = ( front + 1 ) % capacity;

	data[front] = value;
}

template < class T >
T Deque<T>::deleteAtHead ( )
{
	if ( isEmpty ( ) )
		throw DequeEmpty ( "deque empty" );

	T value = data[front];

	front = ( front - 1 + capacity ) % capacity;

	if ( front == rear )
	{
		rear = - 1;
		front = -1;
	}

	return value;
}

template < class T >
void Deque<T>::insertAtTail ( T value )
{
	if ( isFull ( ) )
		throw DequeFull ( "deque full" );

	if ( rear == -1 )
		rear = capacity - 1;

	data[rear] = value;

	rear = ( rear - 1 + capacity ) % capacity;
}

template < class T >
T Deque<T>::deleteAtTail ( )
{
	if ( isEmpty ( ) )
		throw DequeEmpty ( "deque empty" );

	rear = ( rear + 1 ) % capacity;

	T value = data[rear];

	if ( front == rear )
	{
		rear = - 1;
		front = -1;
	}

	return value;
}

template < class T >
int Deque<T>::getElements ( ) const
{
	if ( front == - 1 )
		return rear + 1;

	return ( ( capacity - (front + 1 ) ) % capacity  + rear + 1 ) % capacity;
}
 
template < class T > 
bool Deque<T>::isFull ( ) const
{
	return ( ( rear == capacity - 1 && front == -1 )
		|| ( rear == front && rear != -1 ) );
}

template < class T >
bool Deque<T>::isEmpty ( ) const
{
	return ( rear == front && rear == - 1 );
}

