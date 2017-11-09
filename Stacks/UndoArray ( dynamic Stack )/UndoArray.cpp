#include "UndoArray.h"

template < class T >
UndoArray<T>::UndoArray ( int s )
{
	if ( s <= 0 )
		throw InvalidSize ( "Invalid size" );

	size = s;

	values = new Stack<T>[size];
}

template < class T >
void UndoArray<T>::set ( int index , T value )
{
	if ( !isValidIndex ( value ) )
		throw InvalidIndex ( "Invalid index" );

		values[index].push ( value );
}

template < class T >
void UndoArray<T>::undo ( int index )
{
	if ( !isValidIndex ( index ) )
		throw InvalidIndex ( "invalid index" );

	values[index].pop ( );
}

template < class T >
int UndoArray<T>::isValidIndex ( int index ) const
{
	return index >= 0 && index < size;
}

template < class  T >
T UndoArray<T>::get ( int index ) const
{
	if ( !isValidIndex ( index ) )
		throw InvalidIndex ( "Invalid index" );

	return values[index].stackTop ( );
}