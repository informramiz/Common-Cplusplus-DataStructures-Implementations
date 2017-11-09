#include <stdexcept>
using namespace std;

class StackEmpty : public exception
{
	public:

		StackEmpty ( const char * msg ) : exception ( msg )
		{}
};