#include <stdexcept>
using namespace std;

class TrieEmpty : public exception
{
	public:

		TrieEmpty ( const char * msg ) : exception ( msg )
		{}
};