#include <stdexcept>
using namespace std;

class NoChildExist : public exception
{
	public:

		NoChildExist ( const char * msg ) : exception ( msg )
		{}
};


class NoSiblingExist : public exception
{
	public:

		NoSiblingExist ( const char * msg ) : exception ( msg )
		{}
};
