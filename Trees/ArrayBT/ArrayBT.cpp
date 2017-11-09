#include "ArrayBT.h"

template < class T >
ArrayBT<T>::ArrayBT ( int h )
{
	if ( h <= 0 )
		throw InvalidHeight ( "Invalid height" );

	height = h;
	
	int size = pow ( 2 , h ) - 1;
	data = new T[size];
	status = new char[size];
	
	for ( int i = 0 ; i < size ; i++ )
		status[i] = 'F';
}

template < class T >
void ArrayBT<T>::setRoot ( T val )
{
	data[0] = val;
	status[0] = 'T';
}

template < class T >
void ArrayBT<T>::setLeftChild ( T key , T val )
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	int index = findTreePosition ( key );

	if ( index == -1 )
		throw NoMatchFound ( "No match found" );

	if ( 2 * index + 1 >= ( pow ( 2 , height ) - 1 ) )
		throw NoSpaceForChild ( "No space for left child" );
	
	data[2 * index + 1 ] = val;
	status[2 * index + 1] = 'T';
}

template < class T >
void ArrayBT<T>::setRightChild ( T key , T val )
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	int index = findTreePosition ( key );

	if ( index == -1 )
		throw NoMatchFound ( "No match found" );

	if ( 2 * index + 2 >= ( pow ( 2 , height ) - 1 ) )
		throw NoSpaceForChild ( "No space for right child" );
	
	data[2 * index + 2 ] = val;
	status[2 * index + 2] = 'T';
}

template < class T >
T ArrayBT<T>::getLeftChild ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	int index = findTreePosition ( key );

	if ( index == -1 )
		throw NoMatchFound ( "No match found" );

	if ( 2 * index + 1 >= pow ( 2 , height ) - 1 || status[2 * index + 1 ] == 'F' )
		throw exception ( "No left child exists" );
	
	return data[2 * index + 1 ] ;
}

template < class T >
void ArrayBT<T>::preOrderTraversal ( int i ) const
{
	if ( i >= pow ( 2 , height ) - 1 )
		return;

	if ( status[i] == 'T' )
		cout << data[i] << ' ';

	preOrderTraversal ( 2 * i + 1 );
	preOrderTraversal ( 2 * i + 2 );
}

template < class T >
void ArrayBT<T>::inOrderTraversal ( int i ) const
{
	if ( i >= pow ( 2 , height ) - 1 )
		return;

	inOrderTraversal ( 2 * i + 1 );

	if ( status[i] == 'T' )
		cout << data[i] << ' ';

	inOrderTraversal ( 2 * i + 2 );
}

template < class T >
void ArrayBT<T>::postOrderTraversal ( int i ) const
{
	if ( i >= pow ( 2 , height ) - 1 )
		return;

	postOrderTraversal ( 2 * i + 1 );
	postOrderTraversal ( 2 * i + 2 );

	if ( status[i] == 'T' )
		cout << data[i] << ' ';
}

template < class T >
T ArrayBT<T>::getRightChild ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	int index = findTreePosition ( key );

	if ( index == -1 )
		throw NoMatchFound ( "No match found" );

	if ( 2 * index + 2 >= ( pow ( 2 , height ) - 1 ) || status[2 * index + 2 ] == 'F' )
		throw exception ( "No right child exists" );
	
	return data[2 * index + 2];
}

template < class T >
bool ArrayBT<T>::isEmpty ( ) const
{
	return status[0] == 'F' ;
}

template < class T >
int ArrayBT<T>::findTreePosition ( T key ) const
{
	int size = pow ( 2 , height ) - 1;

	int i = 0;

	while ( i < size )
	{
		if ( status[i] == 'T' && data[i] == key )
			return i;

		i++;
	}

	return -1;
}

template < class T >
void ArrayBT<T>::deleteNode ( T key ) 
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	int index = findTreePosition ( key );

	if ( index == -1 )
		throw NoMatchFound ( "No match found" );

	erase ( index );
}

template < class T >
void ArrayBT<T>::erase ( int i ) 
{
	if ( i >= pow ( 2 , height ) - 1 )
		return;

	status[i] = 'F';
	
	erase ( 2 * i + 1 );
	erase ( 2 * i + 2 );
}

template < class T >
void ArrayBT<T>::display ( ifstream & inFile , int count )
{
	char ch;

	if ( !( inFile >> ch ) )
		return;

	if ( ch == '(' )
	{
		count++;
	}
	else if ( ch == ')' )
		count--;
	else if ( ch != ',' )
	{
		for ( int i = 0 ; i < count - 1 ; i++ )
			cout << "\t" ;

		cout << ch << endl;
	}

	display ( inFile , count );
}

template < class T >
void ArrayBT<T>::displayIteratively ( ifstream & inFile )
{
	if ( inFile == 0 )
		return;

	int count = 0;

	char ch;

	while ( inFile >> ch )
	{
		if ( ch == ')' )
			count--;
		else if ( ch == '(' )
			count++;
		else if ( ch != ',' )
		{
			for ( int i = 0 ; i < count - 1; i++ )
				cout << "\t";

			cout << ch << endl;
		}
	}
}
