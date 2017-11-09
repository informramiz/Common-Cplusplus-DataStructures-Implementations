#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "TreeEmpty.h"

template < class T >
struct Node
{
	T info;
	
	Node * left;
	Node * right;

	Node ( )
	{
		left = right = 0;
	}

	Node ( T val ) : info ( val )
	{
		left = right = 0;
	}
};

template < class T >
class BST
{
	private:
		
		Node<T> * root;

		int isEmpty ( ) const;

		Node<T> * inOrderSuccessor ( Node<T> * root ) const;
		Node<T> * leafNodeInOrderSuccessor ( Node<T> * root , Node<T> * node , int f ) const;

		Node<T> * inOrderSuccessorNode ( T key ) const;
		Node<T> * searchNode ( T key ) const;

		Node<T> * searchParent ( T key ) const;

		void displaySorted ( Node<T> * p , int counter ) const;

	public:

		BST ( );
		void insert ( T val );

		int search ( T key ) const;
		void deleteNode ( T key ) ;

		void displaySorted ( ) const;
};