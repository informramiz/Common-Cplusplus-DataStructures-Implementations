#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;


#include "LSLL.cpp"

struct CityCode
{
	string name;
	int code;

	CityCode ( string n , int c )
	{
		name = n;
		code = c;
	}

	CityCode ( )
	{
	
	}

	bool operator == ( const CityCode & c )
	{
		return c.name == name ;
	}

	bool operator != ( const CityCode & c )
	{
		return c.name != name;
	}
};


int x = 10;
int mod = 112;

LSLL<CityCode> cities[112];


unsigned long getHashCode ( const char * str ) 
{
	int len = strlen ( str ) ;
	int value = pow ( x , len - 1 );
	
	int hashCode = 0;
	for ( int i = 0 ; i < len - 1 ; i++ )
	{
		hashCode += str[i] * value;
		value /= x;
	}

	return hashCode + str[i];
}

int integer ( char * a )
{
	int i = 0;

	int value = 0;

	while ( a[i] != '\0' )
	{
		value *= 10;
		value += a[i] - '0';
		i++;
	}

	return value;
}

void search ( string name )
{
	long int index = getHashCode ( name.data ( ) ) % mod ;

	Node<CityCode> * p = cities[index].isFound ( CityCode ( name , 0 ) );

	if ( p == 0 )
		cout << "No match found" << endl;
	else
		cout << p->info.code << endl;
}

void read ( )
{
	ifstream inFile ( "in.txt" );
	
	char a[100];
	char code[10];

	int codeValue = 0;
	string name ;

	while ( !inFile.eof ( ) && inFile.getline ( a, 100 ) )
	{
		int len = strlen ( a );
		a[len-1] = '\0';

		inFile.getline ( code , 10 );
		codeValue = integer ( code );

		long int index = getHashCode ( a ) % mod ;

		cities[index].insertAtHead ( CityCode ( string ( a ) , codeValue ) );

	}

}

void main ( )
{
	read ( );
	search ( "Okara" );
}