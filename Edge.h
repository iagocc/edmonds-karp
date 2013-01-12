//
//  Edge.h
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#ifndef __EdmondsKarp__Edge__
#define __EdmondsKarp__Edge__

#include <iostream>
#include "Vertex.h"

class Edge {
	Vertex *source;
	Vertex *destination;
	int capacity;
public:
	Edge(Vertex *s, Vertex* d, int c);
	Vertex *getSource();
	Vertex *getDestination();
	int getCapacity();
	Edge *clone();
	bool equals(Edge *o);
	bool equalsWithoutCapacity(Edge *o);
};

#endif /* defined(__EdmondsKarp__Edge__) */
