#include <stdexcept>
using namespace std;

class NoSpaceForChild : public exception
{
	public:

		NoSpaceForChild ( const char * msg ) : exception ( msg )
		{}
};