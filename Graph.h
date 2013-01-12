//
//  Graph.h
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#ifndef __EdmondsKarp__Graph__
#define __EdmondsKarp__Graph__

#include <iostream>
#include <map>
#include <vector>
#include "Edge.h"

class Graph {
	map<Vertex*, vector<Edge*>*> *edges;
	vector<Vertex*> *vertices;
	unsigned int n;
public:
	Graph(int n, vector<Vertex*>	*vertices);
	int								getN();
	map<Vertex*, vector<Edge*>*>	*getEdges();
	vector<Vertex*>					*getVertices();
	void							insertVertex(Vertex *v);
	void							addArc(Edge* e);
	Edge							*findEdge(Vertex* s, Vertex* d);
	vector<Edge*>					*adjacentsOf(Vertex *v);
	Graph							*clone();
	void							printGraph();
};

#endif /* defined(__EdmondsKarp__Graph__) */
