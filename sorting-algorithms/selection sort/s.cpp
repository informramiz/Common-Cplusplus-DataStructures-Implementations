#include <iostream.h>
#include <fstream.h>

void swap ( int & , int & );
int getMinimum ( int * , int , int );

void sort ( int * a , int n );

void main ( )
{
	int a[4] = { 3 , 2 , 1 , 6 };

	sort ( a , 4 );

	for ( int i = 0 ; i < 4 ; i++ )
		cout << a[i] << ' ' << endl;
}

void sort ( int * a , int n )
{
	for ( int i = 0 ; i < n ; i++ )
	{
		int min = getMinimum ( a , i , n );
		swap ( a[i] , a[min] );
	}
}

void swap ( int & n1 , int & n2 )
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int getMinimum ( int * a , int start , int n )
{
	int min = start;
	for ( int i = start + 1 ; i < n - 1 ; i++ )
		if ( a[i] < a[min] )
			min = i;
	return min;
}
