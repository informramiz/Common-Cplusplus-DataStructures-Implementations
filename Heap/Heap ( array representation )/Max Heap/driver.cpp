#include "Heap.cpp"

template class MaxHeap<int>;
void main ( )
{
	MaxHeap<int> m ( 10 );

	try
	{
		m.insert ( 5 );
		m.insert ( 6 );
		m.insert ( 7 );
		m.insert ( 4 );
		
		cout << m.getMax ( ) << endl;
		m.display ( );
	}

	catch ( exception & e )
	{
		cout << e.what ( ) << endl; 
	}
}