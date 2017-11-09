#include <iostream>
//#include <string>
//#include <stack>
#include <cmath>
using namespace std;

long gcd ( long a , long b )
{
	if ( a % b == 0 )
		return b;

	return gcd ( b , a % b );
}

void divByGcd ( long & a , long & b )
{
	long g = gcd ( a , b );
	
	a /= g;
	b /= g;
}

long combination ( int n1 , int k )
{
	long n = 1 , d = 1 , toMul , toDiv , i;

	if ( k > n1 / 2 )
		k = n1 - k;

	for ( i = k ; i ; i-- )
	{
		toMul = n1 - k + i;
		toDiv = i;

		divByGcd ( toMul , toDiv );
		divByGcd ( toMul , d );
		divByGcd ( n , toDiv );

		n *= toMul;
		d *= toDiv;
	}

	return n/d;
}


void main ( )
{
	cout << combination ( 100 ,   6  ) << endl;
}