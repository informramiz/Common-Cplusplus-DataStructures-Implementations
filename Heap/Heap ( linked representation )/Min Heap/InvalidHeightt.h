#include <stdexcept>
using namespace std;

class InvalidHeight : public exception
{
	public:
	
		InvalidHeight ( const char * msg ) : exception ( msg )
		{}
};


class HeapIsFull : public exception
{
	public:
	
		HeapIsFull ( const char * msg ) : exception ( msg )
		{}
};

class HeapIsEmpty : public exception
{
	public:
	
		HeapIsEmpty ( const char * msg ) : exception ( msg )
		{}
};
