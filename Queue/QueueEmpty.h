#include <stdexcept>
using namespace std;

class QueueEmpty : public exception
{
	public:
		
		QueueEmpty ( const char * msg ) : exception ( msg )
		{}
};