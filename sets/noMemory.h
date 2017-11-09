#include <stdexcept>
#include <string>
using namespace std;

class NoMemoryException : public exception
{
	public:
		NoMemoryException ( const char * message ) : exception ( message )
		{

		}
};


class NoMatchException : public exception
{
	public:

		NoMatchException ( const char * message ) : exception ( message )
		{
		
		}
};

