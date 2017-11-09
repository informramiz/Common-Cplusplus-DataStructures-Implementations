#include <stdexcept>
using namespace std;

class NoMatch : public exception
{
	public:

		NoMatch ( const char * msg ) : exception ( msg )
		{}
};