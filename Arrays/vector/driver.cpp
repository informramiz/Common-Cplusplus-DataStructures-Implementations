#include "vector.h"

void main ( )
{
	Vector < int > list;

	list.push ( new int ( 5 ) );
	list.push ( new int ( 6 ) );

	for ( int i = 0 ; i < list.getCapacity ( ) ; i++ )
		cout << *list[i] << ' ';
}