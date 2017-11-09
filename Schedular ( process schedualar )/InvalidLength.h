#include <stdexcept>
using namespace std;

class InvalidLength : public exception
{
	public:

		InvalidLength ( const char * msg ) : exception ( msg )
		{}
};