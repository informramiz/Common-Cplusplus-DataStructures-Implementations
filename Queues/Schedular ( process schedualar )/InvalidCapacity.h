#include <stdexcept>
using namespace std;

class InvalidCapacity : public exception
{
	public:

		InvalidCapacity ( const char * msg ) : exception ( msg )
		{}
};