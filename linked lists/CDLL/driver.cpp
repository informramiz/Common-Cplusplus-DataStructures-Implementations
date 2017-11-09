#include "CDLL.cpp"

//template class CDLL<int>;
void main ( )
{
	CDLL<int> c;

	try
	{
		c.insertAtHead ( 5 );
		c.insertAtHead ( 4 );
		c.insertAtHead ( 3 );
		c.insertAtHead ( 2 );
		c.insertAtHead ( 1 );

		c.deleteAtHead ( );
		c.deleteAtHead ( );
		c.deleteAtHead ( );
		c.deleteAtHead ( );
		c.deleteAtHead ( );
		c.deleteAtHead ( );

		c.traverse ( );
	}

	catch ( exception & e )
	{
		cout << e.what ( ) << endl;
	}
}