#include <stdexcept>
using namespace std;

class QueueFull : public exception
{
	public:

		QueueFull ( const char * msg ) : exception ( msg )
		{}
};