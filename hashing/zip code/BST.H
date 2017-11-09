#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;

#include "TreeEmpty.h"

template < class T >
struct Node
{
	T info;
	
	Node * left;
	Node * right;
	int height;

	Node ( )
	{
		left = right = 0;
		height = 1;
	}

	Node ( T val ) : info ( val )
	{
		left = right = 0;
		height = 1;
	}
};

template < class T >
class AVL
{
	private:
		
		Node<T> * root;

		int isEmpty ( ) const;

		Node<T> * inOrderSuccessor ( Node<T> * root ) const;
		Node<T> * leafNodeInOrderSuccessor ( Node<T> * root , Node<T> * node , int f ) const;

		Node<T> * inOrderSuccessorNode ( T key ) const;
		Node<T> * searchNode ( T key ) const;

		Node<T> * searchParent ( T key ) const;

		void updateHeight ( Node<T> * p ) ;

		void LeftLeft ( Node<T> * P , Node<T> * PP , Node<T> * LP , Node<T> * RLP );
		void RightRight ( Node<T> * P , Node<T> * PP , Node<T> * RP , Node<T> * LRP );

		void LeftRight ( Node<T> * P , Node<T> * PP , Node<T> * LP , Node<T> * RLP , Node<T> * LRLP , Node<T> * RRLP );
		void RightLeft ( Node<T> * P , Node<T> * PP , Node<T> * RP , Node<T> * LRP , Node<T> * LLRP , Node<T> * RLRP );

		int isBalanceFactorOut ( Node<T> * p ) const;
		void rotate ( Node<T> * PP , Node<T> * P , int balanceFactor ) ;

		void deleteNode1 ( T key ) ;
	public:

		AVL ( );
		void insert ( T val );
		int search ( T key ) const;

		void deleteNode ( T key ) ;
};