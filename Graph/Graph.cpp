#include "Graph.h"

Graph::Graph ( int v )
{
	if ( v <= 0 )
		throw InvalidNumberOfVertices ( "Invalid number of vertices" );

	vertices = v;
	m = new int[vertices * vertices];

	for ( int i = 0 ; i < vertices * vertices ; i++ )
		m[i] = 0;

	visited = 0;
}

void Graph::DFS ( ) const
{
	visited = new int[vertices];

	for ( int i = 0 ; i < vertices ; i++ )
		visited[i] = 0;

	for ( i = 0 ; i < vertices ; i++ )
		if ( visited[i] == 0 )
			DFS ( i );

	delete [ ] visited;
	visited = 0;
}

void Graph::DFS ( int i ) const
{
	visited[i] = 1;
	//cout << i << ' ';

	if ( i == 3 )
	{
		cout << "";
	}

	for ( int j = 0 ; j < vertices ; j++ )
		if ( visited[j] == 0 && matrix ( i , j ) )
			DFS ( j );
}

void Graph::displayVisited ( ) const
{
	for ( int i = 0 ; i < vertices ; i++ )
		if ( visited[i] == 1 )
		{
			cout << i << ' ';
			visited[i] = 2;
		}

	cout << endl;
}

void Graph::undirectedComponents ( ) const
{
	visited = new int[vertices];

	for ( int i = 0 ; i < vertices ; i++ )
		visited[i] = 0;

	for ( i = 0 ; i < vertices ; i++ )
		if ( visited[i] == 0 )
		{
			DFS ( i );
			displayVisited ( );
		}

	delete [ ] visited;
	visited = 0;
		
}

void Graph::BFS ( ) const
{
	visited = new int[vertices];

	for ( int i = 0 ; i < vertices ; i++ )
		visited[i] = 0;

	queue<int> q;

	q.push ( 0 );
	visited[0] = 1;
	
	while ( !q.empty ( ) )
	{
		int i = q.front ( );
		cout << i << ' ';
		q.pop ( );

		for ( int j = 0 ; j < vertices ; j++ )
			if ( visited[j] == 0 && matrix ( i , j ) )
			{
				q.push ( j );
				visited[j] = 1;
			}
	}

	delete [] visited;
	visited = 0;
}

Graph::~Graph ( )
{
	if ( m )
	{
		delete []m;
		m = 0;
	}
}

void Graph::insertEdge ( int i , int j , int weight )
{
	matrix ( i , j ) = weight;
}

void Graph::removeEdge ( int i , int j )
{
	matrix ( i , j ) = 0;
}

int Graph::isValidIndex ( int index ) const
{
	return ( index >= 0 && index < vertices );
}

int & Graph::matrix ( int i , int j ) 
{
	if ( !isValidIndex ( i ) || !isValidIndex ( j ) )
		throw InvalidIndex ( "Invalid index passed" );

	return m[ i * vertices + j ];
}

int Graph::matrix ( int i , int j ) const
{
	if ( !isValidIndex ( i ) || !isValidIndex ( j ) )
		throw InvalidIndex ( "Invalid index passed" );

	return m[ i * vertices + j ];
}