# include <iostream>
# include <fstream>
# include <string.h>
# include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <fstream>

using namespace std;

#include "Exceptions.h"

struct Trie;

struct Node
{
	char ch;
	bool end;
	Trie *next;

	Node(  )
	{
		ch = '$';
		end = 0;
		next = 0;
	}
};

struct Trie
{
	Node arr[26];
};

class SpellCheck
{
	Trie * root;

	bool isEmpty ( ) const;
	void buildDictionary ( ) ;

	
	bool isValid ( const string & str , vector<char> & v ) const;
	void generateSuggestions ( Trie * root ,  const string & str , vector<char> & v ) const;

	void deleteTrie ( Trie * root );

	public:

		SpellCheck ( );
		~SpellCheck ( );

		void insert( const char * str );
		bool search ( const char * str ) const;

		void generateSuggestions ( const string & str ) const;

};