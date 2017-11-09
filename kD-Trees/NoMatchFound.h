#include <stdexcept>
using namespace std;

class NoMatchFound : public exception
{
	public:

		NoMatchFound ( const char * msg ) : exception ( msg )
		{}
};