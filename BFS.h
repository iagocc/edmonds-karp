//
//  BFS.h
//  EdmondsKarp
//
//  Created by Iago Chaves on 14/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#ifndef __EdmondsKarp__BFS__
#define __EdmondsKarp__BFS__

#include <iostream>
#include <queue>
#include "Graph.h"

class BFS {
	map<Vertex*, Vertex*> *parent;
	std::queue<Vertex*> *queue;
	Graph *g;
	Vertex *s;
	Vertex *t;
	map<Edge*, int> *cf;
public:
	BFS(Graph *g, Vertex *s, Vertex *t, map<Edge*, int> *cf);
	map<Vertex*, Vertex*>* search();
	bool hasPath();
};

#endif /* defined(__EdmondsKarp__BFS__) */
