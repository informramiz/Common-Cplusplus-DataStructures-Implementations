#include <stdexcept>
using namespace std;

class TreeEmpty : public exception
{
	public:

		TreeEmpty ( const char * msg ) : exception ( msg )
		{}
};