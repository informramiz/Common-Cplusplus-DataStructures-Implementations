#include "Queue.cpp"

template class Deque<int>;

void main ( )
{
	Deque<int> q ( 3 ) ;

	try
	{
		q.insertAtHead ( 6 );
		q.insertAtHead ( 7 );
		q.insertAtTail ( 9 );
		
		q.deleteAtHead ( );

		while ( !q.isEmpty ( ) )
		{
			cout << q.deleteAtTail ( ) << endl;
		}
	}

	catch ( exception & e )
	{
		cout << "exception occurred : " << e.what ( ) << endl;
	}
}