#include <iostream>
#include <string>
using namespace std;

#include "NoMatchFound.h"
#include "TreeEmpty.h"

struct TNode;

struct ChildNode
{
	ChildNode * nextsib;
	TNode * nextChild;

	ChildNode ( )
	{
		nextsib = 0;
		nextChild = 0;
	}

	ChildNode ( TNode * child , ChildNode * sibling )
	{
		nextChild = child;
		nextsib = sibling;
	}
};

struct ChildList
{
	ChildNode * childListHead;
	
	ChildList ( )
	{
		childListHead = 0;
	}
};

struct TNode
{
	int flagFF;
	int size;

	string fname;
	ChildList childList;

	TNode ( )
	{
		flagFF = 0;
		size = 1;
		fname[0] = '\0';
	}

	TNode ( string name , int f )
	{
		fname = name;
		flagFF = f;
		size = 1;
	}
};

class KAryTree
{
	TNode * root;
	mutable TNode * current;

	int size ( TNode * p ) const;
	TNode * findNode ( TNode * p , string name ) const;

	TNode * findNode ( string * name , int n ) const;
	int isEmpty ( ) const;

	void traverse ( TNode * root , string path ) const;
	void expandedView ( TNode * root , int ) const;

	void displayParenthesizedView ( TNode * root ) const;

	TNode * copy ( TNode * root ) const;

	void deleteNode ( TNode * p ) const;
	ChildNode * searchParent ( TNode * p , string name ) const;

	public:

		KAryTree ( )
		{
			root = current = 0;
		}

		KAryTree ( const KAryTree & k );
		~KAryTree ( );

		void setRoot ( string name , int f );
		int findSize ( string path = "" ) const;

		void setChild ( string key , string name , int f );

		void traverse ( ) const;
		void expandedView ( string path = "" ) const;

		void displayParenthesizedView ( string path = ""  ) const;

		int isFound ( string path ) const;

		void deleteFile ( string path ) ;
};