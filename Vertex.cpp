//
//  Vertex.cpp
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#include "Vertex.h"

/* Contructor
 * @var int v: Name of vertex
 */
Vertex::Vertex(int v) {
	vertex = v;
}

/* getVertex
 * @return: Name of vertex
 */
int Vertex::getVertex() {
	return vertex;
}

/* getVertex
 * @return: Clone of Vertex
 */
Vertex* Vertex::clone() {
	Vertex *clone = new Vertex(vertex);
	return clone;
}

/* getVertex
 * @var Vertex *o: Other vertex
 * @return: True if this vertex equals the vertex o
 */
bool Vertex::equals(Vertex *o) {
	if(vertex == o->getVertex()) {
		return true;
	}
	return false;
}