#include "KAryTree.h"

void KAryTree::deleteFile ( string path ) 
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );
	
	int noOfNames = 0;
	int i = 0;

	while ( path[i] != '\0' )
	{
		if ( path[i] == '\\' )
			noOfNames++;

		i++;
	}

	string * names = new string[noOfNames];

	i = 0;
	int j = 0;

	while ( path[i] != '\0' )
	{
		if ( path[i] == '\\' )
		{
			j++;

		}
		else
			names[j] += path[i];

		i++;
	}

	TNode * p = 0;
	
	if ( noOfNames > 1 )
		p = findNode ( names , noOfNames - 1 );
	else if ( root->childList.childListHead && root->childList.childListHead->nextChild->fname == names[noOfNames - 1] )
	{
		ChildNode * head = root->childList.childListHead;
		
		root->childList.childListHead = head->nextsib;
		delete ( head->nextChild );
		delete head;

		head = 0;
		return;
	}
	else 
	{
		deleteNode ( root );
		return;
	}


	if ( p->childList.childListHead && p->childList.childListHead->nextChild->fname == names[noOfNames - 1] )
	{
		ChildNode * head = p->childList.childListHead;
		
		p->childList.childListHead = head->nextsib;
		delete ( head->nextChild );
		delete head;

		head = 0;
		return;
	}


	ChildNode * child = searchParent ( p , names[noOfNames -1] );

	if ( child == 0 )
		throw NoMatchFound ( "No match found" );
		
	deleteNode ( child->nextsib->nextChild );

	ChildNode * temp2 = child->nextsib;

	if ( child->nextsib )
		child->nextsib = child->nextsib->nextsib;

	delete temp2;
}

ChildNode * KAryTree::searchParent ( TNode * p , string name ) const
{
	if ( p == 0 )
		return 0;

	ChildNode * temp = p->childList.childListHead;

	if (temp && temp->nextsib && temp->nextsib->nextChild && temp->nextsib->nextChild->fname == name )
		return temp;

	ChildNode * temp1 = 0;
	while ( temp != 0 )
	{
		temp1 = searchParent ( temp->nextChild , name );

		if ( temp1 != 0 )
			return temp1;

		temp = temp->nextsib;
	}

	return temp1;
}

KAryTree::KAryTree ( const KAryTree & k )
{
	root = copy ( k.root );

	current = findNode ( root , k.current->fname ); 
}

void KAryTree::deleteNode ( TNode * p ) const
{
	if ( p == 0 )
		return;

	ChildNode * temp = p->childList.childListHead;

	while ( temp != 0 )
	{
		deleteNode ( temp->nextChild );
		
		ChildNode * toDie = temp;
		temp = temp->nextsib ;

		delete toDie;
	}

	delete p;
}

KAryTree::~KAryTree ( )
{
	if ( root )
	{
		deleteNode ( root );
		root =0 ;
		current = 0;
	}
}

TNode * KAryTree::copy ( TNode * p ) const
{
	if ( p == 0 )
		return 0;

	TNode * temp = new TNode ( p->fname , p->flagFF );

	ChildNode * t = p->childList.childListHead;
	
	if ( t )
		temp->childList.childListHead = new ChildNode;

	ChildNode * t1 = temp->childList.childListHead;

	while ( t != 0 )
	{
		t1->nextChild = copy ( t->nextChild );

		t = t->nextsib;

		if ( t )
		{
			t1->nextsib = new ChildNode;
		}

		t1 = t1->nextsib ;
	}

	return temp;
}

void KAryTree::setRoot ( string name , int f )
{
	if ( isEmpty ( ) )
	{
		root = new TNode ( name , f );
		current = root;
		return;
	}

	root->fname = name;
	root->flagFF = f;
}

int KAryTree::isEmpty ( ) const
{
	return root == 0;
}

int KAryTree::findSize ( string path ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	if ( path.empty ( ) )
		return size ( current );

	int noOfNames = 0;
	int i = 0;

	while ( path[i] != '\0' )
	{
		if ( path[i] == '\\' )
			noOfNames++;

		i++;
	}

	string * names = new string[noOfNames];

	i = 0;
	int j = 0;

	while ( path[i] != '\0' )
	{
		if ( path[i] == '\\' )
		{
			j++;

		}
		else
			names[j] += path[i];

		i++;
	}

	TNode * p = findNode ( names , noOfNames );
	current = p;

	return size ( p );

}

void KAryTree::setChild ( string key , string name , int f ) 
{
	if ( isEmpty ( ) )
		throw NoMatchFound ( "No match found" );

	TNode * temp = findNode ( root , key );

	if ( temp == 0 )
		throw NoMatchFound ( "No match found" );

	ChildNode * ptr = temp->childList.childListHead;

	TNode * p = new TNode ( name , f );

	if ( ptr == 0 )
	{
		temp->childList.childListHead = new ChildNode ( p , 0 );
		return;
	}

	while ( ptr->nextsib != 0 )
		ptr = ptr->nextsib ;

	ptr->nextsib = new ChildNode ( p , 0 );
}

int KAryTree::size ( TNode * p ) const
{
	if ( p == 0 )
		return 0;

	int s = p->size ;

	ChildNode * temp = p->childList.childListHead;

	while ( temp  != 0 )
	{
		s += size ( temp->nextChild );
		temp = temp->nextsib ;
	}

	return s;
}

TNode * KAryTree::findNode ( TNode * p , string name ) const
{
	if ( p == 0 )
		return 0;

	if ( p->fname == name )
		return p;

	TNode * temp = 0;
	ChildNode * ptr = p->childList.childListHead;

	while ( ptr != 0 )
	{
		temp = findNode ( ptr->nextChild , name );

		if ( temp == 0 )
			ptr = ptr->nextsib;
		else
			return temp;
	}

	return temp;
}

TNode * KAryTree::findNode ( string * name , int n ) const
{
	int i = 0;
	TNode * temp = root;

	while ( i < n )
	{
		temp = findNode ( temp , name[i] );
		
		if ( temp == 0 )
			return 0;

		i++;
	}

	return temp;
}

void KAryTree::traverse ( ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	traverse ( root , root->fname );
}

void KAryTree::traverse ( TNode * p , string path ) const
{
	if ( p == 0 )
		return;

	cout << "Type : " << ( ( p->flagFF == 0 ) ? "Folder" : "File" ) << endl;
	cout << "Size : " << p->size << "kb" << endl;
	cout << "Name : " << p->fname << endl ;

	cout << "Path : " ;

	if ( path != p->fname )
		cout << path << "\\" << p->fname << "\\";
	else
		cout << path << "\\" ;
	
	cout << endl << endl;

	ChildNode * temp = p->childList.childListHead;

	while ( temp  != 0 )
	{
		if ( path != p->fname )
			traverse ( temp->nextChild , ( path + "\\" + p->fname )  );
		else
			traverse ( temp->nextChild , path );

		temp = temp->nextsib ;
	}
}

void KAryTree::expandedView ( string path ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	if ( path.empty ( ) )
		expandedView ( current , 0 );

	int i = path.length ( ) - 2 ;

	string name;
	while ( i >= 0 && path[i] != '\\' )
	{
		name += path[i];
		i--;
	}

	string name1;

	i = name.length ( ) - 1;
	
	while ( i >= 0 )
	{
		name1 += name[i];
		i--;
	}

	TNode * p = findNode ( root , name1 );

	expandedView ( p , 0 );
}

void KAryTree::expandedView ( TNode * p , int count ) const
{
	if ( p == 0 )
		return;

	for ( int i = 0 ; i < count ; i++ )
		cout << "\t";
	
	cout << p->fname << endl;

	ChildNode * temp = p->childList.childListHead ;

	while ( temp != 0 )
	{
		expandedView ( temp->nextChild , count + 1 );
		temp = temp->nextsib;
	}
}

void KAryTree::displayParenthesizedView ( string path ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree empty" );

	if ( path.empty ( ) )
		displayParenthesizedView ( current );

	int i = path.length ( ) - 2 ;

	string name;
	while ( i >= 0 && path[i] != '\\' )
	{
		name += path[i];
		i--;
	}

	string name1;

	i = name.length ( ) - 1;
	
	while ( i >= 0 )
	{
		name1 += name[i];
		i--;
	}

	TNode * p = findNode ( root , name1 );
	displayParenthesizedView ( p );
}

void KAryTree::displayParenthesizedView ( TNode * p ) const
{
	if ( p == 0 )
		return;

	cout << p->fname;

	ChildNode * temp = p->childList.childListHead ;

	if ( temp )
		cout << "(";

	while ( temp != 0 )
	{
		 displayParenthesizedView ( temp->nextChild  );
		temp = temp->nextsib;

		if ( temp )
			cout << ",";
		else
			cout << ")";
	}
}

int KAryTree::isFound ( string path ) const
{
	if ( isEmpty ( ) )
		throw TreeEmpty ( "Tree is empty" );

	if ( path.empty ( ) )
		return size ( current );

	int noOfNames = 0;
	int i = 0;

	while ( path[i] != '\0' )
	{
		if ( path[i] == '\\' )
			noOfNames++;

		i++;
	}

	string * names = new string[noOfNames];

	i = 0;
	int j = 0;

	while ( path[i] != '\0' )
	{
		if ( path[i] == '\\' )
		{
			j++;

		}
		else
			names[j] += path[i];

		i++;
	}

	TNode * p = findNode ( names , noOfNames );
	
	if ( p == 0 )
		return 0;

	return 1;
}