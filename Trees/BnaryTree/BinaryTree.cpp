#include "BinaryTree.h"

template < class T >
BinaryTree<T>::BinaryTree ( )
{
	root = 0;
}

template < class T >
int BinaryTree<T>::isFull ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	return isFull ( root );
}

template < class T >
int BinaryTree<T>::isComplete ( ) const
{
	return isComplete ( root ) != -1;
}

template < class T >
int BinaryTree<T>::isComplete ( Node<T> * p ) const
{
	if ( p->left == 0 && p->right == 0 )
		return 0;

	if ( p->left == 0 && p->right != 0 )
		return 1;

	if ( p->left != 0 && p->right == 0 )
		return 2;

	//if ( p->left != 0 && p->right != 0 )
	//	return 3;

	int c1 = isComplete ( p->left );

	int c2;

	if ( c1 != - 1 )
		 c2 = isComplete ( p->right );
	else
		return c1;

	if ( c1 == 2 && ( c2 == 1 || c2 == 3 ) )
		return -1;

	if ( c1 == 3 && c2 == 1 )
		return -1;

	if ( c1 == 2 && c2 == 3 )
		return -1;

	if ( ( c1 == 1 || c1 == 3 ) && ( c2 == 1 ) )
		return -1;

	return 4;
}

template < class T >
int BinaryTree<T>::isFull ( Node<T> * p ) const
{
	if ( p->left == 0 && p->right == 0 )
		return 1;

	if ( ( p->left == 0 && p->right != 0 ) || ( p->left != 0 && p->right == 0 ) )
		return 0;

	int f = isFull ( p->left );

	if ( f == 1 )
		return isFull ( p->right );

	return f;
}

template < class T >
void BinaryTree<T>::nonRecPreOrder ( ) const
{
	stack< Node<T> * > s;
	Node <T> * p = root;

	int f = 1;

	while ( f )
	{
		while ( p )
		{
			cout << p->info << ' ';

			s.push ( p );
			p = p->left;
		}

		if ( !s.empty ( ) )
		{
			p = s.top ( );
			s.pop ( );
			p = p->right;
		}
		else
			f = 0;
	}
}

template < class T >
void BinaryTree<T>::nonRecInOrder ( ) const
{
	stack< Node<T> * > s;
	Node <T> * p = root;

	int f = 1;

	while ( f )
	{
		while ( p )
		{
			s.push ( p );
			p = p->left;
		}

		if ( !s.empty ( ) )
		{
			p = s.top ( );

			cout << p->info << ' ';

			s.pop ( );
			p = p->right;
		}
		else
			f = 0;
	}
}

template < class T >
void BinaryTree<T>::nonRecPostOrder ( ) const
{
	stack< Back<T> > s;
	Node <T> * p = root;

	int f = 1;

	while ( f )
	{
		while ( p )
		{
			s.push ( Back<T> ( p ) );
			p = p->left;
		}

		if ( !s.empty ( ) )
		{
			Back<T> b = s.top ( );
			p = b.ptr;
			s.pop ( );

			while ( b.f > 0 && b.ptr != 0 )
			{
				cout << p->info << ' ';

				if ( s.empty ( ) )
					break;

				b = s.top ( );
				p = b.ptr;
				s.pop ( );
			}

			if ( s.empty ( ) && b.f > 0 )
				f = 0;
			else
			{
				b.f = 1;
				s.push ( b );
				p = p->right;
			}
			
		}
		else
			f = 0;
	}
}

template < class T >
int BinaryTree<T>::countLeafNodes ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	return countLeafNodes ( root ) ;
}

template < class T >
int BinaryTree<T>::countLeafNodes ( Node <T > * p ) const
{
	if ( p->left == 0 && p->right == 0 )
		return 1;

	int count = countLeafNodes ( p->left );
	
	count += countLeafNodes ( p->right );

	return count;
}

template < class T >
T BinaryTree<T>::maxValue ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	return maxValue ( root );
}

template < class T >
T BinaryTree<T>::maxValue ( Node<T> * p ) const
{
	if ( p->left == 0 && p->right == 0 )
		return p->info;

	T max = p->info;

	T m = maxValue ( p->left );
	
	if ( m > max )
		max = m;

	m = maxValue ( p->right );

	if ( m > max )
		max = m;

	return max;
}

template < class T >
T BinaryTree<T>::minValue ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	return minValue ( root );
}

template < class T >
T BinaryTree<T>::minValue ( Node<T> * p ) const
{
	if ( p->left == 0 && p->right == 0 )
		return p->info;

	T min = p->info;

	T m = minValue ( p->left );
	
	if ( m < min )
		min = m;

	m = minValue ( p->right );

	if ( m < min )
		min = m;

	return min;
}

template < class T >
BinaryTree<T> BinaryTree<T>::mirrorImage ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	BinaryTree<T> bt;

	bt.root = new Node<T> ( root->info );

	bt.root->left = copy ( root->right );
	bt.root->right = copy ( root->left );

	return bt;
}

template < class T >
int BinaryTree<T>::operator == ( const BinaryTree<T> & bt ) const
{
	return isEqual ( root , bt.root );
}

template < class T >
int BinaryTree<T>::isEqual ( Node<T> * p1 , Node<T> * p2 ) const
{
	if ( p1 == 0 && p2 == 0 )
		return 1;
	
	if ( ( p1 == 0 && p2 != 0 ) || ( p1 != 0 && p2 == 0 ) )
		return 0;

	if ( p1->info != p2->info )
		return 0;

	int f = isEqual ( p1->left , p2->left );

	if ( f == 1 )
		f = isEqual ( p1->right , p2->right );

	return f;
}

template < class T >
int BinaryTree<T>::noOfNodes ( ) const
{
	return noOfNodes ( root );
}

template < class T >
int BinaryTree<T>::noOfNodes ( Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	int height = noOfNodes ( p->left );
	height += noOfNodes ( p->right );

	return ++height;
}

template < class T >
void BinaryTree<T>::displayDscendents ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	int f = displayDscendents ( key , root );

	if ( f == 0 )
		throw NoMatchFound ( "No match found" );
}

template < class T >
int BinaryTree<T>::displayDscendents ( T key , Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	if ( p->info == key )
		return 1;
	
	int f = displayDscendents ( key , p->left );

	if ( f == 0 )
		f = displayDscendents ( key , p->right );

	if ( f == 1 )
	{
		cout << p->info << ' ';
	}

	return f;
}

template < class T >
int BinaryTree<T>::heightOfTree ( ) const
{
	return heightOfTree ( root );
}

template < class T >
int BinaryTree<T>::heightOfTree ( Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	int max = 0;

	int height = heightOfTree ( p->left );

	if ( max < height )
		max = height;

	height = heightOfTree ( p->right );

	if ( max < height )
		max = height ;

	return ++max;
}

template < class T >
void BinaryTree<T>::levelOrder ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * p = root;
	
	queue< Node<T> * > q;

	while ( p )
	{
		cout << p->info << ' ';
		
		q.push ( p->left );
		q.push ( p->right );

		p = q.front ( );
		q.pop ( );
	}
}

template < class T >
BinaryTree<T>::BinaryTree ( const BinaryTree<T> & bt ) 
{
	root = copy ( bt.root );
}

template < class T >
const BinaryTree<T> & BinaryTree<T>::operator = ( const BinaryTree<T> & bt ) 
{
	if ( this == &bt )
		return *this;

	if ( !isEmpty ( ) )
		deleteNode ( root->info );

	root = 0;

	root = copy ( bt.root );

	return *this;
}

template < class T > 
Node<T> * BinaryTree<T>::copy ( Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	Node<T> * temp = new Node<T>( p->info );

	temp->left = copy ( p->left );
	temp->right = copy ( p->right);
	return temp;
}

template < class T >
int BinaryTree<T>::isInternalNode ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node <T> * p = search ( key , root );

	if ( p == 0 )
		throw NoMatchFound ( "No match found" );

	if ( p->left != 0 || p->right != 0 )
		return 1;

	return 0;
}

template < class T >
int BinaryTree<T>::isExternalNode ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is Empty" );

	return isInternalNode ( key ) == 0 ;
}

template < class T >
T BinaryTree<T>::findSiblingNode ( T key ) const
{
	if ( isEmpty ( ) )
		throw NoMatchFound ( "No match found" );

	if ( root->info == key )
		throw NoSiblingExist ( "No sibling exist" );

	Node<T> * p = searchParent ( key , root );

	if ( p == 0 )
		NoMatchFound ( "No match found" );

	if ( p->left->info == key && p->right )
		return p->right->info;
	else if ( p->right->info == key && p->left )
		return p->left->info;
	else
	throw NoSiblingExist ( "No sibling exist" );
}

template < class T >
void BinaryTree<T>::setRoot ( T info )
{
	if ( isEmpty ( ) )
		root = new Node<T> ( info );
	else
		root->info = info;
}

template < class T >
void BinaryTree<T>::setLeftChild ( T key , T info ) 
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * ptr = search ( key , root );

	if ( ptr == 0 )
		throw NoMatchFound ( "No match found" );

	if ( ptr->left )
		ptr->left->info = info;
	else
		ptr->left = new Node<T> ( info );
}

template < class T >
T BinaryTree<T>::getLeftChild ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * ptr = search ( key , root );

	if ( ptr == 0 )
		throw NoMatchFound ( "No match found" );

	if ( ptr->left )
		return ptr->left->info;
	else
		throw NoChildExist ( "No left child exist" );	
}

template < class T >
void BinaryTree<T>::setRightChild ( T key , T info ) 
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * ptr = search ( key , root );

	if ( ptr == 0 )
		throw NoMatchFound ( "No match found" );

	if ( ptr->right )
		ptr->right->info = info;
	else
		ptr->right = new Node<T> ( info  );
}

template < class T >
void BinaryTree<T>::displayIndentedViewFromFile ( ifstream & inFile ) const
{
	if ( inFile == 0 )
		throw FileNotOpened ( "File not opened" );

	char ch;
	int count = 0;

	while ( inFile >> ch )
	{
		if ( ch == '(' )
			count++;
		else if ( ch == ')' )
			count--;
		else if ( ch != ',' )
		{
			for ( int i = 0 ; i < count - 1 ; i++ )
				cout << '\t' ;

			cout << ch << endl;
		}
	}
}

template < class T >
void BinaryTree<T>::printAncestors ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );
	
	queue<T> q;
	printAncestors ( root , key , q );
}

template < class T >
int BinaryTree<T>::printAncestors ( Node<T> * p , T key , queue<T> & q  ) const
{
	if ( p == 0 )
		return 0;

	if ( p->info == key )
		return 1;

	if ( p->info == 'e' )
	{
		cout << "";
	}

	//cout << " a : " << p->info << endl;

	q.push ( p->info );

	int f = printAncestors ( p->left , key , q );

	if ( f == 0 )
		f = printAncestors ( p->right , key , q );
	
	if ( f == 0 )
	{
		q.pop ( );
		cout << "poping : " << endl << endl;
		return 0;
	}
	else
	{
		cout << q.front ( ) << endl;
		q.pop ( );
		return f;
	}
}

template < class T >
int BinaryTree<T>::levelOfNode ( T key ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	return levelOfNode ( root , key , 0 );
}

template < class T >
int BinaryTree<T>::levelOfNode ( Node<T> * p ,  T key , int count ) const
{
	if ( p == 0 )
		return 0;

	if ( p->info == key )
		return count + 1;

	int f = levelOfNode ( p->left , key , count + 1 );

	if ( f == 0 )
		return levelOfNode ( p->right , key , count + 1 );

	return f;
}

template < class T >
void BinaryTree<T>::readFromFile ( ifstream & inFile ) 
{
	if ( inFile == 0 )
		throw FileNotOpened ( "File not opened" );

	char ch;

	inFile >> ch;

	root = readFile ( inFile );

	inFile >> ch;
}

template < class T > 
Node<T> * BinaryTree<T>::readFile ( ifstream & inFile )
{
	char ch;

	if ( ( inFile >> ch ) == 0 )
		return 0;

	if ( ch == ')' )
	{
		inFile >> ch;
		return 0;
	}

	if ( ch == ',' )
		return 0;

	Node<T> * temp = new Node<T> ( ch );

	inFile >> ch;

	if ( ch == ')' )
	{
		inFile >> ch;
		return temp;
	}

	if ( ch == ',' )
		return temp;

	if ( ch == '(' )
		temp->left = readFile ( inFile );

	temp->right = readFile ( inFile );

	return temp;
}

template < class T >
void BinaryTree<T>::writeToFile ( ofstream & outFile ) const
{
	if ( outFile == 0 )
		throw FileNotOpened ( "File not opened" );

	outFile << '(';

	writeToFile ( outFile , root );

	outFile << ')';
}

template < class T >
void BinaryTree<T>::writeToFile ( ofstream & outFile , Node<T> * ptr ) const
{
	if ( ptr == 0 )
		return;
	
		outFile << ptr->info;

		if ( ! ( ptr->left == 0 && ptr->right == 0 ) )
			outFile << '(';

		writeToFile ( outFile , ptr->left );
	
		if ( ! ( ptr->left == 0 && ptr->right == 0 ) )
			outFile << ',';

		writeToFile ( outFile , ptr->right );

		if ( ! ( ptr->left == 0 && ptr->right == 0 ) )
			outFile << ')';
}

template < class T >
void BinaryTree<T>::displayParenthesizeView ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	cout << '(';

	displayParenthesizeView ( root );

	cout << ')';
}

template < class T >
void BinaryTree<T>::displayParenthesizeView ( Node<T> * ptr ) const
{
	if ( ptr == 0 )
		return;
	
		cout << ptr->info;

		if ( ! ( ptr->left == 0 && ptr->right == 0 ) )
			cout << '(';

		displayParenthesizeView ( ptr->left );
	
		if ( ! ( ptr->left == 0 && ptr->right == 0 ) )
			cout << ',';

		displayParenthesizeView (  ptr->right );

		if ( ! ( ptr->left == 0 && ptr->right == 0 ) )
			cout << ')';
}

template < class T >
void BinaryTree<T>::preOrder ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	preOrder ( root );
}

template < class T >
void BinaryTree<T>::preOrder ( Node<T> * ptr ) const
{
	if ( ptr == 0 )
		return ;

	cout << ptr->info << ' ';
	
	preOrder ( ptr->left );
	preOrder ( ptr->right );
}

template < class T >
void BinaryTree<T>::inOrder ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	inOrder ( root );
}

template < class T >
void BinaryTree<T>::inOrder ( Node<T> * ptr ) const
{
	if ( ptr == 0 )
		return ;
	
	inOrder ( ptr->left );

	cout << ptr->info << ' ';

	inOrder ( ptr->right );
}

template < class T >
void BinaryTree<T>::postOrder ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	postOrder ( root );
}

template < class T >
void BinaryTree<T>::postOrder ( Node<T> * ptr ) const
{
	if ( ptr == 0 )
		return ;
	
	postOrder ( ptr->left );

	cout << ptr->info << ' ';

	postOrder ( ptr->right );
}

template < class T >
T BinaryTree<T>::getRightChild ( T key  ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	Node<T> * ptr = search ( key , root );

	if ( ptr == 0 )
		throw NoMatchFound ( "No match found" );

	if ( ptr->right )
		return ptr->right->info ;
	else
		throw NoChildExist ( "No right child exist" );
}

template < class T >
void BinaryTree<T>::deleteNode ( T key )
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	if ( root->info == key )
	{
		erase ( root );
		return;
	}

	Node<T> * ptr = searchParent ( key , root );

	if ( ptr == 0 )
		throw NoMatchFound ( "No match found" );
	
	if ( ptr->left->info == key )
	{
		erase ( ptr->left );
		ptr->left = 0;
	}
	else
	{
		erase ( ptr->right );
		ptr->right = 0;
	}
}

template < class T >
void BinaryTree<T>::erase ( Node<T> * ptr )
{
	if ( ptr == 0 )
		return;

	erase ( ptr->left );
	erase ( ptr->right );

	delete ptr;
	ptr = 0;
}

template < class T >
bool BinaryTree<T>::isEmpty ( ) const
{
	return root == 0;
}

template < class T >
Node<T> * BinaryTree<T>::search ( T key , Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	if ( p->info == key )
		return p;

	Node<T> * q = search ( key , p->left );

	if ( q == 0 )
		return search ( key , p->right );
	
	return q;
}

Node<T> * getParent ( T key )
{
	return searchParent ( key , root );
}

template < class T >
Node<T> * BinaryTree<T>::searchParent ( T key , Node<T> * p ) const
{
	if ( p == 0 )
		return 0;

	if ( p->left && p->left->info == key )
		return p;
	else if ( p->right && p->right->info == key  )
		return p;

	Node<T> * q = searchParent ( key , p->left );

	if ( q == 0 )
		return searchParent ( key , p->right );

	return q;
}