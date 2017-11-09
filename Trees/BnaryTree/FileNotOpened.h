#include <stdexcept>
using namespace std;

class FileNotOpened : public exception
{
	public:

		FileNotOpened ( const char * msg ) : exception ( msg )
		{}
};