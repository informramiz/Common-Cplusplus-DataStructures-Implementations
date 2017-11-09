#include <iostream.h>
#include <fstream.h>

void display ( const char * );

void main ( )
{
	display ( "file.txt" );
}

void display ( const char * name )
{
	ifstream inFile ( name , ios::in );

	int number;

	int frequency[100] = { 0 };

	while ( inFile >> number && !inFile.eof ( ) )
	{
		frequency[number]++;
	}

	for ( int i = 1 ; i < 100 ; i++ )
	{
		for ( int j = 0 ; j < frequency[i] ; j++ )
		{
			cout << i << ' ';
		}
		
		cout << endl;
	}
}