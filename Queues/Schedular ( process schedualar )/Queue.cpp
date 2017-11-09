#include "Queue.h"

template < class T >
Queue<T>::Queue ( int size )
{
	if ( size <= 0 )
		throw InvalidCapacity ( "Invalid size" );

	capacity = size;
	data = new T[size];

	front = rear = -1;
}

template < class T >
Queue<T>::~Queue ( )
{
	if ( data )
	{
		delete [] data;
		data = 0;
	}
}

template < class T >
void Queue<T>::enQueue ( T value )
{
	if ( isFull ( ) )
		throw QueueFull ( "Queue is Full" );

	rear = ( rear + 1 ) % capacity;

	data[rear] = value;
}

template < class T >
T Queue<T>::deQueue ( ) 
{
	if ( isEmpty ( ) )
		throw QueueEmpty ( "Queue is empty" );

	front = ( front + 1 ) % capacity;

	T temp = data[front];

	if ( front == rear )
		front = rear = -1;
	
	return temp;
}

template < class T >
int Queue<T>::getElements ( ) const
{
	if ( front == - 1 )
		return rear + 1;

	return ( ( capacity - (front + 1 ) ) % capacity  + rear + 1 ) % capacity;
}

template < class T > 
bool Queue<T>::isFull ( ) const
{
	return ( ( rear == capacity - 1 && front == -1 )
		|| ( rear == front && rear != -1 ) );
}

template < class T >
bool Queue<T>::isEmpty ( ) const
{
	return ( rear == front && rear == - 1 );
}

