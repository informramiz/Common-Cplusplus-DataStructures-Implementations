#include <iostream>
//#include <string>
//#include <stack>
#include <cmath>
using namespace std;

int f ( int n )
{
	int m[ 200 ];

	m[1] = 1 , m[2] = 1;

	for ( int i = 3 ; i <= n ; i++ )
		m[i] = m[i - 1 ] + m[i - 2];

	return m[n ];
}

long square ( long n )
{
	return n * n;
}

long bigMode ( long b , long p , long m )
{
	if ( p == 0 )
		return 1;
	
	if ( p % 2 == 0 )
		return square ( bigMode ( b , p / 2 , m ) ) % m;
	else
		return ( b % m ) * bigMode ( b , p - 1 , m ) % m;
}

int f1 ( int n )
{
	if ( n == 1 || n == 2 )
		return 1;
	else
		return f1 ( n - 1 ) + f1 ( n - 2 );
}

int isPrime ( int n )
{
	int size = sqrt ( n );

	for ( int i = 2 ; i < size ; i++ )
		if ( n % i == 0 )
			return 0;

	return 1;
}

int isCarmicheal ( int n )
{
	int c = 0;

	for ( int i = 2 ; i < n ; i++ )
		if ( c % i == 0 && isPrime ( i ) )
			c++;

	if ( c >= 3 )
		return 1;

	return 0;
}

void display ( const int n )
{
	int temp = n;
	int c = 0;
	int j = 0;

	int a[50] = { 0 };

		for ( int i = 2 ; i <= n && n != 1 ; i++ )
		{
			if (  temp % i == 0 )
			{
				if ( isPrime ( i ) )
				{
					a[c] = i;
					c++;
					cout << i << endl;
				}

				temp = temp / i;
				i = 1;
			}
		}


		for ( i = 0 ; i < c - 1 ; i++ )
			if ( a[i] == a[i + 1] )
			{
				cout << "false" << endl;
				return;
			}


		if ( c >= 3 ) 
		{
			cout << "True" << endl ;
		}
		else
			cout << "false " << endl;
}


void main ( )
{
	//display ( 775866001 );
	display (  1109 );
}