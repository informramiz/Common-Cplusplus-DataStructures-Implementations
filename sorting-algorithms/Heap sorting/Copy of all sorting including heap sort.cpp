#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;



void main ( )
{
	const int n = 5;
	int a[n] = { 0 , 2 , 1 , 5 , 4 };

	unique ( a , a + n );

	make_heap ( a , a + n );
	
	for ( int i = 0 ; i < n ; i++ )
		pop_heap ( a , a + n - i );

		
	//unique ( a , a + n );


	vector<int> v;

	for (  i = 0 ; i < n ; i++ )
		v.push_back ( a[i] );

	v.erase ( v.begin ( )  , v.begin ( ) + 0 );

	for (  i = 0 ; i < n  ; i++ )
		cout << v[i] << ' ';
}