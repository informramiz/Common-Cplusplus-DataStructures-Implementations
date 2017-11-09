#include "BST.cpp"

template class AVL<int>;

void main ( )
{
	AVL<int> bt;

	bt.insert ( 8 );
	bt.insert ( 4 );
	bt.insert ( 7 );
	bt.insert ( 6 );
	bt.insert ( 5 );
	//bt.insert ( 2 );
	//bt.insert ( 11 );
	//bt.insert ( 12 );
	//bt.insert ( 9 );
	//bt.insert ( 6 );

	bt.deleteNode ( 8 );
	bt.deleteNode ( 7 );
	bt.deleteNode ( 6 );
	bt.deleteNode ( 5 );

	cout << bt.search ( 4 ) << endl;
}