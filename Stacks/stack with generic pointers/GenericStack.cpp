#include "GenericStack.h"

void main ( )
{
	GenericStack < int > gs;

	{
		int * ptr = new int ( 5 );
		gs.push ( ptr );

		cout << *( int * )gs.pop ( );
	}
}