#include <iostream>
#include <string>
using namespace std;

#include "stack.cpp"

int isValid ( string );
int isOpeningBracket ( char );

int isClosingBracket ( char );
string evaluateToPrefix ( string );

int isOperand ( char );
int isOperator ( char );

int precedence ( char );
string evaluatePrefixExpression ( string );

void main ( )
{
	string s ( "a * b / d" );

	try
	{
		if ( isValid ( s ) )
			cout << "Valid" << endl;
		else 
			cout << "Invalid" << endl;
		
		string result = evaluateToPrefix ( s );

		cout << " postfix : " << result << endl;
		cout << " Infix : " << evaluatePrefixExpression ( result ) << endl;
	}

	catch ( exception & e )
	{
		cout << "Exception occurred : " << e.what ( ) << endl;
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

string evaluatePrefixExpression ( string str )
{
	int i = str.length ( ) - 1;
	Stack<string> operandStack;

	while ( i >= 0 )
	{
		if ( isOperand ( str[i] ) )
		{
			char ch[2] = { str[i] , '\0' };
			operandStack.push ( ch );
		}
		else if ( isOperator ( str[i] ) )
		{
			string op1 = operandStack.pop ( );
			string op2 = operandStack.pop ( );

			operandStack.push ( op1 + str[i] + op2 );
		}

		i--;
	}

	return operandStack.pop ( );
}

string evaluateToPrefix ( string str )
{
	Stack<char> operatorStack;
	Stack<string> operandStack;

	int i = 0;

	while ( str[i] != '\0' )
	{
		if ( isOperand ( str[i] ) )
		{
			char ch[2] = { str[i] , '\0' };
			operandStack.push ( ch  );
		}
		else if ( isOpeningBracket ( str[i] ) )
			operatorStack.push ( str[i] );
		else if ( isOperator ( str[i] ) )
		{
			while ( !operatorStack.isEmpty ( ) && precedence ( operatorStack.stackTop ( ) ) >= 
				precedence ( str[i] ) )
			{
				char operatr = operatorStack.pop ( );

				if ( !isOpeningBracket ( operatr ) )
				{
					string s2 = operandStack.pop ( );
					string s1 = operandStack.pop ( );
					
					operandStack.push ( operatr + s1 + s2 );
				}
			}

			if ( !isClosingBracket ( str[i] ) )
			{
				operatorStack.push ( str[i] );
			}
		}
		
		
		i++;
	}

	while ( !operatorStack.isEmpty ( ) )
	{
		char operatr = operatorStack.pop ( );
		string s2 = operandStack.pop ( );
		string s1 = operandStack.pop ( );

		operandStack.push ( operatr + s1 + s2 );
	}

	return operandStack.pop ( );
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