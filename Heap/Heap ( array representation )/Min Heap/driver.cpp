#include "Heap.cpp"

template class MinHeap<int>;
void main ( )
{
	MinHeap<int> m ( 10 );

	try
	{
		m.insert ( 5 );
		m.insert ( 6 );
		m.insert ( 7 );
		m.insert ( 4 );
		
		m.remove ( );
		cout << m.getMin ( ) << endl;
		m.display ( );
	}

	catch ( exception & e )
	{
		cout << e.what ( ) << endl; 
	}
}