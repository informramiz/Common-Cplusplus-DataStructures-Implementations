#include <stdexcept>
using namespace std;

class StackFull : public exception
{
	public:

		StackFull ( const char * msg ) : exception ( msg )
		{}
};