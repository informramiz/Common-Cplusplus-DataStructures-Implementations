#include <iostream>
#include <cstdlib>
using namespace std;

template < class T >
class Set
{
	private:

		T * data;
		int capacity;
		int numberOfElements;

		bool isEmpty ( ) const;
		bool isFull ( ) const;

		int findLocation ( T ) const;
		
		bool isCommonElement ( T ) const;
		void shiftElementsToLeft ( int ) ;

	public:

		Set ( int );
		Set ( Set & );

		~Set ( )
		{
			if ( data )
			{
				delete [] data;
				data = 0;
			}
		}

		int getCapacity ( ) const;
		int getCardinality ( ) const;

		void insert ( T );
		void remove ( T );
		void input ( );

		Set unionOfSet ( const Set & ) const;
		Set intersection ( const Set & ) const;
		
		void print ( ) const;
		Set crossProduct ( const Set & ) const;

		Set difference ( const Set & ) const;
		Set symmetricDifference ( const Set & ) const;
};