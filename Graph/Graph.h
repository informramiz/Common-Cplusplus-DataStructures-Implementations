#include <iostream>
#include <queue>
using namespace std;

#include "InvalidIndex.h"
#include "InvalidNumberOfVertices.h"

class Graph
{
	private:

		int * m;
		int vertices;
		mutable int * visited ;

		int & matrix ( int i , int j ) ;
		int matrix ( int i , int j ) const;

		int isValidIndex ( int index ) const;
		void DFS ( int i ) const;

		void displayVisited ( )const;

	public:

		Graph ( int v );
		~Graph ( );

		void insertEdge ( int i , int j , int weight = 1 );
		void removeEdge ( int i , int j );

		void BFS ( ) const;
		void DFS ( ) const;

		void undirectedComponents ( ) const;

		void display ( ) const
		{
			for ( int i = 0 ; i < vertices ; i++ )
			{
				for ( int j = 0 ; j < vertices ; j++ )
					cout << matrix ( i , j ) << ' ';

				cout << endl;
			}
		}
};
