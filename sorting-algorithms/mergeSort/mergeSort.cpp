#include <iostream>
#include <cmath>
using namespace std;

void merge ( int * a , int l1 , int n1 , int l2 , int n2 )
{
	int size = ( n1 - l1 ) + ( n2 - l2 ) + 2;

	int * b = new int[size];

	int i = l1;
	int j = l2;

	for ( int k = 0 ; k < size ; k++ )
	{
		if ( i <= n1 && j <= n2 )
		{
			if ( a[i] <= a[j] )
			{
				b[k] = a[i];
				i++;
			}
			else
			{
				b[k] = a[j];
				j++;
			}
		}
		else if ( i <= n1 )
		{
			b[k] = a[i];
			i++;
		}
		else if ( j <= n2 )
		{
			b[k] = a[j];
			j++;
		}
	}

	for ( i = l1 ; i <= n2 ; i++ )
		a[i] = b[i-l1];

	delete [] b;
	b = 0;
}

void arrange ( int * a , int start , int n )
{
	int i = start + 1;
	int value = a[start];

	while ( i <= n && value > a[i] )
	{
		a[i-1] = a[i];
		i++;
	}

	a[i-1] = value;
}

void inPlaceMerge ( int * a , int l1 , int n1 , int l2 , int n2 )
{
	for ( int i = l1 ; i <= n1 ; i++ )
		if ( a[i] > a[l2] )
		{
			swap ( a[i] , a[l2] );
			arrange ( a , l2 , n2 );
		}
}

void mergeSort ( int * data , int l , int u )
{
	if ( l >= u )
		return;

	//static int a = 0;
	//a++;

	int m = ( ( l + u ) / 2 );

	



	mergeSort ( data , l , m );
	mergeSort ( data , m + 1 , u );

	inPlaceMerge ( data , l , m , m + 1 , u );


#if 0

	if ( a == 1 || a == 2 )
	{
		for ( int i = 0 ; i < 7 ; i++ )
			cout << data[i] << ' ';

		cout << endl;
	}
	else
		cin >> a;
#endif

}

void main ( )
{
	const int n = 7;

	int a[n] = { 10 , 2 , 3 , 90 , 6 , 4 , 10 };

	//inPlaceMerge ( a , 0 , 1 , 2 , 3 );

	mergeSort ( a , 0 , 6 );


	for ( int i = 0 ; i < n ; i++ )
		cout << a[i] << ' ';
}