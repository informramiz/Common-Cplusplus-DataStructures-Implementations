#include <iostream>
//#include <string>
//#include <stack>
#include <cmath>
using namespace std;

int numberOfDivisors ( int n )
{
	int c = 0;
	for ( int i = 2 ; i < ceil ( sqrt ( n ) ) ; i++ )
	{
		if ( n % i == 0 )
		{
			c += 2;
			cout << " i : " << i << endl;
		}
	}

	return c + 2;
}

void numberWithMaxDivisors ( int l , int u )
{
	int number;
	int divisors ;

	int max = 0;

	for ( int i = l ; i <= u ; i++ )
	{
		divisors = numberOfDivisors ( i );

		if ( max < divisors )
		{
			max = divisors;
			number = i;
		}
	}

	cout << "number : " << number << " with " << max << " divisors" << endl;
}


void main ( )
{
	numberWithMaxDivisors ( 999999900 , 1000000000 );
}