#include "Set.h"
#include "noMemory.h"
#include "SetEmpty.h"
#include "SetFull.h"

template < class T >
Set<T>::Set<T> ( int n )
{
	capacity = ( n > 0 ) ? n : 1 ;
	data = new T[capacity];

	numberOfElements = 0;
}

template < class T >
Set<T>::Set<T> ( Set<T> & s )
{
	capacity = s.capacity ;
	numberOfElements = s.numberOfElements ;

	data = new T[capacity];

	for ( int i = 0 ; i < capacity ; i++ )
		data[i] = s.data [i];
	
}

template < class T >
void Set<T>::insert ( T value )
{
	if ( data == 0 )
		throw NoMemoryException ( "There is not enough memory" );

	if ( !isFull ( ) )
	{
		if ( !isCommonElement ( value ) )
			data[ numberOfElements++ ] = value;
	}
	else
		throw SetFullException ( "The set is full" );
}

template < class T >
void Set<T>::remove ( T value )
{
	if ( data == 0 )
		throw NoMemoryException ( "There is not enough memory" );

	if ( !isEmpty ( ) )
	{
		int location = findLocation ( value );

		if ( location != - 1 )
		{
			shiftElementsToLeft ( location );
			numberOfElements --;
		}
		else
			throw NoMatchException ( "There is no match" );
	}
	else
		throw SetEmptyException ( "The set is empty" );
}

template < class T >
void Set<T>::input ( )
{
	if ( data == 0 )
		throw NoMemoryException ( "There is not enough memory" );

	T temp;
	for ( int i = 0 ; i < capacity ; i++ )
	{
		cin >> temp;
		insert ( temp );
	}
}

template < class T >
void Set<T>::print ( ) const
{
	if ( data == 0 )
		throw NoMemoryException ( "There is not enough memory" );

	if ( numberOfElements == 0 )
		cout << '{' << '}' << endl;
	else
	{
			cout << '{' ;
			for ( int i = 0 ; i < numberOfElements ; i++ )
			{
				cout << data[i] ;

				if ( i != numberOfElements - 1 )
					cout << ',' ;
			}
			cout << '}' << endl;
	}
}

template < class T >
bool Set<T>::isCommonElement ( T element ) const
{
	if ( data == 0 )
		throw NoMemoryException ( "There is not enough memory" );

	for ( int i = 0 ; i < numberOfElements ; i++ ) 
		if ( data[i] == element )
			return true;
	
	return false;
}

template < class T >
Set<T> Set<T>::unionOfSet (const Set<T> & s ) const
{
	if ( data == 0 || s.data == 0 )
		throw NoMemoryException ( "There is no memory" );

	Set<T> unionSet ( numberOfElements + s.numberOfElements );


	for ( int i = 0 ; i < numberOfElements ; i++ )
		unionSet.insert( data[i] );

	for ( i = 0 ; i < s.numberOfElements ; i++ )
		if ( !isCommonElement ( s.data [i] ) )
			unionSet.insert ( s.data [i] );

	return unionSet;

}

template < class T >
Set<T> Set<T>::intersection ( const Set<T> & s ) const 
{
	if ( data == 0 || s.data == 0 )
		throw NoMemoryException ( "There is no memory" );

	Set<T> intersectionSet ( s.numberOfElements  );

	for ( int i = 0 ; i < s.numberOfElements && i < numberOfElements ; i++ )
		if ( isCommonElement ( s.data [i] ) ) 
			intersectionSet.insert ( s.data[i] );
		
	return intersectionSet;
}

template < class T >
Set<T> Set<T>::difference ( const Set<T> & s ) const
{
	if ( data == 0 || s.data == 0 )
		throw NoMemoryException ( "There is no memory" );

	Set<T> difference ( numberOfElements + s.numberOfElements );

	for ( int i = 0 ; i < numberOfElements ; i++ )
	{
		if ( !s.isCommonElement ( data[i] ) )
			difference.insert ( data[i] );
	}

	return difference;
}

template < class T >
Set<T> Set<T>::crossProduct ( const Set<T> & s ) const
{

	if ( data == 0 || s.data == 0 )
		throw NoMemoryException ( "There is no memory" );

	Set<T> product ( numberOfElements * s.numberOfElements );

	for ( int i = 0 ; i < numberOfElements ; i++ )
	{
		for ( int j = 0 ; j < s.numberOfElements ; j++ )
			product.insert ( data[i] *  s.data[j] );
	}

	return product;
}

template < class T >
Set<T> Set<T>::symmetricDifference ( const Set<T> & s ) const
{
	if ( data == 0 || s.data == 0 )
		throw NoMemoryException ( "There is no memory" );

	Set<T> difference ( numberOfElements + s.numberOfElements );
	
	for ( int i = 0 ; i < numberOfElements ; i++ )
		if ( !s.isCommonElement ( data[i] ) )
			difference.insert ( data[i] );


	for ( i = 0 ; i < s.numberOfElements ; i++ )
		if ( !isCommonElement ( s.data[i] ) )
			difference.insert ( s.data[i] );


	return difference;
}

template < class T >
int Set<T>::getCapacity ( ) const
{
	return capacity;
}

template < class T >
int Set<T>::getCardinality ( ) const
{
	return numberOfElements ;
}

template < class T >
void Set<T>::shiftElementsToLeft ( int limit )
{

	if ( data == 0 )
		throw NoMemoryException ( "There is no memory" );

	for ( int i = limit ; i < numberOfElements - 1 ; i++ )
   		data[i] = data[i+1];
}

template < class T >
bool Set<T>::isEmpty ( ) const
{
	if ( numberOfElements == 0 ) 
		return true;

	return false;
}

template < class T >
bool Set<T>::isFull ( ) const
{
	if ( numberOfElements == capacity )
		return true;

	return false;
}

template < class T >
int Set<T>::findLocation ( T value ) const
{

	if ( data == 0 )
		throw NoMemoryException ( "There is no memory" );

	for ( int i = 0 ; i < numberOfElements ; i++ )
		if ( data[i] == value )
			return i;

	return -1;
}