//Name : Ramiz Raja
//Roll no : BITF09M038

#include <iostream>
using namespace std;

#include "InvalidDimensionSize.h"
#include "InvalidNumberOfDimensions.h"
#include "InvalidIndex.h"
#include "Boundary.h"

class NDArray
{
	private:

		int noOfDimensions;
		Boundary * boundary ;
		int * data;

		bool isValidDimensionNumber ( int ) const;
		bool isValidDimensionSize ( int ) const;

		bool isValidIndexSet ( int * indexSet ) const;
		int calculateIndex ( int * indexSet ) const;

	public:

		NDArray ( int dimNumber , int * lower , int * upper );
		void setValue ( int * indexSet , int value );

		int getValue ( int * indexSet ) const;
		int getSize ( ) const;
};