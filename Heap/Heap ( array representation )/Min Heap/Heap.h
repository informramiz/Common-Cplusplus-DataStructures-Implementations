#include <iostream>
#include <cmath>
using namespace std;

#include "InvalidHeightt.h"

template < class T >
class MinHeap
{
	private:

		int height;
		T * data;
		int noOfElements;

		int isFull ( ) const;
		int isEmpty ( ) const;

	public:

		MinHeap ( int h );
		void insert ( T value ) ;

		T getMin ( ) const;
		void remove ( ) ;

		void display ( ) const
		{
			for ( int i = 0 ; i < noOfElements ; i++ )
				cout << data[i] << ' ';

			cout << endl;
		}
};