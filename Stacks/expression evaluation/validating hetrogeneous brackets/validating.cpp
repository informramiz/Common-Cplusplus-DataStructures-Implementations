#include <iostream>
#include <string>
using namespace std;

#include "stack.cpp"

int validate ( const char * );
int isOpeningBracket ( char );

int isClosingBracket ( char );
int isOppositeBracket ( char , char );

void main ( )
{
	string s ( " { [ ( ( a * ( a + b ) * c / d ) ) ] }" );

	try
	{
		if ( validate ( s.data ( ) ) )
			cout << "Valid" << endl;
		else 
			cout << "Invalid" << endl;
	}

	catch ( exception & e )
	{
		cout << "Execption occurred : " << e.what ( ) << endl;
	}
}

int validate ( const char * str )
{
	int i = 0;
	Stack<int> s;

	while ( str[i] != '\0' )
	{
		if ( isOpeningBracket ( str[i] ) )
				s.push ( str[i] );
		else if ( isClosingBracket ( str[i] ) )
		{
			if ( s.isEmpty ( ) )
				return 0;
			else if ( isOppositeBracket ( s.stackTop ( ) , str[i] ) )
				s.pop ( );
			else
				return 0;
		}

		i++;
	}

	if ( s.isEmpty ( ) )
		return 1;

	return 0;
}

int isOpeningBracket ( char ch )
{
	if ( ch == '(' )
		return 1;
	else if ( ch == '{' )
		return 1;
	else if ( ch == '[' )
		return 1;

	return 0;
}

int isClosingBracket ( char ch )
{
	if ( ch == ')' )
		return 1;
	else if ( ch == '}' )
		return 1;
	else if ( ch == ']' )
		return 1;

	return 0;
}

int isOppositeBracket ( char ch1 , char ch2 )
{
	if ( ch1 == '(' && ch2 == ')' )
		return 1;
	else if ( ch1 == '{' && ch2 == '}' )
		return 1;
	else if ( ch1 == '[' && ch2 == ']' )
		return 1;

	return 0;
}