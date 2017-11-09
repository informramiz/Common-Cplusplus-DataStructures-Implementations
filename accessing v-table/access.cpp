#include <iostream.h>

class Animal
{
	virtual void f ( )
	{
		cout << "ramiz" << endl;
	}

	virtual void g ( )
	{
		cout<< "G" << endl;
	}

};

void main ( )
{
	Animal a;

	int * ptr = *( int ** ) &a;

	( (void(*)())ptr[0] ) ( );
}