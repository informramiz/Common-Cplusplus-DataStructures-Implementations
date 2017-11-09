//Name : Ramiz Raja
//Roll no : BITF09M038

#include "NDArray.h"

NDArray::NDArray ( int dimNumber , int * lower , int * upper )
{
	// let n = noOfDiamonsions , t(n) = 5n + 4

	if ( !isValidDimensionNumber ( dimNumber ) )			// 1
		throw InvalidNumberOfDimensions ( "Invalid dimension number passed" );

	noOfDimensions = dimNumber;		// 1

	boundary = new Boundary[noOfDimensions]; // n
	int size = 1;								//1

	for ( int i = 0 ; i < noOfDimensions ; i++ )		// n + 1
	{//?3n

		boundary[i] = Boundary ( lower[i] , upper[i] );	// 1
		size *= boundary[i].getSize ( );
	}
	
	data = new int[size]; // n ( assuming n = size )
}

void NDArray::setValue ( int * indexSet , int value ) 
{
	//t(n) = n2 + 2n + 5
	int index = 0;

	if ( !isValidIndexSet ( indexSet ) )
		throw InvalidIndex ( "invalid index passed" );

	index = calculateIndex ( indexSet ); // n2 + 2n + 4
	data[index] = value;	// 1
}

int NDArray::getValue ( int * indexSet ) const
{
	// t(n) = n2 + 2n + 5
	int index = 0;
	
	if( !isValidIndexSet ( indexSet ) )
		throw InvalidIndex ( "invalid index passed" );

	index = calculateIndex ( indexSet ); // n2 + 2n + 4

	return data[index];	// 1
} 

int NDArray::getSize ( ) const
{
	// assuming noOfDimensions = n
	// t(n) = 2n + 3
	int size = 1;		// 1

	for ( int i = 0 ; i < noOfDimensions ; i++ ) // i = 0 to n , n + 1
		size = size * boundary[i].getSize ( );	// 0 to n = n 

	return size; // 1
}

int NDArray::calculateIndex ( int * indexSet ) const
{
	// assuming n = noOfDimensions
	// t ( n ) = n2 + 2n + 4

	int index = 0;		// 1
	int result;			// 1

	for ( int i = 0 ; i < noOfDimensions ; i++ ) // i = 0 to n , t = n + 1
	{//? i to n = n2 + n + 3

		result = indexSet[i] - boundary[i].lower;
		
		for ( int j = i + 1 ; j < noOfDimensions ; j++ ) // j = i to n , t = n - i
			result = result * boundary[j].getSize ( );		// n - i - 1

		index = index + result;		// 1
	}

	if ( index < 0 )
		return -index; // 1

	return index;
}

bool NDArray::isValidIndexSet ( int * indexSet ) const
{
	for ( int i = 0 ; i < noOfDimensions ; i++ )
		if ( indexSet[i] < boundary[i].lower || indexSet[i] >= boundary[i].upper )
			return false;

	return true;
}

bool NDArray::isValidDimensionNumber ( int value ) const
{
	return value > 0; // 1
}

bool NDArray::isValidDimensionSize ( int value ) const
{
	return value > 0; // 1
}