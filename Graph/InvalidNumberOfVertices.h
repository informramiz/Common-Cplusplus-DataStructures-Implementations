#include <stdexcept>
using namespace std;

class InvalidNumberOfVertices : exception
{
	public:

		InvalidNumberOfVertices ( const char * msg ) : exception ( msg )
		{}
};

