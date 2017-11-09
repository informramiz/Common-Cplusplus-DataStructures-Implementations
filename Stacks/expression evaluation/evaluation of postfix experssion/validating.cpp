#include <iostream>
#include <string>
using namespace std;

#include "stack.cpp"

int isValid ( string );
int isOpeningBracket ( char );

int isClosingBracket ( char );
string evaluateToPostfix ( string );

int isOperand ( char );
int isOperator ( char );

int precedence ( char );
string evaluatePostfixExpression ( string );

void main ( )
{
	string s ( "a * b / d" );

	try
	{
		if ( isValid ( s ) )
			cout << "Valid" << endl;
		else 
			cout << "Invalid" << endl;
		
		string result = evaluateToPostfix ( s );

		cout << " postfix : " << result << endl;
		cout << " Infix : " << evaluatePostfixExpression ( result ) << endl;
	}

	catch ( exception & e )
	{
		cout << "Execption occurred : " << e.what ( ) << endl;
	}
}

int isValid ( string str )
{
	int i = 0;
	Stack<int> s;

	while ( str[i] != '\0' )
	{
		if ( isOpeningBracket ( str[i] ) )
				s.push ( str[i] );
		else if ( isClosingBracket ( str[i] ) )
		{
			if ( s.isEmpty ( ) )
				return 0;
			else if ( s.stackTop ( ) == '(' )
				s.pop ( );
			else
				return 0;
		}

		i++;
	}

	if ( s.isEmpty ( ) )
		return 1;

	return 0;
}

string evaluatePostfixExpression ( string str )
{
	int i = 0;
	Stack<string> operandStack;

	while ( str[i] != 0 )
	{
		if ( isOperand ( str[i] ) )
		{
			char ch[2] = { str[i] , '\0' };
			operandStack.push ( ch );
		}
		else if ( isOperator ( str[i] ) )
		{
			string op2 = operandStack.pop ( );
			string op1 = operandStack.pop ( );

			operandStack.push ( op1 + str[i] + op2 );
		}

		i++;
	}

	return operandStack.pop ( );
}

string evaluateToPostfix ( string str )
{
	Stack<char> stack;
	string result;
	int i = 0;

	while ( str[i] != '\0' )
	{
		if ( isOperand ( str[i] ) )
		{
			result += str[i];
		}
		else if ( isOpeningBracket ( str[i] ) )
			stack.push ( str[i] );
		else if ( isOperator ( str[i] ) )
		{
			while ( !stack.isEmpty ( ) && precedence ( stack.stackTop ( ) ) >= 
				precedence ( str[i] ) )
			{
				char character = stack.pop ( );

				if ( !isOpeningBracket ( character ) )
					result += character;
			}

			if ( !isClosingBracket ( str[i] ) )
			{
				stack.push ( str[i] );
			}
		}
		
		
		i++;
	}

	while ( !stack.isEmpty ( ) )
	{
		result += stack.pop ( );
	}

	return result;
}

int precedence ( char ch )
{
	if ( ch == '(' || ch == ')' )
		return 0;
	else if ( ch == '=' )
		return 1;
	else if ( ch == '+' || ch == '-' )
		return 2;
	else if ( ch == '/' || ch == '%' || ch == '*' )
		return 3;

	return -1;
}

int isOperand ( char ch )
{
	return ( ch >= 'A' && ch <= 'z' );
}

int isOperator ( char ch )
{
	return ( ch >= '!' && ch <= '/' );
}

int isOpeningBracket ( char ch )
{
	if ( ch == '(' )
		return 1;

	return 0;
}

int isClosingBracket ( char ch )
{
	if ( ch == ')' )
		return 1;

	return 0;
}