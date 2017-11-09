#include <stdexcept>
using namespace std;

class InvalidHeight : public exception
{
	public:

		InvalidHeight ( const char * msg ) : exception ( msg )
		{}
};