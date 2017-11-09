#include "Graph.h"

void main ( )
{
	Graph g ( 6 );
	g.insertEdge ( 0 , 1 );
	g.insertEdge ( 0 , 2  );

	g.insertEdge ( 1 , 0 );
	g.insertEdge ( 2 , 0 );

	g.insertEdge ( 2 , 3 );
	g.insertEdge ( 3 , 2 );

	g.insertEdge ( 1 , 3 );
	g.insertEdge ( 3 , 1 );

	g.insertEdge ( 4 , 5 );
	g.insertEdge ( 5 , 4 );

	g.insertEdge ( 3 , 2 );

	g.undirectedComponents ( );
}