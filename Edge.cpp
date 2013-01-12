//
//  Edge.cpp
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#include "Edge.h"

Edge::Edge(Vertex *s, Vertex* d, int c) {
	source = s;
	destination = d;
	capacity = c;
}

Vertex * Edge::getSource() {
	return source;
}

Vertex * Edge::getDestination() {
	return destination;
}

int Edge::getCapacity() {
	return capacity;
}

Edge * Edge::clone() {
	// Preisa deixar o vertices com o mesmo endereco da memória
	//Vertex* s = source;
	//Vertex* d = destination;
	
	//Edge *clone = new Edge(s, d, capacity);
	//return clone;
	return this;
}

bool Edge::equals(Edge *o) {
	if( source->equals(o->getSource()) && destination->equals(o->getDestination()) && capacity == o->getCapacity() ) {
		return true;
	}
	return false;
}

bool Edge::equalsWithoutCapacity(Edge *o) {
	if( source->equals(o->getSource()) && destination->equals(o->getDestination()) ) {
		return true;
	}
	return false;
}