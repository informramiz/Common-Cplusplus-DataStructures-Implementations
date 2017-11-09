//Name : Ramiz Raja
//Roll no : BITF09M038

#ifndef INVALIDNUMBEROFDIMENSIONS_H
#define INVALIDNUMBEROFDIMENSIONS_H

#include <stdexcept>
using namespace std;

class InvalidNumberOfDimensions : public exception
{
	public:
		
		InvalidNumberOfDimensions ( const char * msg ) : exception ( msg )
		{}
};

#endif