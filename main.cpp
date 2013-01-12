//
//  main.cpp
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "EdmondsKarp.h"
#include <fstream>
#include <sstream>

int main(int argc, const char * argv[])
{
	Graph *g;
	vector<Vertex*> *vertices = new vector<Vertex*>();
	ifstream file;
	bool config = false;
	int n;
	Vertex *s, *t;
	string param;
	string params[6];
	int j = 0;
	
	// Arquivo que contém o grafo
	file.open("input.txt");
	
	if(file.is_open()) {
		string line;
		
		while(file.good()) {
			getline(file, line);
			stringstream linestream(line);
			
			if(!config) {
				
				// Separa os parametos. Valores separados por vírgulas
				while(getline(linestream, param, ',')) {
					params[j] = param;
					j++;
				}
				
				// Configurando os dados iniciais
				n = atoi(params[0].c_str());
				
				for(int i = 0; i < n; i++) {
					vertices->push_back(new Vertex(i));
				}
				
				s = vertices->at(atoi(params[1].c_str()));
				t = vertices->at(atoi(params[2].c_str()));
				
				config = true;
				g = new Graph(n, vertices);
				
			} else {
				
				// Separa os parametos. Valores separados por vírgulas
				int j = 0;
				while(getline(linestream, param, ',')) {
					params[j] = param;
					j++;
				}
				
				int s, d, c;
				s = (int) atoi(params[0].c_str());
				d = (int) atoi(params[1].c_str());
				c = (int) atoi(params[2].c_str());
				
				Edge *e = new Edge(vertices->at(s), vertices->at(d), c);
				g->addArc(e);
				
			}
		}
	} else {
		cout << "Error to open the input Graph. ( input.txt )." << endl;
		return 0;
	}
	
	file.close();
	
	g->printGraph();
	
	EdmondsKarp *ek = new EdmondsKarp(g, s, t);
	delete ek;
}
