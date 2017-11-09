#include <stdexcept>
#include <string>
using namespace std;

class SetFullException : public exception
{
	public:

		SetFullException ( const char * message ) : exception ( message )
		{

		}
};
