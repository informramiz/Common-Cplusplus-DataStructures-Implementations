#include "vector.h"

template < typename T >
Vector<T>::Vector ( )
{
	list = 0;
	capacity = 0;
}

template < typename T >
Vector<T>::~Vector ( )
{
	if ( list )
	{
		for ( int i = 0 ; i < capacity ; i++ )
			delete list[i];

		delete [ ] list;
		list = 0;
	}
}

template < typename T >
void Vector<T>::clear ( )
{
	for ( int i = 0 ; i < capacity ; i++ )
		delete list[i];

	delete [] list;
	list = 0;
	capacity = 0;
}

template < typename T >
void Vector<T>::push ( T * ptr )
{
	resize ( );
	list[ capacity ] = ptr;
	capacity ++;
}

template < typename T >
int Vector<T>::getCapacity ( )
{
	return capacity;
}

template < typename T >
void Vector<T>::resize ( )
{
	if ( list == 0)
	{
		list = new T * [1];
		return;
	}

	T ** newList = new T*[capacity + 1];

	for ( int i = 0 ; i < capacity ; i++ )
		newList[i] = list[i];

	delete [ ] list;

	list = newList;
}