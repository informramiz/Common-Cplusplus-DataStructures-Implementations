//Name : Ramiz Raja
//Roll no : BITF09M038

#ifndef INVALIDDIMENSIONSIZE_H
#define INVALIDDIMENSIONSIZE_H

#include <stdexcept>
using namespace std;

class InvalidDimensionSize : public exception
{
	public:

		InvalidDimensionSize ( const char * msg ) : exception ( msg )
		{}
};

#endif