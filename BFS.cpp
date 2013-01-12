//
//  BFS.cpp
//  EdmondsKarp
//
//  Created by Iago Chaves on 14/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#include "BFS.h"

BFS::BFS(Graph *g, Vertex *s, Vertex *t, map<Edge*, int> *cf) {
	this->parent = new map<Vertex*, Vertex*>();
	this->queue = new std::queue<Vertex*>();
	
	this->g = g;
	this->s = s;
	this->t = t;
	this->cf = cf;
	
}

map<Vertex*, Vertex*>* BFS::search() {
	
	vector<Vertex*> *vertices = g->getVertices();
	vector<Vertex*>::iterator iv;
	
	map<Vertex*, string> *color = new map<Vertex*, string>();
	for(iv = vertices->begin(); iv < vertices->end(); iv++) {
		color->insert( pair<Vertex*, string>(*iv, "white") );
		parent->insert( pair<Vertex*, Vertex*>(*iv, NULL) );
	}
	
	(*color)[s] = "gray";
	queue->push(s);
	
	while(!queue->empty()) {
		
		Vertex *u = queue->front();
		queue->pop();
		
		vector<Edge*> *adj = g->adjacentsOf(u);
		vector<Edge*>::iterator it;
		
		for(it = adj->begin(); it < adj->end(); it++) {
			Vertex *v = (*it)->getDestination();
			
			if( (*color)[v] == "white" && cf->find( g->findEdge(u, v) )->second > 0 ) {
				(*color)[v] = "gray";
				(*parent)[v] = u;
				queue->push(v);
			}
		}
		(*color)[u] = "black";

	}
	
	return parent;
}

bool BFS::hasPath() {
	if( (*parent)[t] != NULL ) {
		return true;
	}
	return false;
}