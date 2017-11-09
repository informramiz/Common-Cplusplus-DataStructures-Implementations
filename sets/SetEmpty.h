#include <stdexcept>
#include <string>
using namespace std;

class SetEmptyException : public exception
{
	public:

		SetEmptyException ( const char * message ): exception ( message )
		{

		}
};


