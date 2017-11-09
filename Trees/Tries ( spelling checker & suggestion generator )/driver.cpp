#include "spellCheck.h"

void main ( )
{
	try
	{
		SpellCheck s;
		char sentence[200];

		cout << "Enter a sentence : " ;
		cin.getline ( sentence , 200 );

		int i = 0 ;

		while ( sentence[i] != '\0' )
		{
			int j = 0;
			char word[20];

			while ( sentence[i+j] != '\0' && sentence[i+j] != ' ' )
			{
				word[j] = sentence[i+j];
				j++;
			}

			word[j] = '\0';

			string str ( word );

			if ( !s.search ( str.data ( ) ) )
			{
				cout << "\n\nIncorrect word...." << str << endl;
				cout << "Suggestions are : " << endl ;

				s.generateSuggestions ( str );

				cout << endl << endl;
			}

			if ( sentence[ i+j ] == '\0' )
				break;

			i += j;
			i++;
		}

	}

	catch ( exception & e )
	{
		cout << "Exception occurred : " << e.what ( ) << endl;
	}


}