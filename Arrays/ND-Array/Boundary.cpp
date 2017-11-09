//Name : Ramiz Raja
//Roll no : BITF09M038

#include "Boundary.h"

Boundary::Boundary ( int l , int u )
{
	upper = u;
	lower = l;
}

int Boundary::getSize ( ) const
{
	return upper - lower;
}