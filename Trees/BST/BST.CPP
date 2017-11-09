#include "BST.h"

template < class T >
BST<T>::BST ( )
{
	root = 0;
}

template < class T >
int BST<T>::isEmpty ( ) const
{
	return root == 0;
}

template < class T >
void BST<T>::displaySorted ( ) const
{
	displaySorted ( root , 0 );
}

template < class T >
void BST<T>::displaySorted ( Node<T> * p , int level ) const
{
	if ( p == 0 )
		return;

	displaySorted ( p->left , level + 1 );

	for ( int i = 0 ; i < level ; i++ )
		cout << "-";

	cout << p->info << endl;

	displaySorted ( p->right , level + 1 );
}

template < class T >
Node<T> * BST<T>::inOrderSuccessorNode ( T key ) const
{
	Node<T> * p = searchNode ( key );

	if ( p->right == 0 )
		return p;

	if ( p->right == 0 && p->left == 0 )
		return leafNodeInOrderSuccessor ( root , p , 0 );

	return inOrderSuccessor ( p->right );
}

template < class T >
Node<T> * BST<T>::leafNodeInOrderSuccessor ( Node<T> * p , Node<T> * node , int f ) const
{
	if ( p == 0 )
		return 0;

	if ( p == node )
		return p;

	Node<T> * temp = leafNodeInOrderSuccessor ( p->left , node , f );

	if ( temp == 0 )
		temp = leafNodeInOrderSuccessor ( p->right , node , f );

	if ( temp != 0 && f != 1 )
	{
		if ( p->left == temp )
		{
			f = 1;
			return p;
		}
		else
			return p;
	}

	return temp;
}

template < class T >
Node<T> * BST<T>::inOrderSuccessor ( Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	Node<T> * temp = inOrderSuccessor ( p->left );

	if ( temp == 0 )
		temp = p;

	return temp;
}

template < class T >
void BST<T>::insert ( T key )
{
	if ( isEmpty ( ) )
	{
		root = new Node<T> ( key );
		return;
	}

	Node<T> * p = root;

	while ( p != 0 )
	{
		if ( p->info <= key )
		{
			if ( p->right )
				p = p->right;
			else
			{
				p->right = new Node<T> ( key );
				break;
			}
		}
		else if ( p->info > key )
		{
			if ( p->left )
				p = p->left;
			else
			{
				p->left = new Node<T> ( key );
				break;
			}
		}
	}
}

template < class T >
int BST<T>::search ( T key ) const
{
	Node<T> * p = root;

	while ( p != 0 )
	{
		if ( p->info == key )
			return 1;
		else if ( p->info <= key )
			p = p->right;
		else
			p = p->left;
	}

	return 0;
}

template < class T >
Node<T> * BST<T>::searchNode ( T key ) const
{
	Node<T> * p = root;

	while ( p != 0 )
	{
		if ( p->info == key )
			return p;
		else if ( p->info <= key )
			p = p->right;
		else
			p = p->left;
	}

	return 0;
}

template < class T >
Node<T> * BST<T>::searchParent ( T key ) const
{
	Node<T> * p = root;

	if ( p->info == key )
		return p;

	while ( p != 0 )
	{
		if ( (p->left && p->left->info == key ) || ( p->right && p->right->info == key ) )
			return p;
		else if ( p->info <= key )
			p = p->right;
		else
			p = p->left;
	}

	return 0;
}

template < class T >
void BST<T>::deleteNode ( T key )
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * p = searchNode ( key );

	if ( p == 0 )
		throw exception ( "No match found" );

	if ( p == root )
	{
		Node<T> * successor = inOrderSuccessorNode  ( p->info );
		Node<T> * parentOfSuccessor = searchParent ( successor->info );
		
		if ( parentOfSuccessor->left == successor )
			parentOfSuccessor->left = 0;
		else
			parentOfSuccessor->right = 0;
		
		if ( p->left != successor )
			successor->left = p->left;

		if ( p->right != successor )
			successor->right = p->right;

		root = successor;

		delete p;
		p = 0;

		return;
	}

	Node<T> * parent = searchParent ( key );

	if ( p->left == 0 && p->right == 0 )
	{

		if ( parent->left == p )
			parent->left = 0;
		else
			parent->right = 0;
	}
	else if ( ( p->left == 0 && p->right != 0 ) || ( p->right == 0 && p->left != 0 ) )
	{
		if ( parent->left == p )
		{
			if ( p->left )
				parent->left = p->left;
			else 
				parent->right = p->right;
		}
		else
		{
			if ( p->left )
				parent->right = p->left;
			else
				parent->right = p->right;
		}
	}
	else
	{
		Node<T> * successor = inOrderSuccessor  ( p );
		Node<T> * parentOfSuccessor = searchParent ( successor->info );
		
		if ( parentOfSuccessor->left == successor )
			parentOfSuccessor->left = 0;
		else
			parentOfSuccessor->right = 0;
		
		if ( p->left != successor )
			successor->left = p->left;

		if ( p->right != successor )
			successor->right = p->right;

		if ( parent->left == p )
			parent->left = successor;
		else
			parent->right = successor;
	}

	delete p;
	p = 0;
}