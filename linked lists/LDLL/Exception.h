#include <stdexcept>
using namespace std;

class ValueNotFound : public exception
{

public:
	ValueNotFound( const char* ptr ) : exception(ptr)
	{}

};

class ListIsEmpty : public exception
{

public:
	ListIsEmpty( const char* ptr ) : exception(ptr)
	{}

};