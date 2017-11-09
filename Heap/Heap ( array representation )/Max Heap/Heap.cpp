#include "Heap.h"

template < class T >
T MaxHeap<T>::getMax ( ) const
{
	if ( isEmpty ( ) )
		throw HeapIsEmpty ( "Heap is empty" );

	return data[0];
}

template < class T >
void MaxHeap<T>::remove ( )
{
	if ( isEmpty ( ) )
		throw HeapIsEmpty ( "Heap is empty" );

	noOfElements--;
	int i = 0;

	data[0] = data[noOfElements];
	int size = pow ( 2 , height ) - 1;

	while ( i < size && ( ( 2 * i + 1 < size && data[i] < data[2 * i + 1] ) || ( 2 * i + 2 < size && data[i] < data[2 * i + 2] ) ) )
	{
		if ( i < 2 * i + 1 || i < 2 * i + 2 )
		{
			if ( data[2 * i + 1] > data[2 * i + 2] )
				swap ( data[i] , data[2 * i + 1] );
			else
				swap ( data[i] , data[2 * i + 2] );
		}
		else if ( i < 2 * i + 1 )
			swap ( data[i] , data[2 * i + 1] );
		else
			swap ( data[i] , data[2 * i + 2] );
	}
}

template < class T >
MaxHeap<T>::MaxHeap ( int h )
{
	if ( h <= 0 )
		throw InvalidHeight ( "Invalid height passed" );

	height = h;
	int size = pow ( 2 , height ) - 1;
	data = new T[size];

	noOfElements = 0;
}

template < class T >
void MaxHeap<T>::insert ( T value )
{
	if ( isFull ( ) )
		throw HeapIsFull ( "Heap is empty" );
	
	data[noOfElements++] = value;

	int i = noOfElements - 1;
	int parent ;

	if ( i % 2 == 0 )
		parent = ( i - 2 ) / 2;
	else
		parent = ( i - 1 ) / 2;

	while ( parent >= 0 && ( data[i] > data[parent] ) )
	{
		swap ( data[i] , data[parent] );
		i = parent;

		if ( i % 2 == 0 )
			parent = ( i - 2 ) / 2;
		else
			parent = ( i - 1 ) / 2;
	}
}

template < class T >
int MaxHeap<T>::isEmpty ( ) const
{
	return noOfElements == 0;
}

template < class T >
int MaxHeap<T>::isFull ( ) const
{
	return noOfElements == pow ( 2 , height ) - 1;
}