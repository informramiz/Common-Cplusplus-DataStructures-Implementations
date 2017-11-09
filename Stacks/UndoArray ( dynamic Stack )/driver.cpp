#include "UndoArray.cpp"

//template class UndoArray<int>;

void main ( )
{
	UndoArray<int> a;

	a.set ( 1 , 5 );

	//cout << a.get ( 1 ) << endl;
	
	a.set ( 1 , 6 );
	a.set ( 1 , 0 );
	a.set ( 1 , 9 );
	a.set ( 1 , 8 );

	cout << " before : " << a.get ( 1 ) << endl;
	
	a.undo ( 1 );
	cout << " after 1 : " << a.get ( 1 ) << endl;
	
	a.undo ( 1 );
	cout << " after 2 : " << a.get ( 1 ) << endl;

	//cout << a.get ( 1 ) << endl;
	
	//a.undo ( 1 );
	//a.undo ( 1 );
	//cout << a.get ( 1 ) << endl;

}