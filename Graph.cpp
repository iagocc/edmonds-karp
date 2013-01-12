//
//  Graph.cpp
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#include "Graph.h"

Graph::Graph(int n, vector<Vertex*> *vertices) {
	edges = new map<Vertex*, vector<Edge*>*>();
	this->vertices = vertices;
	this->n = n;
	
	// Cria e insere os vertices na lista de adjacencias
	vector<Vertex*>::iterator it;
	for(it = vertices->begin(); it < vertices->end(); it++) {
		vector<Edge*> *list = new vector<Edge*>();
		edges->insert( pair<Vertex*, vector<Edge*>*>(*it, list) );
	}
}

map<Vertex*, vector<Edge*>*> * Graph::getEdges() {
	return edges;
}

vector<Vertex*> * Graph::getVertices() {
	return vertices;
}

void Graph::insertVertex(Vertex *v) {
	vertices->push_back(v);
	vector<Edge*> *list = new vector<Edge*>();
	edges->insert( pair<Vertex*, vector<Edge*>*>(v, list) );
}

int Graph::getN() {
	return n;
}

void Graph::addArc(Edge* e) {
	// Cria uma lista de ponteiro para Edge e pega o vertice fonte
	vector<Edge*>* list;
	Vertex *v = e->getSource();
	
	// Se o vertice não está na lista de adjacencia, insere-o
	if(edges->find(v) == edges->end()) {
		insertVertex(v);
	}
	
	list = edges->find(v)->second;
	
	// Insere o Edge no local correto
	list->push_back(e);
}

Edge* Graph::findEdge(Vertex* s, Vertex* d) {
	Edge *aux = new Edge(s, d, 0);
	Edge *e = NULL;
	vector<Edge*>::iterator it;
	
	for(it = edges->find(s)->second->begin(); it < edges->find(s)->second->end(); it++) {
		
		if(aux->equalsWithoutCapacity(*it)) {
			e = *it;
		}
		
	}

	return e;
}

vector<Edge*> * Graph::adjacentsOf(Vertex *v) {
	return (edges->find(v)->second);
}

Graph * Graph::clone() {
	map<Vertex*, vector<Edge*>*>::iterator it;
	vector<Edge*>::iterator it2;
	
	Graph *clone = new Graph(n, vertices);
	
	for(it = edges->begin(); it != edges->end(); it++) {
		for(it2 = it->second->begin(); it2 < it->second->end(); it2++) {
			
			Edge* eClone = (*it2)->clone();
			
			clone->addArc(eClone);
			
		}
	}
	
	return clone;
}

void Graph::printGraph() {
	map<Vertex*, vector<Edge*>*>::iterator it;
	vector<Edge*>::iterator it2;
	
	for(it = edges->begin(); it != edges->end(); it++) {
		for(it2 = it->second->begin(); it2 < it->second->end(); it2++) {
			cout <<
				"#edge (" <<
				(*it2)->getSource()->getVertex() <<
				"," <<
				(*it2)->getDestination()->getVertex() <<
				")[" <<
				(*it2)->getCapacity() <<
				"] " << endl;
		}
	}
}