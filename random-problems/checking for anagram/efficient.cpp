#include <iostream.h>
#include <string.h>

bool isAnagram ( const char * const str1 , const char * const a2 );

void main ( )
{
	char a[100];
	char b[100];

	cout << "Enter fist word : " ;
	cin >> a;

	cout << "Enter second word : ";
	cin >> b;

	if ( isAnagram ( a , b ) )
		cout << "\nAnagram" << endl;

}

bool isAnagram ( const char * const str1 , const char * const str2 )
{
	int len1 = strlen ( str1 );
	int len2 = strlen ( str2 );

	if ( len1 != len2 )
		return false;
	
	int a[256] = { 0 };

	for ( int i = 0 ; i < len1 ; i++ )
	{
		a [ str1[i] ]++;

		a[ str2[i] ]++;
	}

	for ( i = 64 ; i < 256 ; i++ )
		if ( a[i] == 1 )
			return false;

	return true;
}

