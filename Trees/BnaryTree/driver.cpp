#include "BinaryTree.cpp"

template class BinaryTree<int>;

void main ( )
{
	BinaryTree<char> b;

	//ofstream outFile ( "out.txt" );
	ifstream inFile ( "out.txt" );

	try
	{
		b.setRoot ( 'a' );
		b.setLeftChild ( 'a' , 'b' );
		b.setRightChild ( 'a' , 'c' );

		b.setLeftChild ( 'b' , 'd' );
		//b.setRightChild ( 'b' , 'e' );
		
		b.setLeftChild ( 'c' , 'f' );
		b.setRightChild ( 'c' , 'g' );

		cout << b.isComplete ( ) << endl;

		//b.nonRecPostOrder ( );
		//cout << b.countLeafNodes ( ) << endl;
		
		//b.printAncestors ( 'g' );

		//cout << b.levelOfNode ( 'a' ) << endl;

		//b.writeToFile ( outFile );

		//BinaryTree<char> c ( b );
		//c.deleteNode ( 'g' );
		//b.readFromFile ( inFile );
		
		//c = b.mirrorImage ( );
		//c.levelOrder ( );

		//cout << b.findSiblingNode ( 'a' ) << endl;
		//b.displayParenthesizeView ( );
		//b.displayIndentedViewFromFile ( inFile );
	}

	catch ( exception & e )
	{
		cout << "exception occurred : " << e.what ( ) << endl;
	}
}