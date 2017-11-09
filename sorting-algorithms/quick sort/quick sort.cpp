#include <iostream>
using namespace std;

void quickSort ( int * a , int start , int u )
{
	if ( start >= u - 1 )
		return;

	int i = start + 1;
	int j = u - 1;

	while ( i < u && j >= 0 && i <= j )
	{
		while ( i <= j && a[i] < a[start] )
			i++;

		if ( i > j )
			break;

		while ( j >= i && a[j] >= a[i] )
			j--;

		if ( j < i )
			break;

		swap ( a[i] , a[j] );

		i++;
		j--;
	}

	int p;

	if ( i <= j  )
	{
		swap ( a[start] , a[i] );
		p = i;
	}
	else
	{
		swap ( a[start] , a[j] );
		p = j;
	}

	quickSort ( a , start , p );
	quickSort ( a , p + 1 , u );
}

void main ( )
{
	const int n = 4;

	int a[n] = { 2 , -3 , 1 , -4 };

	quickSort ( a , 0 , n );

	for ( int i = 0 ; i < n ; i++ )
		cout << a[i] << ' ';
}
