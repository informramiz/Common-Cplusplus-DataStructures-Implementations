#include <stdexcept>
using namespace std;

class DequeEmpty : public exception
{
	public:
		
		DequeEmpty ( const char * msg ) : exception ( msg )
		{}
};