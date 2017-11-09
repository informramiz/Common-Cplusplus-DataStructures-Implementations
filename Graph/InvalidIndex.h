#include <stdexcept>
using namespace std;

class InvalidIndex : exception
{
	public:

		InvalidIndex ( const char * msg ) : exception ( msg )
		{}
};

