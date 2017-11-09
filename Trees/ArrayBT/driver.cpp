#include "ArrayBT.cpp"

template class ArrayBT<int>;
void main ( )
{
	ArrayBT<int> t ( 4 );

	ifstream inFile ( "in.txt" );

	try
	{
		t.setRoot ( 1 );
		t.setLeftChild ( 1 , 2 );
		t.setRightChild ( 1 , 3 );

		t.setLeftChild ( 2 , 4 );
		t.setRightChild ( 2 , 5 );
		t.setLeftChild ( 5 , 6 );
		t.deleteNode ( 5 );

		t.displayIteratively ( inFile );
	}

	catch ( exception & e )
	{
		cout << "Exception occured : " << e.what ( ) << endl;
	}
}