#include <stdexcept>
using namespace std;

class InvalidIndex : public exception
{
	public:
	
		InvalidIndex ( const char * msg ) : exception ( msg )
		{}

};