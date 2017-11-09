#include "LSLL.cpp"

template class LSLL<int>;
void main ( )
{
	LSLL<int> l;

	try
	{
		l.insertAtHead ( 4 );
		l.insertAtHead ( 5 );
		//l.insertBefore ( 4 , 6 );
		//l.insertBefore ( 5 , 7 );
		//l.deleteBefore ( 4 );

		//l.insertAfter ( 4 , 3 );
		//l.insertAfter ( 5 , 3 );
		//l.deleteAfter ( 5 );
		l.deleteX ( 4 );

		l.traverse ( );
		l.traverse ( );
	}

	catch ( exception & e )
	{
		cout << e.what ( ) << endl;
	}
}