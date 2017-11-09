#include <stdexcept>
using namespace std;

class DequeFull : public exception
{
	public:

		DequeFull ( const char * msg ) : exception ( msg )
		{}
};