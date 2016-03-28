#include <vector>

namespace chipmunk {
	// Class for a directed graph
	class DirectedGraph {
	// Struct for an edge
	struct edge {
		int to, weight;
		edge(int t, int w) : to(t), weight(w) {}
	};

	int NODES = 0; // Number of nodes

	std::vector<edge>* edges; // Edges of the graph

	bool weighted = false; // True if edges are weighted
	bool negative_weights = false; // True if there are negative weights

	public:
		// Directed Graph constructor
		DirectedGraph(int N);
		// Adds ab edge to the graph
		void addEdge(int from, int to, int weight = 1);

	private:
		struct status {
			bool negative_cycle = false;
			int length;
			std::vector<int> path;
		};
		void bfs(int start, int finish, status& stat);
		void dijkstra(int start, int finish, status& stat);
		void bellman_ford(int start, int finish, status& stat);
	};
}
