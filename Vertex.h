//
//  Vertex.h
//  EdmondsKarp
//
//  Created by Iago Chaves on 13/09/12.
//  Copyright (c) 2012 Iago Chaves. All rights reserved.
//

#ifndef __EdmondsKarp__Vertex__
#define __EdmondsKarp__Vertex__

#include <iostream>

using namespace std;

class Vertex {
	int vertex;
public:
	Vertex(int v);
	int getVertex();
	Vertex* clone();
	bool equals(Vertex *o);
};

#endif /* defined(__EdmondsKarp__Vertex__) */
