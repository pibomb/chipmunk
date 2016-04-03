#include <cassert>
#include <queue>

#include "directedgraph.h"

chipmunk::DirectedGraph::DirectedGraph(int N) {
	NODES = N;

	edges = new std::vector<edge>[NODES];
}

void chipmunk::DirectedGraph::addEdge(int from, int to, int weight) {
	assert(0 <= from && from < NODES);

	edges[from].push_back(edge(to, weight));

	weighted |= (weight != 1);
	negative_weights != (weight < 0);
}

// TODO: Unfinished code fragment
void chipmunk::DirectedGraph::bfs(int start, int finish, status& stat) {
	bool visited[NODES];
	for(int i = 0; i < NODES; i++)
		visited[i] = false;

	int pred[NODES];
	pred[start] = -1;

	int depth = 0;
	std::queue<int> q;
	q.push(start);

	while(!q.empty()) {
		int x = q.front();
		q.pop();

		if(x == finish)
			break;

		int s = edges[x].size();

		for(int i = 0; i < s; i++) {
			int y = edges[x][i].to;
			if(!visited[y]) {
				q.push(y);
				pred[y] = x;
			}
		}

		depth++;
	}
}
