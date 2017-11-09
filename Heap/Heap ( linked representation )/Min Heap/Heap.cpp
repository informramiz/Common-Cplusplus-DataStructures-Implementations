#include "Heap.h"

template < class T >
MinHeap<T>::MinHeap ( )
{
	root = 0;
	noOfNodes = 1;
}

template < class T >
void MinHeap<T>::remove ( ) 
{
	if ( isEmpty ( ) )
		throw HeapIsEmpty ( "Heap is empty" );

	noOfNodes--;

	if ( noOfNodes == 1 )
	{
		delete root;
		root = 0;

		noOfNodes = 1;
		return;
	}

	Node<T> * p = root;
	Node<T> * q = p;

	vector<int> v;
	convertToBinary ( noOfNodes  , v );

	while ( !v.empty ( ) )
	{
		q = p;
		if ( v.back ( ) == 0 )
			p = p->left;
		else
			p = p->right;
		
		v.pop_back ( );
	}
	
	root->info = p->info;

	if ( q->left == p )
		q->left = 0;
	else
		q->right = 0;

	delete p;
	p = 0;

	reStructure ( root );
}

template < class T >
void MinHeap<T>::reStructure ( Node<T> * parent )
{
	while ( parent != 0 && ( ( parent->left && parent->info > parent->left->info ) || ( parent->right && parent->info > parent->right->info ) ) )
	{
		if ( parent->left && parent->right )
		{
			if ( parent->left->info < parent->right->info )
			{
				swap ( parent->info , parent->left->info );
				parent = parent->left;
			}
			else
			{
				swap ( parent->info , parent->right->info );
				parent = parent->right;
			}
		}
		else if ( parent->left )
		{
			swap ( parent->info , parent->left->info );
			parent = parent->left;;
		}
		else
		{
			swap ( parent->info , parent->right->info );
			parent = parent->right;
		}
	}
}

template < class T >
T MinHeap<T>::getMin ( ) const
{
	if ( isEmpty ( ) )
		throw HeapIsEmpty ( "Heap is empty" );

	return root->info;
}

template < class T >
int MinHeap<T>::isEmpty ( ) const
{
	return root == 0;
}

template < class T >
void MinHeap<T>::insert ( T value )
{
	if ( isEmpty ( ) )
	{
		root = new Node<T> ( value );
		noOfNodes++;

		return;
	}

	vector<int> v;
	convertToBinary ( noOfNodes , v );

	stack< Node<T> * > s;
	Node<T> * p = root;

	Node<T> * newNode ;

	while ( !v.empty ( ) )
	{
		s.push ( p );

		if ( v.back ( ) == 0 )
		{
			if ( p->left )
				p = p->left;
			else
			{
				p->left = new Node<T> ( value );
				newNode = p->left;
			}
		}
		else
		{
			if ( p->right )
				p = p->right;
			else
			{
				p->right = new Node<T> ( value );
				newNode = p->right;
			}
		}

		v.pop_back ( );
	}

	while ( newNode != root && !s.empty ( ) && newNode->info < s.top ( )->info )
	{
		swap ( newNode->info , s.top ( )->info );
		newNode = s.top ( );
		s.pop ( );
	}

	noOfNodes++;
}

template < class T >
void MinHeap<T>::convertToBinary ( int n , vector<int> & v ) const
{
	while ( n >= 1 )
	{
		v.push_back ( n % 2 );
		n /= 2;
	}

	v.pop_back ( );
}