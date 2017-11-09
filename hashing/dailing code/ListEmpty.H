#include <stdexcept>
using namespace std;

class ListEmpty : public exception
{
	public:

		ListEmpty ( const char * msg ) : exception ( msg )
		{}
};