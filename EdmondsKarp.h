//
//  EdmondsKarp.h
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#ifndef __EdmondsKarp__EdmondsKarp__
#define __EdmondsKarp__EdmondsKarp__

#include <iostream>
#include <algorithm>
#include "Graph.h"

class EdmondsKarp {
	map<Edge*, int> *flow;
	map<Edge*, int> *cr;
	Graph *g;
	Graph *gr;
public:
	EdmondsKarp(Graph *g, Vertex *s, Vertex* t);
};

#endif /* defined(__EdmondsKarp__EdmondsKarp__) */
