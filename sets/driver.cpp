#include "set.cpp"

template class Set < int >;

void main()
{
	Set<int> s1 ( 2 ) ;
	Set<int> s2 ( 2 );

	cout << "Enter the set1 elements : \n";
	s1.input ( );

	try
	{
		s1.insert ( 3 );
		s1.insert ( 2 );
		s1.insert ( 4 );
	}

	catch ( exception & e )
	{
		cout << "Exception : " << e.what ( ) << endl;
	}

  //	cout << "\ns1 is : ";
	//s1.print ( );
}