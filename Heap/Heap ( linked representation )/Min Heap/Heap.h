#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#include "InvalidHeightt.h"

template < class T >
struct Node
{
	Node * left;
	Node * right;

	T info;
	
	Node ( )
	{
		left = right = 0;
	}

	Node ( T value )
	{
		info = value;
		left = 0;
		right = 0;
	}
};

template < class T >
class MinHeap
{
	private:

		Node<T> * root;
		int noOfNodes;

		void convertToBinary( int n , vector<int> & v ) const;
		int isEmpty ( ) const;

		void reStructure ( Node<T> * p );

	public:

		MinHeap (  );
		void insert ( T value ) ;

		T getMin ( ) const;
		void remove ( ) ;

		void display ( ) const
		{
			queue< Node<T> * > q;

			Node<T> * p = root;

			while ( p )
			{
				cout << p->info << ' ' ;

				if ( p->left )
					q.push ( p->left);
					
				if ( p->right )
					q.push ( p->right );

				if ( !q.empty ( ) )
				{
					p = q.front ( );
					q.pop ( );
				}
				else
					p = 0;
			}

			cout << endl;
		}
};