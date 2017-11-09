#include "KAryTree.h"

void main ( )
{
	KAryTree k;

	try
	{
		string name ( "C:\\F09\\" );

		k.setRoot ( "C:" , 0 );
		
		k.setChild ( "C:" , "DSA" , 0 );
		k.setChild ( "C:" , "F06" , 1 );
		k.setChild ( "F06" , "Assignment" , 1 );
		k.setChild ( "Assignment" , "Trees" , 1 );
		k.setChild ( "C:" , "F09" , 1 );

		KAryTree k1 ( k );

		k.deleteFile ( name );

		k.expandedView ( );

		//cout << k.findSize ( name ) << endl;
		//cout << k.isFound ( name ) << endl;

		//k.traverse ( );
	}

	catch ( exception & e )
	{
		cout << e.what ( ) << endl;
	}
}