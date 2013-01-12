//
//  EdmondsKarp.cpp
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#include "EdmondsKarp.h"
#include "BFS.h"

EdmondsKarp::EdmondsKarp(Graph *g, Vertex *s, Vertex* t) {
	
	this->g = g;
	flow = new map<Edge*, int>();
	cr = new map<Edge*, int>();
	
	map<Vertex*, vector<Edge*>*>::iterator it;
	vector<Edge*>::iterator it2;
	
	// Instanciar os fluxos e capacidades residuais
	for(it = g->getEdges()->begin(); it != g->getEdges()->end(); it++) {
		for(it2 = it->second->begin(); it2 < it->second->end(); it2++) {
			flow->insert( pair<Edge*, int>( (*it2), 0 ) );
			cr->insert( pair<Edge*, int>( (*it2), (*it2)->getCapacity() ) );
		}
	}
	
	// Construir rede residual
	gr = g->clone();

	// Busca em largula para checar se há caminho
	BFS *bfs = new BFS(gr, s, t, cr);
	// Retorna lista de predecessores
	map<Vertex*, Vertex*> *parentOf = bfs->search();

	while(bfs->hasPath()) {

		// Crio uma lista que contém todas as capacidades do caminho, e uma lista que contem todas as arestas do caminho
		vector<int> *listOfCap = new vector<int>;
		vector<Edge*> *listOfEdges = new vector<Edge*>();
		Vertex *aux = t;
		
		while((*parentOf)[aux] != NULL) {
			listOfCap->push_back( cr->find(gr->findEdge((*parentOf)[aux], aux))->second );
			listOfEdges->push_back(gr->findEdge((*parentOf)[aux], aux));
			aux = (*parentOf)[aux];
		}
		
		int minCap = *min_element(listOfCap->begin(), listOfCap->end());
		
		vector<Edge*>::iterator it;
		for(it = listOfEdges->begin(); it < listOfEdges->end(); it++) {
			
			// Adicionar o valor ao fluxo no sentido direto
			(*flow)[*it] += minCap;
			
			// Realizar o cálculo da capacidade residual no sentido direto
			(*cr)[*it] = (*it)->getCapacity() - (*flow)[*it];
			
			
			// Checar se já existe aresta contrária
			Edge *inv = gr->findEdge( (*it)->getDestination(), (*it)->getSource() );
			if(inv == NULL) {
				// Se não existe cria e insere-a no fluxo residual
				inv = new Edge((*it)->getDestination(), (*it)->getSource(), 0);
				gr->addArc(inv);
				cr->insert( pair<Edge*, int>(inv, 0) );
			}
			// CapacidadeResidual(u,v) = Fluxo(v,u) - Capacidade(u,v)
			//(*cr)[inv] = (*flow)[*it] - inv->getCapacity();
			// CapacidadeResidual(u,v) = Capacidade(u,v) + Fluxo(v,u) 
			(*cr)[inv] = inv->getCapacity() + (*flow)[*it];
		}
		
		// Recalcular o gráfico residual
		bfs = new BFS(gr, s, t, cr);
		parentOf = bfs->search();
		
	}
	
	// { DEBUG }
	map<Edge*, int>::iterator k;
	for(k = flow->begin(); k != flow->end(); k++) {
		cout << "F: ("
			 << k->first->getSource()->getVertex()
			 << " > "
			 << k->first->getDestination()->getVertex()
			 << ")["
			 << k->second << "/"
			 << k->first->getCapacity()
			 << "]" <<
			 endl;
	}
	
}