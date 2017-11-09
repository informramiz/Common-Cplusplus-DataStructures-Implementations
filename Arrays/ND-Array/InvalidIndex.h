//Name : Ramiz Raja
//Roll no : BITF09M038

#ifndef INVALIDINDEX_H
#define INVALIDINDEX_H

#include <stdexcept>
using namespace std;

class InvalidIndex : public exception
{
	public:

		InvalidIndex ( const char * msg ) : exception ( msg )
		{}
};

#endif