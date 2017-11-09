#ifndef INVALIDSIZE_H
#define INVALIDSIZE_H

#include <stdexcept>
using namespace std;

class InvalidSize : public exception
{
	public:
	
		InvalidSize ( const char * msg ) : exception ( msg )
		{}

};

#endif