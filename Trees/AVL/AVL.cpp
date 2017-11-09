#include "AVL.h"

template < class T >
void AVL<T>::updateHeight ( Node<T> * p ) 
{
	if ( p == 0 )
		return;

	if ( p->left && p->right )
	{
		if ( p->left->height > p->right->height )
			p->height = p->left->height + 1;
		else
			p->height = p->right->height + 1;
	}
	else if ( p->left )
		p->height = p->left->height + 1;
	else if ( p->right )
		p->height = p->right->height + 1;
	else
		p->height = 1;
}

template < class T >
int AVL<T>::isBalanceFactorOut ( Node<T> * p ) const
{
	int PH = 0 , LPH = 0 , LLPH = 0 , RLPH = 0;
	int RPH = 0 , LRPH = 0 , RRPH = 0;

	PH = p->height;

	if ( p->left )
		LPH = p->left->height;

	if ( p->left && p->left->left )
		LLPH = p->left->left->height;
	
	if ( p->left && p->left->right )
		RLPH = p->left->right->height;

	if ( p->right )
		RPH = p->right->height;

	if ( p->right && p->right->right )
		RRPH = p->right->right->height;

	if ( p->right && p->right->left )
		LRPH = p->right->left->height;

	int BP = LPH - RPH;
	int BLP = LLPH - RLPH;
	int BRP = LRPH - RRPH;

	// assigned values
// RR = 1 , LL = 2 , LR = 3 , RL = 4 , BALANCE = 0

	if ( BP > -2 && BP < 2 )
		return 0;

	if ( BP < -1 ) // R
	{
		if ( BRP < 0 ) // R
			return 1;
		else			// L
			return 4;
	}
	else		// L
	{
		if ( BLP  < 0 ) // R
			return 3;
		else			// L;
			return 2;
	}

	return 0;
}

template < class T >
void AVL<T>::rotate ( Node<T> * PP , Node<T> * P , int f )
{
	Node<T> *  pivot = P;

	if ( f == 1 ) // RR
	{
		Node<T> * RP = P->right;

		Node<T> * LRP = 0 ;

		if ( RP )
			LRP = P->right->left;

		RightRight ( P , PP , P->right , P->right->left );

		updateHeight ( LRP );

		updateHeight ( pivot );
		updateHeight ( RP );
	}
	else if ( f == 2 ) // LL
	{

		Node<T> * LP = P->left;
		Node<T> * RLP = 0 ;

		if ( LP )
			RLP = LP->right;

		LeftLeft ( P , PP , P->left , P->left->right );

		updateHeight ( RLP );

		updateHeight ( pivot );
		updateHeight ( LP );
	}
	else if ( f == 3 ) // LR
	{
		Node<T> * LP = P->left;
		Node<T> * RLP = 0 ;
		Node<T> * LRLP = 0;
		Node<T> * RRLP = 0;

		if ( LP )
			RLP = LP->right;

		if ( RLP )
		{
			LRLP = RLP->left;
			RRLP = RLP->right;
		}

		LeftRight ( P , PP , P->left , P->left->right , P->left->right->left , P->left->right->right );

		updateHeight ( LRLP );
		updateHeight ( RRLP );

		updateHeight ( pivot );
		updateHeight ( LP );

		updateHeight ( RLP );
	}
	else //RL
	{
		Node<T> * RP = P->right;
		Node<T> * LRP = 0 ;
		Node<T> * LLRP = 0;
		Node<T> * RLRP = 0;

		if ( RP )
			LRP = RP->left;

		if ( LRP )
		{
			LLRP = LRP->left;
			RLRP = LRP->right;
		}

		RightLeft ( P , PP , P->right , P->right->left , P->right->left->left , P->right->left->right );

		updateHeight ( LLRP );
		updateHeight ( RLRP );

		updateHeight ( pivot );
		updateHeight ( RP );

		updateHeight ( LRP );
	}

	updateHeight ( PP );
}

template < class T >
void AVL<T>::RightLeft ( Node<T> * P , Node<T> * PP , Node<T> * RP , Node<T> * LRP , Node<T> * LLRP , Node<T> * RLRP )
{
	LRP->left = P;
	LRP->right = RP;

	P->right = LLRP;
	RP->left = RLRP;

	if ( PP )
	{
		if ( PP->left == P )
			PP->left = LRP;
		else
			PP->right = LRP;
	}
	else
		root = LRP;

	if ( PP == root )
		root = PP;
}

template < class T >
void AVL<T>::LeftRight ( Node<T> * P , Node<T> * PP , Node<T> * LP , Node<T> * RLP , Node<T> * LRLP , Node<T> * RRLP )
{
	RLP->left = LP;
	RLP->right = P;
	LP->right = LRLP;
	P->left = RRLP;

	if ( PP )
	{
		if ( PP->left == P )
			PP->left = RLP;
		else
			PP->right = RLP;
	}
	else
		root = RLP;

	if ( PP == root )
		root = PP;
}

template < class T >
void AVL<T>::RightRight ( Node<T> * P , Node<T> * PP , Node<T> * RP , Node<T> * LRP )
{
	RP->left = P;
	P->right = LRP;

	if ( PP )
	{
		if ( PP->left == P )
			PP->left = RP;
		else
			PP->right = RP;
	}
	else
		root = RP;

	if ( PP == root )
		root = PP;
}

template < class T >
void AVL<T>::LeftLeft ( Node<T> * P , Node<T> * PP , Node<T> * LP , Node<T> * RLP )
{
	LP->right = P;
	P->left = RLP;

	if ( PP )
	{
		if ( PP->left == P )
			PP->left = LP;
		else
			PP->right = LP;
	}
	else
		root = LP;

	if ( PP == root )
		root = PP;
}

template < class T >
AVL<T>::AVL ( )
{
	root = 0;
}

template < class T >
int AVL<T>::isEmpty ( ) const
{
	return root == 0;
}

template < class T >
Node<T> * AVL<T>::inOrderSuccessorNode ( T key ) const
{
	Node<T> * p = searchNode ( key );

	if ( p->right == 0 )
		return p;

	if ( p->right == 0 && p->left == 0 )
		return leafNodeInOrderSuccessor ( root , p , 0 );

	return inOrderSuccessor ( p->right );
}

template < class T >
Node<T> * AVL<T>::leafNodeInOrderSuccessor ( Node<T> * p , Node<T> * node , int f ) const
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
Node<T> * AVL<T>::inOrderSuccessor ( Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	Node<T> * temp = inOrderSuccessor ( p->left );

	if ( temp == 0 )
		temp = p;

	return temp;
}

template < class T >
void AVL<T>::insert ( T key )
{
	if ( isEmpty ( ) )
	{
		root = new Node<T> ( key );
		return;
	}

	stack< Node<T> * > s;

	Node<T> * p = root;

	while ( p != 0 )
	{
		s.push ( p );

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


	int f = 0;

	while ( !s.empty ( ) )
	{
		p = s.top ( );
		s.pop ( );

		updateHeight ( p );
		
		if ( f == 0 )
		{
			f = isBalanceFactorOut ( p );

			if ( f != 0 )
			{
				if ( !s.empty ( ) )
				{
					rotate ( s.top ( ) , p , f );

					//if( root == s.top ( ) )
						//root = s.top ( );
				}
				else
					rotate ( 0 , p , f );
			}
		}
	}
}

template < class T >
void AVL<T>::deleteNode ( T key )
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	stack< Node<T> * > s;
	Node<T> * p = root;

	while ( p != 0 )
	{
		if ( p->info == key )
			break;

		s.push ( p );

		if ( p->info <= key )
			p = p->right;
		else
			p = p->left;
	}

	deleteNode1 ( p->info );

	while ( !s.empty ( ) )
	{
		p = s.top ( );
		s.pop ( );

		updateHeight ( p );
		int f = isBalanceFactorOut ( p );

		if ( f != 0 )
		{
			if ( !s.empty ( ) )
				rotate ( s.top ( ) , p , f );
			else
				rotate ( 0 , p , f );
		}
	}
}

template < class T >
int AVL<T>::search ( T key ) const
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
Node<T> * AVL<T>::searchNode ( T key ) const
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
Node<T> * AVL<T>::searchParent ( T key ) const
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
void AVL<T>::deleteNode1 ( T key )
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * p = searchNode ( key );

	if ( p == 0 )
		throw exception ( "No match found" );

	Node<T> * parent = searchParent ( key );

	if ( p->left == 0 && p->right == 0 )
	{
		if ( p == root )
		{
			delete p;
			root = 0;
		}
		else if ( parent->left == p )
			parent->left = 0;
		else
			parent->right = 0;

		updateHeight ( parent );
	}
	else if ( ( p->left == 0 && p->right != 0 ) || ( p->right == 0 && p->left != 0 ) )
	{
		if ( p == root )
		{
			if ( p->left )
				root = p->left;
			else
				root = p->right;
		}
		else if ( parent->left == p )
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

		updateHeight ( p );
		updateHeight ( parent );
	}
	else
	{
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

			updateHeight ( parentOfSuccessor );
			updateHeight ( root );

			delete p;
			p = 0;

			return;
		}

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

		updateHeight ( p );
		updateHeight ( parent );

		updateHeight ( parentOfSuccessor );
		updateHeight ( successor );


	}

	delete p;
	p = 0;
}
