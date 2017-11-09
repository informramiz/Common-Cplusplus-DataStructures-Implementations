#include "spellCheck.h"

SpellCheck::SpellCheck ( ) 
{
	root = 0;

	buildDictionary ( );
}

bool SpellCheck::isEmpty ( ) const
{
	return root == 0;
}

void SpellCheck::deleteTrie ( Trie * p ) 
{
	if ( p == 0 )
		return;

	for ( int i = 0 ; i < 26 ; i++ )
		deleteTrie ( p->arr[i].next );

	delete  p;
	p = 0;
}

SpellCheck::~SpellCheck ( )
{
	if ( root )
	{
		deleteTrie ( root );
		root = 0;
	}
}

void SpellCheck::generateSuggestions ( const string & str ) const
{
	if ( str.length ( ) == 0 )
		return ;

	int index = str[0];
	
	if ( islower ( str[0] ) )
		index = toupper ( str[0] ) ;

	index = index - 'A';

	vector<char> v;
	v.push_back ( str[0] );

	generateSuggestions ( root->arr[index].next , str , v );
}

void SpellCheck::generateSuggestions ( Trie * p , const string & str , vector<char> & v ) const
{
	if ( p == 0 )
	{
		return;
	}

	int counter = 0;

	for ( int i = 0 ; i < 26 ; i++ )
	{
		if ( p->arr[i].ch == '$' )
			continue;

		v.push_back ( p->arr[i].ch );
		counter++;


		if ( p->arr[i].end == 1 )
		{
			if ( isValid ( str , v ) )
			{
				for ( int j = 0 ; j < v.size ( ) ; j++ )
					cout << v[j];

				cout << endl;
			}
		}

		if ( str.length ( ) < v.size ( ) - 1 )
		{
			v.pop_back ( );
			return;
		}
		
		generateSuggestions ( p->arr[i].next , str , v );

		v.pop_back ( );
	}
}

bool SpellCheck::isValid ( const string & str , vector<char> & v ) const
{


	int d = 0;

	int flag = 0;

	if ( str.length ( ) > v.size ( ) )
		flag = 1;

	int f[26] = {0};

	if ( flag == 0 )
	{

		for ( int i = 0 ; i < str.length ( ) ; i++ )
		{
			int index = str[i];

			if ( islower ( str[i] ) )
				index = toupper ( str[i] );

			index = index - 'A';

			f[index]++;
		}

		for ( i = 0 ;  i < v.size ( ) ; i++ )
		{
			
			int index = v[i];

			if ( islower ( v[i] ) )
				index = toupper ( v[i] );

			index = index - 'A';

			if ( f[index] == 0 )
				d++;
			else
				f[index]--;

			if ( d > 1 )
				return 0;
		}
	}
	else
	{
		for ( int i = 0 ; i < v.size ( ) ; i++ )
		{
			int index = v[i];

			if ( islower ( v[i] ) )
				index = toupper ( v[i] );

			index = index - 'A';

			f[index]++;
		}

		for ( i = 0 ; i < str.length ( ) ; i++ )
		{
			
			int index = str[i];

			if ( islower ( str[i] ) )
				index = toupper ( str[i] );

			index = index - 'A';

			if ( f[index] == 0 )
				d++;
			else
				f[index]--;

			if ( d > 1 )
				return 0;
		}
	}

	return 1;
}

void SpellCheck::buildDictionary ( ) 
{
	ifstream inFile ( "in.txt" );

	char  str[2000];

	while ( !inFile.eof ( ) && inFile.getline ( str , 2000 ) )
	{
		insert ( str );
	}

	inFile.close ( );
}

bool SpellCheck::search ( const char * str ) const
{
	if ( isEmpty ( ) )
		throw TrieEmpty ( "there are no words in dictionary" );

	int len = strlen ( str );

	if ( len == 1 )
		return 1;

	int i = 0;
	Trie * p = root;

	int index = 0;

	while ( p != 0 && str[i] != '\0' )
	{
		if ( islower ( str[i] ) )
			index = toupper ( str[i] ) - 'A';
		else
			index = str[i] - 'A';

		if ( p->arr[ index ].ch == '$' )
			return 0;

		i++;

		if ( str[i] == '\0' && p->arr[index].end == 1 )
			return 1;

		p = p->arr[ index ].next ;
	}

	if ( p == 0 )
		return 0;

	if ( p->arr[ index ].end != 1 )
		return 0;

	return 1;
		
}

void SpellCheck :: insert( const char * str )
{
	if ( isEmpty ( ) )
		root = new Trie;

	int i = 0;
	Trie *ptr = root;

	int index = 0;
	char space = ' ';

	while( str[i] != '\0' )
	{
		if ( str[i] == space )
		{
			i++;
			ptr->arr[index].end = 1;
			
			ptr = root;
			continue;
		}
		
		if ( islower ( str[i] ) )
			index = toupper ( str[i] ) - 'A';
		else
			index = str[i] - 'A';

		ptr->arr[index].ch = str[i];

		if( ptr->arr[index].next == 0 && ( str[i+1] != '\0' && str[i+1] != space ) )
		{
			ptr->arr[index].next = new Trie;

			ptr = ptr->arr[index].next;
		}
		else if ( str[i+1] != '\0' && str[i+1] != space )
		{
			ptr = ptr->arr[index].next;
		}

		i++;
	}

	ptr->arr[index].end = 1;
}


